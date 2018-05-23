
#include <bcm2835.h>
#include "MotorHat.h"
#include "Servo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//^^^ INCLUDES ^^^

motor motors[4];
//Define array of motors

void dcInit(motor m1, int num)
{
	list[0].pwm = 8;
	list[0].in2 = 9;
	list[0].in1 = 10;
	list[1].pwm = 13;
	list[1].in2 = 12;
	list[1].in1 = 11;
	list[2].pwm = 2;
	list[2].in2 = 3;
	list[2].in1 = 4;
	list[3].pwm = 7;
	list[3].in2 = 6;
	list[3].in1 = 5;
}//initialize values in motors

void run(int command, motor m1){
  if (command == FORWARD){
  	setPin(m1.IN2pin, 0);
    setPin(m1.IN1pin, 1);
	}
  if (command == BACKWARD){
    setPin(m1.IN1pin, 0);
    setPin(m1.IN2pin, 1);
	}
  if (command == RELEASE){
    setPin(m1.IN1pin, 0);
    setPin(m1.IN2pin, 0);
	}
}//run a given command (forward, backward, or release) on a given motor

void setSpeed(int speed, motor m1){
  if (speed < 0){
    speed = 0;
	}
  if (speed > 255){
    speed = 255;
    setPWM(m1.PWMpin, 0, speed*16);
	}
}//set the speed of a given motor by adjusting the PWM

void hatInit(int addr, int freq){
	int _freqency  = freq;
	int i;
  for (i = 0; i < 4; i++){
		dcInit(list[i], i);
	}
	init1(addr);
  setPWMFreq(freq);
}//initialize motor hat and motor values

void setPin(int pin,int value){
	if (pin < 0 || pin > 15){
	  perror("PWM pin must be between 0 and 15 inclusive");
  }
	if (value != 0 && value != 1){
	    perror("Pin Value must be 0 or 1!");
	}
	if (value == 0){
    setPWM(pin, 0, 4096);
  }
	if (value == 1){
    setPWM(pin, 4096, 0);
	}
}//adjust pin # values

motor getMotor(int num){
  if (num < 1 || num > 4){
		perror("MototHAT Motor must be between 1 and 4 inclusive");
	}
	return motors[num-1];
}//get a motor from the motor array
