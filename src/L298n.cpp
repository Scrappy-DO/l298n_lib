#include "Arduino.h"
#include "L298n.h"

// direction
void L298n::Direction::invert(){
    FORWARD = !FORWARD;
    BACKWARD = !BACKWARD;
    LEFT = !LEFT;
    RIGHT = !RIGHT;
}

// Motor class
L298n::Motor::Motor(int enable, int in_1, int in_2, bool invert/*=false*/){
    en = enable;
    in1 = in_1;
    in2 = in_2;
    if (invert){
        dir.invert();
    }
}

L298n::Motor::Motor(){}

void L298n::Motor::setPins(int enable, int in_1, int in_2){
    en = enable;
    in1 = in_1;
    in2 = in_2;
}

void L298n::Motor::invert(){
    dir.invert();
}

void L298n::Motor::begin(){
    pinMode(en, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
}

void L298n::Motor::drive(bool direction, int speed){
    if (direction){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else{
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }

    analogWrite(en, speed);
}

void L298n::Motor::stop(){
    analogWrite(en, 0);
}

// Driver class
L298n::Driver::Driver(int en_a, int en_b, int in_1, int in_2, int in_3, int in_4, bool invertA/*=false*/, bool invertB/*=false*/){
    enA = en_a;
    enB = en_b;
    in1 = in_1;
    in2 = in_2;
    in3 = in_3;
    in4 = in_4;

    if (invertA){
        dirA.invert();
    }
    if (invertB){
        dirB.invert();
    }
}

L298n::Driver::Driver(){}

void L298n::Driver::setPins(int en_a, int en_b, int in_1, int in_2, int in_3, int in_4){
    enA = en_a;
    enB = en_b;
    in1 = in_1;
    in2 = in_2;
    in3 = in_3;
    in4 = in_4;
}

void L298n::Driver::invertA(){
    dirA.invert();
}

void L298n::Driver::invertB(){
    dirB.invert();
}

void L298n::Driver::begin(){
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void L298n::Driver::drive(bool direction, int speed){
    if (direction == dirA.FORWARD){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    }
    else{
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }

    if (direction == dirB.FORWARD){
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }
    else{
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }

    analogWrite(enA, speed);
    analogWrite(enB, speed);
}

void L298n::Driver::driveA(bool direction, int speed){
    if (direction){
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else{
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }

    analogWrite(enA, speed);
}

void L298n::Driver::driveB(bool direction, int speed){
    if (direction){
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    } else{
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }

    analogWrite(enB, speed);
}

void L298n::Driver::stop(){
    analogWrite(enA, 0);
    analogWrite(enB, 0);
}

void L298n::Driver::stopA(){
    analogWrite(enA, 0);
}

void L298n::Driver::stopB(){
    analogWrite(enB, 0);
}
