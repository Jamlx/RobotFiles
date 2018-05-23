//This library will contain all of the header information for the robot.

#include "MotorHat.h"

#ifndef ROBOT
#define ROBOT


//By default the ID of the robot motors will be left_id = 1 and right_id = 2 and the default
//values for both trim will be set to 0 

typedef enum { false, true } bool;

typedef struct ROBOT{
	int addr;
	//int left_id;
	//int right_id;
	int left_trim;
	int right_trim;
	bool stop_at_exit;
      	motor mLeft;
	motor mRight;
}robot;


// The ID of the robot motor will be _left = 1, and _right = 2.
// By default, the value of the trims will be set to 0

robot robotInit(robot r1, unsigned int address, int left_id, int right_id, int left_trim, int right_trim);

//Create an instanceo of the robot
//Parameters:

//addr = The I2C address of the motor HAT -> default is 0x60
//left_id = The ID of the left motor -> default is 1
//right_id = The ID of the right motor -> default is 2
//left_trim = Amount of offset of the speed of the left motor -> Postive or Negative
//right_trim = Amount of offset of the speed of the right motor -> Positive or Negative
//stop_at_exit = Boolean to indciate if the motor should stop on program -> Default is set to True

void leftSpeed(int speed, robot r1); // Set the speed of the left motor

void rightSpeed(int speed, robot r1); // Set the speed of the right motor

void stop(robot r1); // stop all movement

void forward(int speed, int seconds, robot r1); // Move forward at a specified speed (0-255)

void backward(int speed, int seconds, robot r1); // Move backward at a specified speed (0-255)

void right(int speed, int seconds, robot r1); // Spin to the right at a specified speed

void left(int speed, int seconds, robot r1); // Spin to the left at a specified speed


#endif

