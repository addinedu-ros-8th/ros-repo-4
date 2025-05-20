import RPi.GPIO as GPIO
import time

#us sensor
TRIG = 23
ECHO = 24

#buzzer
BUZZER = 22

#ir 로봇이 보는방향 기준 오른쪽에서 왼쪽으로 1,2,3
IR_1 = 16
IR_2 = 20
IR_3 = 21

#motor
AIN1 = 17
AIN2 = 27
PWMA = 18
BIN1 = 5
BIN2 = 6
PWMB = 13
STBY = 25


class Pinky:
    def __init__(self):
        GPIO.setmode(GPIO.BCM)
        
        try:
            #us sensor
            GPIO.setup(TRIG, GPIO.OUT)
            GPIO.setup(ECHO, GPIO.IN)

            #buzzer
            GPIO.setup(BUZZER, GPIO.OUT)

            #ir
            GPIO.setup(IR_1, GPIO.IN)
            GPIO.setup(IR_2, GPIO.IN)
            GPIO.setup(IR_3, GPIO.IN)

            #motor
            GPIO.setup(AIN1, GPIO.OUT)
            GPIO.setup(AIN2, GPIO.OUT)
            GPIO.setup(PWMA, GPIO.OUT)
            GPIO.setup(BIN1, GPIO.OUT)
            GPIO.setup(BIN2, GPIO.OUT)
            GPIO.setup(PWMB, GPIO.OUT)
            GPIO.setup(STBY, GPIO.OUT)

        except Exception as e:
            raise RuntimeError("현재 GPIO가 사용중 입니다. 사용 중인 커널을 종료 후 다시 실행해 주세요")

        self.min_speed = 20
        self.ratio = 1.0

    def set_ratio(self, ratio):
        self.ratio = float(ratio)

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
    
    def buzzer_start(self):
        try:
            self.pwm = GPIO.PWM(BUZZER, 1000)
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

    def read_ir(self):
        ir_1 = GPIO.input(IR_1)
        ir_2 = GPIO.input(IR_2)
        ir_3 = GPIO.input(IR_3)

        return ir_1, ir_2, ir_3
    
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

    def set_min_speed(self, speed):
        self.min_speed = speed

    def move_front(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else: 
            GPIO.output(AIN1, GPIO.HIGH)
            GPIO.output(AIN2, GPIO.LOW)
            self.pwm_L.ChangeDutyCycle(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:    
            GPIO.output(BIN1, GPIO.HIGH)
            GPIO.output(BIN2, GPIO.LOW)
            self.pwm_R.ChangeDutyCycle(R)

    def move_back(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else: 
            GPIO.output(AIN1, GPIO.LOW)
            GPIO.output(AIN2, GPIO.HIGH)
            self.pwm_L.ChangeDutyCycle(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:    
            GPIO.output(BIN1, GPIO.LOW)
            GPIO.output(BIN2, GPIO.HIGH)
            self.pwm_R.ChangeDutyCycle(R)

    def turn_right(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else: 
            GPIO.output(AIN1, GPIO.HIGH)
            GPIO.output(AIN2, GPIO.LOW)
            self.pwm_L.ChangeDutyCycle(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:    
            GPIO.output(BIN1, GPIO.LOW)
            GPIO.output(BIN2, GPIO.HIGH)
            self.pwm_R.ChangeDutyCycle(R)

    def turn_left(self, L, R):
        if L < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else: 
            GPIO.output(AIN1, GPIO.LOW)
            GPIO.output(AIN2, GPIO.HIGH)
            self.pwm_L.ChangeDutyCycle(L)

        if R < self.min_speed:
            raise ValueError(f"Set the speed higher than min_speed ({self.min_speed})")
        else:    
            GPIO.output(BIN1, GPIO.HIGH)
            GPIO.output(BIN2, GPIO.LOW)
            self.pwm_R.ChangeDutyCycle(R)
    
    def move(self, L, R):
        if L < 0:
            GPIO.output(AIN1, GPIO.LOW)
            GPIO.output(AIN2, GPIO.HIGH)
        else: 
            GPIO.output(AIN1, GPIO.HIGH)
            GPIO.output(AIN2, GPIO.LOW)
        
        self.pwm_L.ChangeDutyCycle(abs(L * self.ratio))

        if R < 0:
            GPIO.output(BIN1, GPIO.LOW)
            GPIO.output(BIN2, GPIO.HIGH)
        else:    
            GPIO.output(BIN1, GPIO.HIGH)
            GPIO.output(BIN2, GPIO.LOW)
        
        self.pwm_R.ChangeDutyCycle(abs(R))

    def stop(self):
        GPIO.output(AIN1, GPIO.LOW)
        GPIO.output(AIN2, GPIO.LOW)
        self.pwm_L.ChangeDutyCycle(0)

        GPIO.output(BIN1, GPIO.LOW)
        GPIO.output(BIN2, GPIO.LOW)
        self.pwm_R.ChangeDutyCycle(0)
    
    def clean(self, pins=None): 
        if pins is None:
            GPIO.cleanup()
        else:
            GPIO.cleanup(pins)