#ifndef L298n_h
#define L298n_h
#include "Arduino.h"

class L298n {
    public:
        class Direction{
            public:
                bool FORWARD = true;
                bool BACKWARD = false;
		        bool LEFT = true;
		        bool RIGHT = false;

                void invert();
        };
        class Motor{
            private:
                int en;
                int in1;
                int in2;

            public:
                Direction dir;
                Motor(int enable, int in_1, int in_2, bool invert=false);
                void begin();
                void drive(bool direction, int speed);
                void stop();
        };
        class Driver{
            private:
                int enA;
                int enB;
                int in1;
                int in2;
                int in3;
                int in4;

            public:
                Direction dirGlo;
                Direction dirA;
                Direction dirB;

                Driver(int en_a, int en_b, int in_1, int in_2, int in_3, int in_4, bool invertA=false, bool invertB=false);
                void begin();
                void drive(bool dir_a, int speed);
                void driveA(bool direction, int speed);
                void driveB(bool direction, int speed);
                void stop();
                void stopA();
                void stopB();
        };
};

#endif
