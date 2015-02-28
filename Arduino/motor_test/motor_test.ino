#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *myMotor = AFMS.getStepper(48, 2);
void setup() 
{ 
  myMotor->setSpeed(60);
}  
void loop()
{
  myMotor->step(100, FORWARD, DOUBLE); 
  delay(500);
}  

