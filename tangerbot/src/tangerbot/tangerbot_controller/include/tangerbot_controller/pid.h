#ifndef PID_H
#define PID_H

class PID {
public:
    PID();
    PID(double kp, double ki, double kd);

    void set_gains(double kp, double ki, double kd);
    void set_dt(double dt);
    void reset();
    double compute(double setpoint, double measurement);
private:
    double kp;
    double ki;
    double kd;

    double dt;
    double prev_error;
    double integral;
};

#endif 