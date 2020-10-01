#include "TimerOne.h"
#include <Arduino.h>
#include "header.h"

void setup(void)
{
  //TIMER initialization
  Timer1.initialize(period); //initialisation du timer
  Timer1.attachInterrupt(Cycle); //attachInterrupt
  //encoder initialisation
  attachInterrupt(encoderpin,encoderInterrupt,RISING);
  //setting up pwm precision
  analogWriteFrequency(pwmpin,F_CPU/1E6);//setting up ideal frequency pedending on cpu frequency
  analogWriteResolution(10); // 0 - 255
  //ros here pls
  Serial.begin(bauderate);//comm non ros
}

void loop(void)
{
  delay(1000);
  Serial.println("------- 1 sec is over -------");
  Serial.send_now();
}

void Cycle()
{
  cli(); //éteint les interrupts
  if(emergency_break){
    motorbreak();
  }else if(target_duration>0){
    //calculate error and pid
    e = target_ticks - tick;
    E = E+e;
    de = e-olde;
    PID = (kp*e)+(ki*E)+(kd*de);
    mapped = map(PID,minpid,maxpid,0,1023);
    analogWrite(pwmpin,mapped);
    //reset
    olde = e;
    tick = 0;
    target_duration--;
    //for debug
    Serial.print(e);
    Serial.print(" ");
    Serial.println(PID);
    Serial.send_now();
  }
  sei(); //relance les interrupts
}

void encoderInterrupt(){
  tick++;
}

void motorbreak(){

}