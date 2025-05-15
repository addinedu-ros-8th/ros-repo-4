string robot_id
uint8 main_status
uint8 motion_status
float32 battery

# main_status constants
uint8 IDLE=0
uint8 WORKING=1
unit8 DEACTIVATE=2

# motion_status
uint8 MOVING=0
uint8 FOLLOWING=1
uint8 STOP=2
uint8 LOADING=3