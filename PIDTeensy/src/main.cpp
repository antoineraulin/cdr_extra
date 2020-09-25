#include <TimerOne.h>
#include <Arduino.h>
#include "header.h"

void setup(void)
{
  Timer1.initialize(period); //initialisation du timer
  Timer1.attachInterrupt(Cycle); //attachInterrupt
  Serial.begin(bauderate);
}

void Cycle()
{
  cli(); //éteint les interrupts
  tick++;
  Serial.println(tick);
  sei(); //relance les interrupts
}

void loop(void)
{
  delay(100);
}