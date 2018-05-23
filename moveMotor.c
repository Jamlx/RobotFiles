
#include <bcm2835.h>
#include "MotorHat.h"
#include "Servo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>       //to use floor


motor motors[4];


void dcInit(motor m1, int num)
{    
	if(num == 0){
     	         m1.pwm = 8;
		 m1.in2 = 9;
                 m1.in1 = 10;
        }else if (num == 1){
                 m1.pwm = 13;
                 m1.in2 = 12;
                 m1.in1 = 11;
        }else if (num == 2){
                 m1.pwm = 2;
                 m1.in2 = 3;
                 m1.in1 = 4;
        }else if (num == 3){
                 m1.pwm = 7;
                 m1.in2 = 6;
                 m1.in1 = 5;
        }else{
          perror("MotorHAT Motor must be between 1 and 4 inclusive");
	}
	motors[num] = m1;
        m1.PWMpin = m1.pwm;
        m1.IN1pin = m1.in1;
        m1.IN2pin = m1.in2;
}
void run(int command, motor m1){
        /*
	printf("%d",m1.id);
	if (m1.id !=1){
            perror("ERROR");
	}
	*/
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
}
void setSpeed(int speed, motor m1){
        if (speed < 0){
            speed = 0;
	}
        if (speed > 255){
            speed = 255;
       	    setPWM(m1.PWMpin, 0, speed*16);
	}
}
        
void hatInit(int addr, int freq)
{
	int _freqency  = freq;
	int i;
        for (i = 0; i < 4; i++)
	{
		dcInit(list[i], i);
	}
        setPWMFreq(freq);
}
  
void setPin(int pin,int value)
{
        if (pin < 0 || pin > 15)
	{
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
}
motor getMotor(int num){
        if (num < 1 || num > 4){
        	perror("MototHAT Motor must be between 1 and 4 inclusive");
	}
	return motors[num-1];
}
