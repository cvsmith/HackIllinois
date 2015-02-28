#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

int durationLin = 48;
int durationRad = 24;
char operation = ' ';
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotorL = AFMS.getStepper(48,  1);
Adafruit_StepperMotor *myMotorR = AFMS.getStepper(48, 2);

void setup() {
  Serial.begin(9600);
  AFMS.begin(); 
  myMotorL->setSpeed(60);
  myMotorR->setSpeed(60);
}

void loop()   
{
  if (Serial.available())
  {
    operation = Serial.read(); 
    switch(operation)
    {
      case '0':
        forward();
        break;
      case '1':
        backward();
        break;
      case '2':
        left();
        break;
      case '3':
        right();
        break; 
    }
    //Serial.write(0);
  }
  //else Serial.write(1);   
   
}  

void forward()
{
   for(int i = 0; i < durationLin; i++)
   {
     myMotorL->step(1, FORWARD, DOUBLE); 
     myMotorR->step(1, BACKWARD, DOUBLE);
   }  
}  

void backward()
{
   for(int i = 0; i < durationLin; i++)
   {
     myMotorL->step(1, BACKWARD, DOUBLE); 
     myMotorR->step(1, FORWARD, DOUBLE);
   }  
}  

void left()
{
   for(int i = 0; i < durationRad; i++)
   {
     myMotorL->step(1, BACKWARD, DOUBLE); 
     myMotorR->step(1, BACKWARD, DOUBLE);
   }  
}  

void right()
{
   for(int i = 0; i < durationRad; i++)
   {
     myMotorL->step(1, FORWARD, DOUBLE); 
     myMotorR->step(1, FORWARD, DOUBLE);
   }  
}  
