// OBJECTIVE: Given the wheel speeds and directions, move the robot from a present to desired location (seen in rviz)
// This is a subscriber that finds the wheel speeds and directions from the moveInstructionsTopic updated by MoveController.cpp
// To update rviz visualization it also publishes to a visual topic


#include <ros/ros.h>

int main(int argc, char **argv)
{
  // Initialize ROS
  ros::init(argc, argv, "points_and_lines");
  ros::NodeHandle n;

  // Initialize publisher to send messages to visulization_marker topic
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);
  ros::Rate loop_rate(30);

  // Make a cube to represent robot in rviz
  Cube cube(0, 0, 0);

  // Set messages (locations) from moveInstructionsTopic to x coord of cube
  ros::Subscriber moveSub = n.subscribe("moveInstructionsTopic", 1000, &Cube::set_pos_x, &cube);
	
  uint32_t shape = visualization_msgs::Marker::CUBE;
  while(ros::ok()){
    // Publish cube to visualization topic
    marker_pub.publish((visualization_msgs::Marker)cube);

    // Process callbacks and wait
    ros::spinOnce();
    loop_rate.sleep();
  } // end while
} // end main