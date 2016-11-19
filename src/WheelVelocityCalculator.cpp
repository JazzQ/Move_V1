// Don't know what libraries to include and exact syntax yet, but here is some sudo code

// FUNCTIONS:
	// WheelVelocityCalculator
	// WheelSpeedCalculator
	// WheelDirectionCalculator

import math
using namespace std;

// OBJECTIVE: Given the overall velocity we want the robot to have, find the velocity needed for a wheel
void WheelVelocityCalculator(vector desiredRobotVelocity, float desiredRobotW, vector wheelPosition, vector* wheelVelocityPtr, vector* wheelObjectiveVelocityPtr){
	// Find the wheelVelocity in the direction of the turning wheel
	float wheelVelocity[2];
	wheelVelocity[0] = -1*desiredRobotW*wheelPosition[1]; // V_rx = -w*r_y
	wheelVelocity[1] = desiredRobotW*wheelPosition[0]; // V_ry = w*r_x

	// Find the wheelObjectiveVelocity in the direction the turning wheel is advancing
	float wheelObjectiveVelocity[2];
	wheelObjectiveVelocity[0] = desiredRobotVelocity[0] + wheelVelocity[0]; // V_wx = Vx + V_rx
	wheelObjectiveVelocity[1] = desiredRobotVelocity[1] + wheelVelocity[1]; // V_wy = Vy + V_ry

	// Assign returned pointers
	wheelVelocityPtr -> wheelVelocity;
	wheelObjectiveVelocityPtr -> wheelObjectiveVelocity;
} // end WheelVelocityCalculator

// OBJECTIVE: Calculate the speed of a wheel when it spins given its velocity
float WheelSpeedCalculator(vector wheelVelocity){
	wheelSpeed = sqrt(wheelVelocity[0]^2 + wheelVelocity[1]^2); // s = |V|
	
	return wheelSpeed;
} // end WheelSpeedCalculator

// OBJECTIVE: Calculate the direction (1 or -1) of a wheel when it spins given its velocity
int WheelDirectionCalculator(vector wheelVelocity){
	float wheelSpeed = WheelSpeedCalculator(wheelVelocity);
	vector wheelDirection = WheelVelocity/wheelSpeed; 
	// wheelDirection is direction of wheel according to robot coord frame
	// Want to simplify to get direction = 1 for spin clockwise (right) or -1 for spin counter-clockwise (left)
	// Can we do this usin cross product with wheelPosition vector (should be perpendicular to wheelDirection then sign should tell us left or right)?
	
	int direction;
	//...
	
	return direction;
} // end WheelDirectionCalculator