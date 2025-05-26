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
- 원하는 섹션을 선택하고 호출 가능한 로봇이 존재하면 로봇의 도착 시간을 초 단위로 확인할 수 있다.
- 로봇이 도착하면 로봇 상태 페이지로 전환된다.

#### 5.1.3 Robot Control (로봇 제어)
![control](https://github.com/user-attachments/assets/8c06c83b-0e6e-4dc6-ba66-fbe8379251b5)

- 로봇이 배정된 User는 로봇의 배터리 상태를 확인할 수 있다.
- Follow 버튼을 On/Off 하며 팔로우 모드를 제어할 수 있다.
- 로봇 사용이 끝난 User는 Return 버튼을 클릭해 로봇을 복귀 시킬 수 있다.

### 5.2 Tangerbot Features

#### 5.2.1 Autonomous Driving (자율주행)
- 로봇은 FollowPath Action을 Tangerbot Server로 부터 생성된 경로와 함께 요청 받으면 RPP (Requlated Pure Pursuit) controller로 경로를 추종한다. 

#### 5.2.2 Following Person (팔로윙)
![follow](https://github.com/user-attachments/assets/a9ae7767-855b-483c-8dc2-768244064c30)

- User로부터 팔로윙 요청을 받은 Tangerbot Server는 SetFollowMode Service를 Vision Server에 요청한다.
- Vision Server는 로봇으로부터 전송받는 영상을 분석해 사람의 상대 좌표를 Tangerbot Server에게 PersonPose 전송한다.
- Tangerbot Server는 전달받은 PersonPose를 이용해 Twist 토픽으로 로봇을 제어해 사람을 따라다닐 수 있다.

#### 5.2.3 Avoiding Obstacle
- Tangerbot Server는 주행 중 Vision Server로부터 ObstacleBool Topic을 통해 로봇의 장애물 감지 유무를 확인할 수 있다.
- 장애물이 감지되면 Tangerbot Server는 FollowPath Action을 취소하고 장애물이 감지되지 않을 때까지 후진 회피한다.
- 이후 경로를 재생성해 다시 로봇에게 FollowPath Action을 요청한다.

#### 5.2.4 Parking
[![Parking](https://img.youtube.com/vi/deswGHgMtCY/0.jpg)](https://youtube.com/shorts/deswGHgMtCY)]
- 홈 위치에 도착한 로봇은 FollowPath Action Result를 Tangerbot Server에 전송한다.
- Tangerbot Server는 로봇에게 Parking Action을 통해 특정 홈에 맞는 marker_id와 함께 요청한다.
- 로봇은 마커와의 상대적인 좌표를 계산하여 스스로 주차할 수 있다.

## 6. Adapted Technology (적용 기술)
