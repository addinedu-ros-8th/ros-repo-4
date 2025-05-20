import RPi.GPIO as GPIO
import time

#us sensor
TRIG = 23
ECHO = 24

class Ultrasonic:
    def __init__(self):
        GPIO.setmode(GPIO.BCM)
        
        try:
            #us sensor
            GPIO.setup(TRIG, GPIO.OUT)
            GPIO.setup(ECHO, GPIO.IN)

        except Exception as e:
            raise RuntimeError("현재 초음파 GPIO가 사용중 입니다. 사용 중인 커널을 종료 후 다시 실행해 주세요")

    def get_dist(self):
        GPIO.output(TRIG, True)
        time.sleep(0.00001)
        GPIO.output(TRIG, False)

        while GPIO.input(ECHO) == 0:
            pulse_start = time.time()

        while GPIO.input(ECHO) == 1:
            pulse_end = time.time()

        pulse_duration = pulse_end - pulse_start
        
        distance = pulse_duration * 34300 / 2
        
        return distance #cm

    def clean(self): 
        GPIO.cleanup([TRIG, ECHO])