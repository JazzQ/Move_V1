// OBJECTIVE: Given the present and desired location for the robot, determine what speeds and directions for each wheel are necessary to get to the desired location
// This is a publisher that publishes to the topic moveInstructionsTopic which tells MoveInitiator.cpp what to do to move the robot
// It subscribes to locationsTopic to get present and desired locations 

#include "ros/ros.h"
#include "std_msgs/Int8.h"

int main(int argc, char **argv){
  // Initialize ROS
  ros::init(argc, argv, "int8_publisher");
  ros::NodeHandle n;

  // Initialize publisher to send messages to moveInstructionsTopic
  ros::Publisher movePub = n.advertise<move_v1::moveMessages>("moveInstructionsTopic", 1000);
  ros::Rate loop_rate(10);

  int count = 0, dir = 1;
  while(ros::ok()){
    // Create a message
    move_v1::moveMessages speedMsg;
    speedMsg.speed_0 = 1 * dir;

    // Publish the message to moveInstructionsTopic
    printf("Sending value: %d\n", count);
    movePub.publish(speedMsg);

    // Process callbacks then wait
    ros::spinOnce();
    loop_rate.sleep();
	
    //Reset count every 20 iterations
    if(count >= 10){
      count = 0;
      dir *= -1;
    } // end if
    else{
    	count++;
    } // end else
      

  } // end while

  return 0;
} // end main
