# 4조 감귤 운송 로봇 Tangerbot
![감귤](https://github.com/user-attachments/assets/ccdd0c76-c434-4141-a030-a1e6e089a2d6)

### 우리는
> 1. 고령화로 인한 노동력 부족의 문제를 해결
> 2. 생산성 향상 및 작업 효율을 개선
> 3. 스마트 농업 기술을 확산 시켜 제주 특산물을 지키고자함

## Contents (목차)

## 0. Result of Project (프로젝트 결과)

> 영상

## 1. Team Members (팀원 소개)

### 김가은 (팀장)

### 박세린

### 박정배

### 이명운

### 이태민
- ROS2 패키지 구조 및 통신 시퀀스 설계
- User GUI 구현
- ArUco Marker 기반 로봇 위치 추정
- 로봇 경로 생성 알고리즘 개발
- 자율주행 및 장애물 회피 알고리즘 개발

## 2. Project Plan (프로젝트 기획)

### 2.1 Plan and Issue (Jira)
![Jira](https://github.com/user-attachments/assets/2ed8ae8e-8770-4ab0-94ef-ab26764443b9)

### 2.2 Confluence (협업)
![Confluence](https://github.com/user-attachments/assets/ffab525f-e6df-4ad6-b81f-3371e87f2c32)

### 2.3 Scenario
![scenario_board](https://github.com/user-attachments/assets/b1e50b05-a9de-48c0-bb91-14508f1a5a9c)

## 3. Design (프로젝트 설계)

### 3.1 System Architecture
![system_architecture](https://github.com/user-attachments/assets/da5bca95-9f68-460e-91a0-4e0dd0d9560d)

### 3.2 Squence Diagram
- 음성 호출
![sequence_call](https://github.com/user-attachments/assets/7859bc7f-64c3-4da0-8604-2ec7697727c9)

### 3.3 State Machine
![state](https://github.com/user-attachments/assets/1cd2ae49-3606-4718-9f48-bb339fc3ae8f)

### 3.5 ERD
![ERD](https://github.com/user-attachments/assets/50acd00d-e98b-4029-88e7-f2d84c3a5cc8)

### 3.6 Map / Tangerbot
![Map](https://github.com/user-attachments/assets/1049c7b0-264a-47c9-b896-b1ec26e05e5c)

![map](https://github.com/user-attachments/assets/6e93e409-f53c-438e-9a61-bde728797573)



## 4. Tech Stack (기술 스택)

| Category | Technology    |
| :---: | --- |
| Development environment | **ROS2 (jazzy)**, Ubuntu 24.04, Python venv, Docker |
| Language | **C++**, Python, SQL |
| Framework | **Nav2**, Qt, OpenCV, YOLO, MediaPipe, Pytorch |
| Network | TCP/IP, UDP/IP |
| Configuration Management | Github, Jira, Confluence |


## 5. Fetures (기능)

### 5.1 User Features

#### 5.1.1 Signup / Login (회원가입 / 로그인)
![signup](https://github.com/user-attachments/assets/e2dc78f1-9837-419d-aed7-94c58ad466a6)

- User는 회원가입을 먼저 진행해야하며 형식에 맞게 회원 정보를 작성하고 회원가입을 한다.
- Tangerbot Server는 DB에서 User 정보를 확인하고 User가 존재하지 않으면 DB에 추가한다.
- 회원가입을 완료한 User는 로그인을 할 수 있으며, 메인 화면에서 오늘의 목표 작업량 및 현재 작업량을 확인할 수 있다.

#### 5.1.2 Robot Call (로봇 호출)
![call](https://github.com/user-attachments/assets/d1872773-1b64-4a70-9be3-228fe284a9b1)

- User는 Call 버튼을 누르고 로봇을 호출하고 싶은 섹션을 선택할 수 있다.
- 원하는 섹션을 선택 후 호출하면 User GUI는 HandleCommand Service를 Tangerbot Server에 요청한다.
- 호출 가능한 로봇이 존재하면 Tangerbot Server는 CallState Topic으로 로봇의 도착 시간을 초 단위로 전달받아 확인 가능하다.
- 로봇이 도착하면 로봇 상태 페이지로 전환된다.

#### 5.1.3 Robot Control (로봇 제어)
![control](https://github.com/user-attachments/assets/8c06c83b-0e6e-4dc6-ba66-fbe8379251b5)

- User는 배정된 로봇의 배터리 상태를 확인할 수 있다. 이때 배터리 상태는 Tangerbot의 RobotState Topic을 통해 전달된다. 
- User는 Follow 버튼을 클릭해 Toggle 방식으로 팔로우 모드를 제어할 수 있다. 팔로우 모드의 제어 명령은 Tangerbot Server에 HandleCommand 서비스 요청으로 전달된다.
- User는 로봇 사용을 마친 후 Return 버튼을 클릭하여 로봇을 복귀시킬 수 있다.

### 5.2 Tangerbot Features

#### 5.2.1 Autonomous Driving (자율주행)
- 로봇은 FollowPath Action을 Tangerbot Server로 부터 생성된 경로와 함께 요청 받으면 RPP (Requlated Pure Pursuit) controller로 경로를 추종한다. 

#### 5.2.2 Following Person (팔로윙)
![follow](https://github.com/user-attachments/assets/a9ae7767-855b-483c-8dc2-768244064c30)

- User로부터 팔로윙 요청을 받은 Tangerbot Server는 SetFollowMode Service를 Vision Server에 요청한다.
- Vision Server는 로봇으로부터 전송받는 영상을 분석해 사람의 상대 좌표를 Tangerbot Server에게 PersonPose 전송한다.
- Tangerbot Server는 전달받은 PersonPose를 PID 제어를 통해 Twist 토픽으로 로봇을 제어해 사람을 따라다님

#### 5.2.3 Avoiding Obstacle
[![obstacle](https://img.youtube.com/vi/deswGHgMtCY/0.jpg)](https://youtube.com/shorts/deswGHgMtCY)
- Tangerbot Server는 주행 중 Vision Server로부터 ObstacleBool Topic을 통해 로봇의 장애물 감지 유무를 확인할 수 있다.
- 장애물이 감지되면 Tangerbot Server는 FollowPath Action을 취소하고 장애물이 감지되지 않을 때까지 후진 회피한다.
- 이후 경로를 재생성해 다시 로봇에게 FollowPath Action을 요청한다.

#### 5.2.4 Parking
[![Parking](https://img.youtube.com/vi/deswGHgMtCY/0.jpg)](https://youtube.com/shorts/deswGHgMtCY)
- 홈 위치에 도착한 로봇은 FollowPath Action Result를 Tangerbot Server에 전송한다.
- Tangerbot Server는 로봇에게 Parking Action을 통해 특정 홈에 맞는 marker_id와 함께 요청한다.
- 로봇은 마커와의 상대적인 좌표를 계산하여 스스로 주차할 수 있다.

#### 5.2.5 Speech Recognition (음성 인식)
[![speech](https://img.youtube.com/vi/deswGHgMtCY/0.jpg)](https://youtube.com/shorts/deswGHgMtCY)
- 로봇은 Wake Word (핑키야)를 통해 음성 인식을 시작하며, 2초간 음성이 인식되지 않으면 Talker Server에 RawVoice Topic으로 음성 데이터를 전송한다.
- 음성 데이터를 받은 Talker 서버는 STT를 적용하여 Tangerbot Server로 전달한다.
- 다시 Tangerbot Server는 변환된 텍스트를 분석해 명령을 판단한다.

#### 5.2.6 Gesture Recognition (손동작 인식)
- User는 손동작 (손바닥: 팔로윙, 주먹: 멈춤)을 통해 로봇의 팔로윙 모드를 제어할 수 있다.
- Vision Server는 Tangerbot의 영상 데이터에 MediaPipe를 적용시켜 반환된 keypoints를 Tangerbot Server에게 전달한다.
- Tangerbot Server 전달받은 Keypoints를 분석해 명령을 판단한다.

### 5.3 Admin Features

#### 5.3.1 Robot Monitoring
![admin](https://github.com/user-attachments/assets/d2c263fa-8448-44af-b7ad-afdbc969671a)
- Admin은 메인 화면에서 로봇의 상태(위치, 작업, 배터리)와 실시간 영상, 작업량을 확인할 수 있다.

#### 5.3.2 Statistical Report
![adminsta](https://github.com/user-attachments/assets/c36ea4e8-50e9-4dae-9ec8-fff0c107bd81)
- Admin은 감귤 수확량의 통계를 확인할 수 있다.

## 6. Adapted Technology (적용 기술)

### 6.1 Pose Estimation (로봇 자세 추정)
![pose](https://github.com/user-attachments/assets/2342cbf5-10c1-49d7-9c79-15f3754126c0)

#### 6.1.1 Camera Pose Estimation
- Map -> Base Marker TF를 발행하여 기준 마커를 둔다.
- Camera에 대한 Base Marker rvec, tvec을 역변환하여 Base Marker에 대한 Camera의 위치를 추정한다. 수식은 다음과 같다.   
![marker_to_camera](https://github.com/user-attachments/assets/aa00505b-df03-48ab-bd60-8edcf267282a)
- 이전에 발행한 TF를 기반으로 Map -> Camera 위치를 추정한다.   
![map_to_camera](https://github.com/user-attachments/assets/86f5c216-914d-47fb-9daf-c4b75b0a4995)
- Camera 위치가 바뀌거나 흔들리는 변수를 위해 코드를 통해 자동화

#### 6.1.2 Robot Pose Estimation
- Map -> Camera TF와 Camera에 대한 Robot Marker의 rvec, tvec을 통해 Map -> Robot의 위치를 추정한다.   
![map_to_robot](https://github.com/user-attachments/assets/e6d5f635-587c-4bae-a8c4-a8ea3dd50a63)

#### 6.1.3 Trouble Shooting
- Camera의 Marker 인식 과정에서 왜곡 및 인식 불안정으로인한 로봇의 **위치 떨림** 현상을 발견했다.
- Camera에 대한 로봇의 tvec과 Yaw 값을 **Low-pass filtering**을 이용하여 안정화시켰으며, Alpha 값 0.98로 설정했을 때 90% 정도 떨림이 없어진다.
- 하지만 위치를 찾는 시간이 오래 걸려 0.7~0.8로 설정
- 로봇 흔들림의 감소로 안정적인 Costmap을 생성할 수 있었고, 더욱 안정적인 경로를 생성할 수 있었다.

### 6.2 Path Planning / Driving

#### 6.2.1 A* Algorithm
- 기존 A* 알고리즘은 출발노드-현재노드의 거리 + 현재노드-타겟노드의 거리를 Cost로 설정하여 최단 경로를 생성하는 알고리즘이다.

#### 6.2.2 OpenCV DistanceTransform
- OpenCV를 사용하여 맵상의 장애물과의 거리를 기반으로한 Distmap을 생성했다.

#### 6.2.3 Hybrid Path Planning
- 기존 A* 알고리즘에서 사용하는 휴리스틱 거리 측정값에 Distmap을 이용한 장애물과의 거리 비용으로 감쇠시켜 **최단 거리 + 안전 경로**를 생성한다.

![path](https://github.com/user-attachments/assets/20958294-5218-46fa-8a55-f2f1c156983d)

#### 6.2.4 Driving Controller
- Path Planning을 통해 Path를 생성하고, NavigateToPose Behavior Tree (BT)를 사용하지 않고, FollowPath Action을 직접 호출함으로써 사전에 생성된 경로를 로봇이 강제로 추종하게한다.
- RPP (Regulated Pure Pursuit)는 로컬 장애물 회피는 수행하지 않지만, 지정된 경로에 대한 안정적인 추종 성능을 제공하며, 곡선 주행 및 선회에 있어서 자연스러운 속도 조절이 가능하다.

#### 6.2.5 Obstacle Avoiding
- 후진 회피 수행
- 로컬 경로 주행 중 로봇 전방에 설정한 ROI (전방 30도, 15cm) 내에 장애물이 탐지될 경우 후진 동작 후 경로를 재탐색하여 장애물 회피 경로 생성
- 이때 장애물 탐지는 Costmap의 장애물이 아닌 SLAM 센서 기반의 실시간 인식 결과를 사용하여 정확한 반응을 유도한다.

#### 6.2.6 Performance & Trouble Shooting
- 기존 Nav2의 SmacPlanner + NavigateToPose BT 사용시 성공률 약 30% 수준이었다.
- Tangerbot의 Distmap Hybrid A* + FollowPath과 회피 알고리즘 적용 결과 성공률 약 80% 달성했다.
- Camera 기반 위치 추정은 Camera 왜곡 및 Marker 흔들림으로 로봇 위치 및 Costmap의 노이즈가 발생한다.
- 이는 후진 직후 1초간의 안정화 시간(Delay)으로 안정성 확보가 가능하다.

### 6.3 Shared Memory

#### 6.3.1 Streaming Requirements
- Tangerbot은 3개의 노드 (follower, human_pose, gesture)가 동일 영상 접근이 필요하다.
- 로봇3대 * 카메라3개 = 총 9개의 영상 스트림 처리해야한다.
- 실시간 처리 가능해야한다.



