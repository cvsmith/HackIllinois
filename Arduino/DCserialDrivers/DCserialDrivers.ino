#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

int durationLin = 48;
int durationRad = 24;
char operation = ' ';
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotorL = AFMS.getMotor(3);
Adafruit_DCMotor *myMotorR = AFMS.getMotor(4);

void setup() {
  Serial.begin(9600);
  AFMS.begin(); 
  myMotorL->setSpeed(30);
  myMotorR->setSpeed(30);
  myMotorR->run(FORWARD);
  myMotorR->run(RELEASE);
  myMotorL->run(FORWARD);
  myMotorL->run(RELEASE);
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
   myMotorL->run(FORWARD);
   myMotorR->run(BACKWARD);
   delay(2000);
   myMotorL->run(RELEASE);
   myMotorR->run(RELEASE);
   
}  

void backward()
{
   myMotorL->run(BACKWARD);
   myMotorR->run(FORWARD);
   delay(2000);
   myMotorL->run(RELEASE);
   myMotorR->run(RELEASE);  
}  

void left()
{
   myMotorL->run(BACKWARD);
   myMotorR->run(BACKWARD);
   delay(1500);
   myMotorL->run(RELEASE);
   myMotorR->run(RELEASE);
}  

void right()
{
   myMotorL->run(FORWARD);
   myMotorR->run(FORWARD);
   delay(1500);
   myMotorL->run(RELEASE);
   myMotorR->run(RELEASE); 
}  
