#include <ros.h>
#include <std_msgs/Bool.h>
#include "IntArr.h"
#include "config.h"

//ros global
ros::NodeHandle nh;

// emergency break
const string TOPIC_EMERGENCY_BREAK = "/breakServo"; //topic name
void emergency_break_callback(const std_msgs::Bool &msg); 
bool emergency_break = false;
ros::Subscriber<std_msgs::Bool> sub_emergency_break(TOPIC_EMERGENCY_BREAK, &emergency_break_callback);

// speed target
int desired_ticks = 0;
int desired_cycles = 0;
PID::IntArr_ target;
void target_callback(const PID::IntArr_ &msg);
ros::Subscriber<PID::IntArr_> sub_target(TOPIC_TARGET, &target_callback);


// speed reality
PID::IntArr_ reality;
ros::Publisher pub_reality(TOPIC_REALITY, &reality);