#include <TimerOne.h>
#include <Arduino.h>
#include "header.h"

const int led=LED_BUILTIN;//used for debug
void setup(void)
{
  //TIMER initialization
  pinMode(led,OUTPUT); //used for debug
  Timer1.initialize(period); //initialisation du timer
  Timer1.attachInterrupt(Cycle); //attachInterrupt
  //encoder initialisation
  attachInterrupt(encoderpin,encoderInterrupt,RISING);
  Serial.begin(bauderate);

}

void loop(void)
{
  delay(300);
  Serial.println("a delay has ended");
  delay(500);
  Serial.println("other");
  digitalWrite(led,LOW);
}

void Cycle()
{
  cli(); //éteint les interrupts
  Serial.println(tick);
  sei(); //relance les interrupts
}

void encoderInterrupt(){
  tick++;
  digitalWrite(led,HIGH);
}