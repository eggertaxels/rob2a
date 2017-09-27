#pragma config(Sensor, dgtl5,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  rightEncoder,   sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorServoContinuousRotation, openLoop, /*reversed*/)
#pragma config(Motor,  port3,           leftMotor,     tmotorServoContinuousRotation, openLoop, reversed)
//#define BASEROTATION 490
#include "header.h"
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*----------------------------------------------------------------------------------------------------*\
|*                                      - Movement by Rotation -                                      *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses the Shaft Encoders to move forward for a certain distance.                      *|
|*  There is a two second pause at the beginning of the program.                                      *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Changing the value of 'distance' will change how far your robot will travel.                *|
|*        !! 360 is equal to one full rotation of the axel !!                                         *|
|*    3)  Whichever encoder is being used for feedback should be cleared just before it starts        *|
|*        counting by using the "SensorValue(encoder) = 0;".  This helps ensure consistancy.          *|
|*    r1/r2 = TURNCONST                                                                                            *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor   - Port 2    rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor   - Port 3    leftMotor           VEX 3-wire module     Left side motor                   *|
|*    Digital - Port 1,2  rightEncoder        VEX Quadrature enc.   Right side encoder                *|
|*    Digital - Port 3,4  leftEncoder         VEX Quadrature enc.   Left side encoder                 *|
\*-----------------------------------------------------------------------------------------------4246-*/


void reset_encoder(){
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
}
void drive_forward(){
	while(abs(SensorValue[leftEncoder]) < BASEROTATION)
  {
    //...Move Forward
    motor[rightMotor] = POWER;
    motor[leftMotor] = POWER;
  }
}
void turn(int deg,bool leftRight){
	while(abs(SensorValue[leftEncoder]) < deg*TURNCONST){
		if(leftRight){
		motor[rightMotor] = POWER;		  // Motor is stop
		motor[leftMotor]  = -POWER;
		}
		else{
				motor[rightMotor] = -POWER;		  // Motor is stop
				motor[leftMotor]  = POWER;
		}
	}
}
void stop_rob(){
	motor[rightMotor] = 0;		  // Motor is stop
	motor[leftMotor]  = 0;
	wait1Msec(500);
}



//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);                  // Wait 2000 milliseconds before continuing.

if(vexRT[Btn7U] == 1)
    {
      motor[rightMotor] = 0;		  // Motor stops
			motor[leftMotor]  = 0;
    }
 reset_encoder();
  drive_forward();
  stop_rob();
  reset_encoder();
  turn(90,true);
  stop_rob();
  reset_encoder();
  drive_forward();
  stop_rob();
  reset_encoder();
  turn(90,false);
  stop_rob();
  reset_encoder();
  drive_forward();
  stop_rob();
  reset_encoder();
  turn(90,false);
  stop_rob();
  reset_encoder();
  drive_forward();

 // motor[rightMotor] = 0;            /* Stop the motors once desired */
 // motor[leftMotor]  = 0;            /* distance has been reached.   */
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
