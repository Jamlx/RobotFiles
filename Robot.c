#include "Robot.h"
#include "Servo.h"
#include "MotorHat.h"
#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include <assert.h>

int left_id = 1;
int right_id = 2;

robot robotInit(robot r1, unsigned int address, int left_id, int right_id, int left_trim, int right_trim){

	r1.addr = address;
	r1.mLeft = getMotor(left_id);
	r1.mRight = getMotor(right_id);
	r1.left_trim = left_trim;
	r1.right_trim = right_trim;
	
	run(RELEASE,r1.mLeft);
	run(RELEASE,r1.mRight);
	
}

void robotInit2(robot r1, int left_trim, int right_trim)
{

	dcInit();
	init1(0x60);	
	r1.addr = 0x60;
	r1.mLeft = getMotor(1);
	r1.mRight = getMotor(2);
	r1.left_trim = left_trim;
	r1.right_trim = right_trim;
	
	r1.mLeft = getMotor(left_id);
	r1.mRight = getMotor(right_id);

	
	run(RELEASE, r1.mLeft);
	run(RELEASE, r1.mRight);
}

int maxXmin(int speed)
{
	int num = MIN(255, speed); 
	if (0>num){ 
		speed = 0;
	} 
	else{
	speed = num;
	}
	return speed;


}

void leftSpeed(int speed, robot r1){

	assert(0 <= speed <= 255);
	speed += r1.left_trim;
	speed = maxXmin(speed);
	r1.mLeft = getMotor(left_id);
	setSpeed(speed, r1.mLeft);
}

void rightSpeed(int speed, robot r1){

	assert(0 <= speed <= 255);
	speed += r1.right_trim;
	speed = maxXmin(speed);
	r1.mRight = getMotor(right_id);
	setSpeed(speed, r1.mRight);
}

void stop(robot r1){
	
	r1.mLeft = getMotor(left_id);
        r1.mRight = getMotor(right_id);

	run(RELEASE, r1.mLeft);
	run(RELEASE, r1.mRight);
}

void forward(int speed, int seconds, robot r1)
{

	leftSpeed(speed, r1);
	rightSpeed(speed, r1);
	r1.mLeft = getMotor(left_id);
        r1.mRight = getMotor(right_id);
	run(FORWARD, r1.mLeft);
	run(FORWARD, r1.mRight);
	if (seconds > 0)
	{
		bcm2835_delay(seconds);
		stop(r1);
	}
}

void backward(int speed, int seconds, robot r1)
{

        leftSpeed(speed, r1);
        rightSpeed(speed, r1);
	r1.mLeft = getMotor(left_id);
        r1.mRight = getMotor(right_id);
	run(BACKWARD, r1.mLeft);
        run(BACKWARD, r1.mRight);
        if (seconds > 0)
        {
                bcm2835_delay(seconds);
		stop(r1);
        }

}

void right(int speed, int seconds, robot r1)
{

        leftSpeed(speed, r1);
        rightSpeed(speed, r1);
	r1.mLeft = getMotor(left_id);
        r1.mRight = getMotor(right_id);
	run(FORWARD, r1.mLeft);
        run(BACKWARD, r1.mRight);
        if (seconds > 0)
        {
                bcm2835_delay(seconds);
		stop(r1);
        }

}

void left(int speed, int seconds, robot r1)
{
	leftSpeed(speed, r1);
        rightSpeed(speed, r1);      
	r1.mLeft = getMotor(left_id);
        r1.mRight = getMotor(right_id);
        run(BACKWARD, r1.mLeft);
        run(FORWARD, r1.mRight);
        if (seconds > 0)
        {
                bcm2835_delay(seconds);
		stop(r1);
        }

}
