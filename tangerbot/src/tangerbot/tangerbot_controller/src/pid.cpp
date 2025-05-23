#include "tangerbot_controller/pid.h"

PID::PID() {
    prev_error = 0.0;
    integral = 0.0;
}

PID::PID(double kp, double ki, double kd) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    prev_error = 0.0;
    integral = 0.0;
}

void PID::set_gains(double kp, double ki, double kd) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
}

void PID::set_dt(double dt) {
    this->dt = dt;
}

void PID::reset() {
    prev_error = 0.0;
    integral = 0.0;
}

double PID::compute(double target, double current) {
    double error = target - current;
    integral += error * dt;
    double derivative = (error - prev_error) / dt;
    prev_error = error;
    return kp * error + ki * integral + kd * derivative;
}