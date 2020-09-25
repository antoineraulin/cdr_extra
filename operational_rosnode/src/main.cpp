#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Bool.h>

#define TOPIC_ENCODER_RIGHT_TICKS "/speedRight/cb"
#define TOPIC_ENCODER_LEFT_TICKS "/speedLeft/cb"
#define TOPIC_ENCODER_RIGHT_CYCLE "/speedRight/cycle"
#define TOPIC_ENCODER_LEFT_CYCLE "/speedLeft/cycle"
#define TOPIC_MOTOR_RIGHT "/speedRight"
#define TOPIC_MOTOR_LEFT "/speedLeft"
#define TOPIC_EMERGENCY_BREAK "/breakServo"

ros::NodeHandle nh;

int right_desired_speed = 0;
int left_desired_speed = 0;
bool emergency_break = false;

std_msgs::Int16 right_speed;
ros::Publisher encoder_right(TOPIC_ENCODER_RIGHT_TICKS, &right_speed);

std_msgs::Int16 left_speed;
ros::Publisher encoder_left(TOPIC_ENCODER_LEFT_TICKS, &left_speed);

std_msgs::Int8 right_cycle;
ros::Publisher encoder_right_cycle(TOPIC_ENCODER_RIGHT_CYCLE, &right_cycle);

std_msgs::Int8 left_cycle;
ros::Publisher encoder_left_cycle(TOPIC_ENCODER_LEFT_CYCLE, &left_cycle);

void right_desired_speed_callback(const std_msgs::Int16 &msg)
{
  right_desired_speed = msg.data;
}

void left_desired_speed_callback(const std_msgs::Int16 &msg)
{
  left_desired_speed = msg.data;
}

void emergency_break_callback(const std_msgs::Bool &msg)
{
  emergency_break = msg.data;
}

ros::Subscriber<std_msgs::Int16> sub_left(TOPIC_MOTOR_LEFT, &left_desired_speed_callback);

ros::Subscriber<std_msgs::Int16> sub_right(TOPIC_MOTOR_RIGHT, &right_desired_speed_callback);

ros::Subscriber<std_msgs::Bool> sub_emergency_break(TOPIC_EMERGENCY_BREAK, &emergency_break_callback);

void setup()
{
  nh.initNode();
  nh.advertise(encoder_right);
  nh.advertise(encoder_left);

  nh.advertise(encoder_right_cycle);
  nh.advertise(encoder_left_cycle);
  nh.subscribe(sub_left);
  nh.subscribe(sub_right);
  nh.subscribe(sub_emergency_break);
}

void loop()
{
}