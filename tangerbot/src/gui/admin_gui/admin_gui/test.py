import socket
import struct
import numpy as np
import cv2

HEADER_FORMAT = "<BBBxIHHI"
HEADER_SIZE = struct.calcsize(HEADER_FORMAT)

buffers = {}
meta = {}

UDP_IP = "0.0.0.0"
UDP_PORT = 14555

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))
print(f"Listening on UDP {UDP_IP}:{UDP_PORT}")

while True:
    data, addr = sock.recvfrom(14555)
    if len(data) < HEADER_SIZE:
        continue

    header = data[:HEADER_SIZE]
    magic, robot_id, camera_id, frame_id, total_chunks, chunk_id, chunk_size = struct.unpack(HEADER_FORMAT, header)

    print(f"[패킷] robot:{robot_id}, cam:{camera_id}, frame:{frame_id}, total_chunks:{total_chunks}, chunk_id:{chunk_id}, chunk_size:{chunk_size}")

    if magic != 0xAA:
        continue

    if chunk_id >= total_chunks:
        print(f"[경고] chunk_id {chunk_id} >= total_chunks {total_chunks}, 무시")
        continue

    chunk_data = data[HEADER_SIZE:HEADER_SIZE + chunk_size]
    key = (robot_id, frame_id)

    if key not in buffers:
        buffers[key] = [None] * total_chunks
        meta[key] = [0, total_chunks]

    if buffers[key][chunk_id] is None:
        buffers[key][chunk_id] = chunk_data
        meta[key][0] += 1

    if meta[key][0] == total_chunks:
        full_data = b''.join(buffers[key])
        del buffers[key]
        del meta[key]

        nparr = np.frombuffer(full_data, np.uint8)
        frame = cv2.imdecode(nparr, cv2.IMREAD_COLOR)

        if frame is None:
            print(f"[에러] 디코딩 실패: robot {robot_id} cam {camera_id}")
            continue

        cv2.imshow(f"Robot {robot_id} Cam {camera_id}", frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

cv2.destroyAllWindows()
sock.close()
