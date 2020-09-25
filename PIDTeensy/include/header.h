#include <stdint.h>

//CYCLE
void Cycle();
const int period = 100000; //10 Hz 1 000 000 microseconds = 1 second

//PID - variables
volatile int tick = 0; //encoder ticks

//Communication
const int bauderate = 9600;


//encoder
const int encoderpin = 8;// pin for the encoder interrupt
void encoderInterrupt();//isr for encoder