from smbus2 import SMBus
from time import sleep

# MPU6500 레지스터와 주소
PWR_MGMT_1   = 0x6B
SMPLRT_DIV   = 0x19
CONFIG       = 0x1A
GYRO_CONFIG  = 0x1B
INT_ENABLE   = 0x38
ACCEL_XOUT_H = 0x3B
ACCEL_YOUT_H = 0x3D
ACCEL_ZOUT_H = 0x3F
GYRO_XOUT_H  = 0x43
GYRO_YOUT_H  = 0x45
GYRO_ZOUT_H  = 0x47

class IMU:
    def __init__(self, bus_num=1, device_address=0x68):
        self.bus = SMBus(bus_num)
        self.device_address = device_address
        self.init_device()

    def init_device(self):
        self.bus.write_byte_data(self.device_address, SMPLRT_DIV, 7)
        self.bus.write_byte_data(self.device_address, PWR_MGMT_1, 1)
        self.bus.write_byte_data(self.device_address, CONFIG, 0)
        self.bus.write_byte_data(self.device_address, GYRO_CONFIG, 24)
        self.bus.write_byte_data(self.device_address, INT_ENABLE, 1)

    def read_raw_data(self, addr):
        high = self.bus.read_byte_data(self.device_address, addr)
        low = self.bus.read_byte_data(self.device_address, addr + 1)
        
        value = (high << 8) | low
        
        if value > 32768:
            value -= 65536
        return value
        
    def get_accel(self):
        acc_x = self.read_raw_data(ACCEL_XOUT_H)
        acc_y = self.read_raw_data(ACCEL_YOUT_H)
        acc_z = self.read_raw_data(ACCEL_ZOUT_H)
        
        Ax = round(acc_x / 16384.0, 2)
        Ay = round(acc_y / 16384.0, 2)
        Az = round(acc_z / 16384.0, 2)
        
        return Ax, Ay, Az
        
    def get_gyro(self):
        gyro_x = self.read_raw_data(GYRO_XOUT_H)
        gyro_y = self.read_raw_data(GYRO_YOUT_H)
        gyro_z = self.read_raw_data(GYRO_ZOUT_H)
        
        Gx = round(gyro_x / 131.0, 2)
        Gy = round(gyro_y / 131.0, 2)
        Gz = round(gyro_z / 131.0, 2)
        
        return Gx, Gy, Gz
        

    def get_accel_gyro_data(self):
        acc_x = self.read_raw_data(ACCEL_XOUT_H)
        acc_y = self.read_raw_data(ACCEL_YOUT_H)
        acc_z = self.read_raw_data(ACCEL_ZOUT_H)
        
        gyro_x = self.read_raw_data(GYRO_XOUT_H)
        gyro_y = self.read_raw_data(GYRO_YOUT_H)
        gyro_z = self.read_raw_data(GYRO_ZOUT_H)

        Ax = acc_x / 16384.0
        Ay = acc_y / 16384.0
        Az = acc_z / 16384.0

        Gx = gyro_x / 131.0
        Gy = gyro_y / 131.0
        Gz = gyro_z / 131.0

        return {"Ax": Ax, "Ay": Ay, "Az": Az, "Gx": Gx, "Gy": Gy, "Gz": Gz}

    def close(self):
        self.bus.close()

    def __del__(self):
        self.close()
