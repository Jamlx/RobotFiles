#include <bcm2835.h>
#include "Robot.h"
#include "Servo.h"
#include "MotorHat.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

  int LEFT_TRIM = 0;
  int RIGHT_TRIM = 0;
  //no right or left left_trim

  robot r1;
  //define robot struct

  robotInit2(r1, LEFT_TRIM, RIGHT_TRIM);
  //initialize robot struct (r1) with no right or left trim

/** SOME RANDOM MOVEMENTS **/
  forward(150, 1.0, r1);
  left(200,0.5,r1);
  forward(150, 1.0, r1);
  left(200,0.5,r1);
  forward(150, 1.0, r1);
  right(200,0.5,r1);
  forward(150, 1.0, r1);
  right(200,0.5,r1);

  right(100,2.0, r1);
  stop(r1);

  backward(150,1.0,r1);
  right(200,0.5,r1);
  backward(150,1.0,r1);
  right(200,0.5,r1);
  backward(150,1.0,r1);
  left(200,0.5,r1);
  backward(150,1.0,r1);
  left(200,0.5,r1);
/** SOME RANDOM MOVEMENTS **/

}
