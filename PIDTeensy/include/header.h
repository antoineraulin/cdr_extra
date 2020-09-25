#include <stdint.h>

//CYCLE
void Cycle();
const int period = 100000; //10 Hz ; 1 000 000 microseconds = 1 second

//ros comm
volatile int target_ticks=0;//target number of ticks per cycle
volatile int target_duration=0;//number of cycles to run
volatile bool emergency_break=false;//boolean for emergeancy break

//PID - variables
volatile int tick = 0; //encoder ticks
int e;//error
int olde=0;//old error
int E=0;//integrated error or cumulated error
int de;//derived error or error variation
const int kp=10;//proportional wheight
const int ki=10;//integral wheight
const int kd=1;//derivative wheight
int PID;//result of pid calc before mapping to pins
int mapped;//mapped version of pid
const int maxpid=4000;//max value of pid for mapping
const int minpid=0;//min valu of pid use for mapping

//Communication
const int bauderate = 38400;

//encoder
const int encoderpin = 8;// pin for the encoder interrupt
void encoderInterrupt();//isr for encoder

// H-bridge
const int pwmpin=10;//pin for H bridge pwm
void motorbreak();
