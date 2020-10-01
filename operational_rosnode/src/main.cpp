#include <Arduino.h>
#include "header.h"



void target_callback(const PID::IntArr_ &msg)
{
  desired_ticks = msg.data.ticks;
  desired_cycles = msg.data.cycles;
}


void emergency_break_callback(const std_msgs::Bool &msg)
{
  emergency_break = msg.data;
}

void setup()
{
  nh.initNode();
  nh.advertise(pub_reality);

  nh.subscribe(sub_target);
  nh.subscribe(sub_emergency_break);
}

void loop()
{
  
}