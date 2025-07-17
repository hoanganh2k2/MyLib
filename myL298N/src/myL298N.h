#ifndef MYL298N_H
#define MYL298N_H

class myL298N {
public:
    myL298N(int in1, int in2, int in3, int in4, int ena, int enb);
    void begin();
    void forward(int speed = 255);
    void backward(int speed = 255);
    void turnright(int speed = 255);
    void turnleft(int speed = 255);
    void brake();
    void stop();
    void setMotorL(bool forward, int speed = 255);
    void setMotorR(bool forward, int speed = 255);
private:
    int _in1, _in2, _in3, _in4;
    int _ena, _enb;
};

#endif
