import RPi.GPIO as GPIO
import time

#buzzer
BUZZER = 22

class Buzzer:
    def __init__(self):
        GPIO.setmode(GPIO.BCM)
        
        try:
            #buzzer
            GPIO.setup(BUZZER, GPIO.OUT)

        except Exception as e:
            raise RuntimeError("현재 부저 GPIO가 사용중 입니다. 사용 중인 커널을 종료 후 다시 실행해 주세요")

    def buzzer_start(self, freq=1000):
        try:
            self.pwm = GPIO.PWM(BUZZER, freq)
        except:
            pass
        
        self.pwm.start(0)
    
    def set_buzzer_duty(self, duty):
        self.pwm.ChangeDutyCycle(duty)

    def set_buzzer_freq(self, freq):
        self.pwm.ChangeFrequency(freq)

    def buzzer(self, cnt=1, duration=0.5, duty=50):
        for i in range(cnt):
            self.pwm.ChangeDutyCycle(duty)
            time.sleep(duration)
            self.pwm.ChangeDutyCycle(0)
            time.sleep(duration)

    def buzzer_stop(self):
        self.pwm.stop()

    def clean(self): 
        GPIO.cleanup([BUZZER])
