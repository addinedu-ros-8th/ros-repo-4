import RPi.GPIO as GPIO
import time

#ir 로봇이 보는방향 기준 오른쪽에서 왼쪽으로 1,2,3
IR_1 = 16
IR_2 = 20
IR_3 = 21

class IR:
    def __init__(self):
        GPIO.setmode(GPIO.BCM)
        
        try:
            #ir
            GPIO.setup(IR_1, GPIO.IN)
            GPIO.setup(IR_2, GPIO.IN)
            GPIO.setup(IR_3, GPIO.IN)

        except Exception as e:
            raise RuntimeError("현재 IR센서 GPIO가 사용중 입니다. 사용 중인 커널을 종료 후 다시 실행해 주세요")

    def read_ir(self):
        ir_1 = GPIO.input(IR_1)
        ir_2 = GPIO.input(IR_2)
        ir_3 = GPIO.input(IR_3)

        return ir_1, ir_2, ir_3

    def clean(self): 
        GPIO.cleanup([IR_1, IR_2, IR_3])