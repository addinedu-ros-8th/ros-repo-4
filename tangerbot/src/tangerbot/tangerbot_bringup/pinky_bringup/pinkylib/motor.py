import RPi.GPIO as GPIO
import time

#motor
AIN1 = 17
AIN2 = 27
PWMA = 18
BIN1 = 5
BIN2 = 6
PWMB = 13
STBY = 25

class Motor:
    def __init__(self):
        GPIO.setmode(GPIO.BCM)
        
        try:
            #motor
            GPIO.setup(AIN1, GPIO.OUT)
            GPIO.setup(AIN2, GPIO.OUT)
            GPIO.setup(PWMA, GPIO.OUT)
            GPIO.setup(BIN1, GPIO.OUT)
            GPIO.setup(BIN2, GPIO.OUT)
            GPIO.setup(PWMB, GPIO.OUT)
            GPIO.setup(STBY, GPIO.OUT)

        except Exception as e:
            raise RuntimeError("현재 모터 GPIO가 사용중 입니다. 사용 중인 커널을 종료 후 다시 실행해 주세요")

        self.min_speed = 20
        self.ratio = 1.0

        self.left_motor_dir = False
        self.right_motor_dir = False

    # motor
    def enable_motor(self):
        GPIO.output(STBY, GPIO.HIGH)

    def disable_motor(self):
        GPIO.output(STBY, GPIO.LOW)

    def start_motor(self, freq=1000):
        try:
            self.pwm_L = GPIO.PWM(PWMA, freq)
            self.pwm_R = GPIO.PWM(PWMB, freq)
        except:
            pass
        
        self.pwm_L.start(0)
        self.pwm_R.start(0)
    
    def stop_motor(self):
        self.pwm_L.stop()
        self.pwm_R.stop()

    def set_ratio(self, ratio):
        self.ratio = float(ratio)

    def set_left_motor_dir(self, value):
        self.left_motor_dir = value

    def set_right_motor_dir(self, value):
        self.right_motor_dir = value

    def set_left_motor(self, L):
        if self.left_motor_dir:
            L = -L

        if L < 0:
            GPIO.output(AIN1, GPIO.LOW)
            GPIO.output(AIN2, GPIO.HIGH)
        else:
            GPIO.output(AIN1, GPIO.HIGH)
            GPIO.output(AIN2, GPIO.LOW)

        self.pwm_L.ChangeDutyCycle(min(abs(L * self.ratio), 100))

    def set_right_motor(self, R):
        if self.right_motor_dir:
            R = -R
            
        if R < 0:
            GPIO.output(BIN1, GPIO.LOW)
            GPIO.output(BIN2, GPIO.HIGH)
        else:    
            GPIO.output(BIN1, GPIO.HIGH)
            GPIO.output(BIN2, GPIO.LOW)
        
        self.pwm_R.ChangeDutyCycle(min(abs(R), 100))
    
    def move(self, L, R):
        self.set_left_motor(L)
        self.set_right_motor(R)

    def stop(self):
        GPIO.output(AIN1, GPIO.LOW)
        GPIO.output(AIN2, GPIO.LOW)
        self.pwm_L.ChangeDutyCycle(0)

        GPIO.output(BIN1, GPIO.LOW)
        GPIO.output(BIN2, GPIO.LOW)
        self.pwm_R.ChangeDutyCycle(0)

    def move_front(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else: 
            self.set_left_motor(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:    
            self.set_right_motor(R)

    def move_back(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:
            L = -L
            self.set_left_motor(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:
            R = -R   
            self.set_right_motor(R)

    def turn_right(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else: 
            self.set_left_motor(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:
            R = -R
            self.set_right_motor(R)

    def turn_left(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:
            L = -L
            self.set_left_motor(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:    
            self.set_right_motor(R)

    def clean(self): 
        GPIO.cleanup([AIN1, AIN2, PWMA, BIN1, BIN2, PWMB, STBY])