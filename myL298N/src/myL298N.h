#ifndef MYL298N_H
#define MYL298N_H

class myL298N {
public:
    myL298N(int in1, int in2, int in3, int in4);
    void begin();
    void forward();
    void backward();
    void turnright();
    void turnleft();
    void brake();
    void stop();
    void setMotorR(bool forward);
    void setMotorL(bool forward);
private:
    int _in1, _in2, _in3, _in4;
};

#endif
