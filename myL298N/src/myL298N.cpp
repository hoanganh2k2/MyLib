#include "myL298N.h"
#include <Arduino.h>

myL298N::myL298N(int in1, int in2, int in3, int in4)
    : _in1(in1), _in2(in2), _in3(in3), _in4(in4) {}

void myL298N::begin() {
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_in3, OUTPUT);
    pinMode(_in4, OUTPUT);
    stop();
}

void myL298N::setMotorL(bool forward) {
    digitalWrite(_in1, forward ? HIGH : LOW);
    digitalWrite(_in2, forward ? LOW : HIGH);
}

void myL298N::setMotorR(bool forward) {
    digitalWrite(_in3, forward ? HIGH : LOW);
    digitalWrite(_in4, forward ? LOW : HIGH);
}

void myL298N::forward() {
    setMotorL(true);
    setMotorR(true);
}

void myL298N::backward() {
    setMotorL(false);
    setMotorR(false);
}

void myL298N::turnright() {
    setMotorL(true);
    setMotorR(false);
}

void myL298N::turnleft() {
    setMotorL(false);
    setMotorR(true);
}

void myL298N::brake() {
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, HIGH);
    digitalWrite(_in3, HIGH);
    digitalWrite(_in4, HIGH);
}

void myL298N::stop() {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, LOW);
    digitalWrite(_in3, LOW);
    digitalWrite(_in4, LOW);
}
