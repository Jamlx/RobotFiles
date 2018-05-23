all:
	gcc -c Servo.c
	gcc -c Motor.c
	gcc -c Robot.c
	gcc moveServo.o moveMotor.o Robot.o Test.o -L /home/pi/bcm2835-1.55/src -lbcm2835 -lm -o TEST


clean:
	rm moveServo.o
	rm moveMotor.o
	rm Robot.o
