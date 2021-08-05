import mouse
import time
# import pyautogui


class PID:
    def __init__(self, kp, ki, kd):
        self.kp = kp
        self.ki = ki
        self.kd = kd

    def clear(self):
        self.prev_err = 0
        self.integral = 0

    def step(self, x):

        now = time.time()
        dt = now - self.last_step
        if (dt > 0.1):
            dt = 0.1

        self.last_step = now
        err = 0.0
        derivative = err - self.prev_err
        if (dt > 0.0001):
            self.integral += err * dt
            derivative /= dt

        output = self.kp * err + self.ki * self.integral + self.kd * derivative
        self.prev_err = err
        return output

    prev_err = 0.0
    integral = 0.0

    kp = 0.0
    ki = 0.0
    kd = 0.0

    last_step = 0.0


pidX = PID(3.7, 24, 0.11)
pidY = PID(3.7, 24, 0.11)
outX = pidX.step(60)
outY = pidY.step(80)

if(outX > 50):
    outX = 50
if (outX < -50):
    outX = -50

if (outY > 50):
    outY = 50
if (outY < -50):
    outY = -50

mouse.move(outX, outY)
