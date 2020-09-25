//CYCLE
void Cycle();
const int period = 100000; //10 Hz

//PID - variables
volatile int tick = 0; //encoder ticks

//Communication
const int bauderate = 9600;
