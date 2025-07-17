#include "myL298N.h"
#include <Arduino.h>

myL298N::myL298N(int in1, int in2, int in3, int in4, int ena, int enb)
    : _in1(in1), _in2(in2), _in3(in3), _in4(in4), _ena(ena), _enb(enb) {}

void myL298N::begin() {
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_in3, OUTPUT);
    pinMode(_in4, OUTPUT);
    pinMode(_ena, OUTPUT);
    pinMode(_enb, OUTPUT);
    stop();
}

void myL298N::setMotorL(bool forward, int speed) {
    digitalWrite(_in1, forward ? HIGH : LOW);
    digitalWrite(_in2, forward ? LOW : HIGH);
    analogWrite(_ena, speed);
}

void myL298N::setMotorR(bool forward, int speed) {
    digitalWrite(_in3, forward ? HIGH : LOW);
    digitalWrite(_in4, forward ? LOW : HIGH);
    analogWrite(_enb, speed);
}

void myL298N::forward(int speed) {
    setMotorL(true, speed);
    setMotorR(true, speed);
}

void myL298N::backward(int speed) {
    setMotorL(false, speed);
    setMotorR(false, speed);
}

void myL298N::turnright(int speed) {
    setMotorL(true, speed);
    setMotorR(false, speed);
}

void myL298N::turnleft(int speed) {
    setMotorL(false, speed);
    setMotorR(true, speed);
}

void myL298N::brake() {
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, HIGH);
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, HIGH);
    analogWrite(_ena, 0);
    analogWrite(_enb, 0);
}

void myL298N::stop() {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    digitalWrite(_in3, LOW);
    digitalWrite(_in4, LOW);
    analogWrite(_ena, 0);
    analogWrite(_enb, 0);
}
