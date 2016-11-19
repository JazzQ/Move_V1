// Don't know what libraries to include and exact syntax yet, but here is some sudo code
// Also not sure these calculations are right

// FUNCTIONS:
	// FieldToRobotCoordTransform
	// RobotToFieldCoordTransform

import math
using namespace std;

// OBJECTIVE: Take vector in field reference frame and convert it to vector in robot reference frame
void FieldToRobotCoordTransform(vector fieldVector, float robotAngle, vector robotFieldPosition, vector* robotVectorPtr){
	float robotVector[2];
	robotVector[0] = fieldVector[0]*cos(robotAngle) + fieldVector[1]*sin(robotAngle) + robotFieldPosition[0]; // x' = xcos(theta) + ysin(theta) + x_offset
	robotVector[1] = -1*fieldVector[0]*sin(robotAngle) + fieldVector[1]*cos(robotAngle) + robotFieldPosition[1]; // y' = -xsin(theta) + ycos(theta) + y_offset

	robotVectorPtr -> robotVector;
} // end FieldToRobotCoordTransform

// OBJECTIVE: Take vector in robot reference frame and convert it to vector in field reference frame
void RobotToFieldCoordTransform(vector robotVector, float robotAngle, vector robotFieldPosition, vector* fieldVectorPtr){
	float fieldVector[2];
	fieldVector[0] = fieldVector[0]*cos(360 - robotAngle) + fieldVector[1]*sin(360 - robotAngle) - robotFieldPosition[0]; // x = x'cos(360 - theta) + y'sin(360 - theta) - x_offset
	fieldVector[1] = -1*fieldVector[0]*sin(360 - robotAngle) + fieldVector[1]*cos(360 - robotAngle) - robotFieldPosition[1]; // y' = -x'sin(360 - theta) + y'cos(360 - theta) - y_offset

	fieldVectorPtr -> fieldVector;
} // end RobotToFieldCoordTransform