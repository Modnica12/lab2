#include <Servo.h>
#include "keys.h"

const byte rowAmount = 4;
const byte colAmount = 4;

const int rotateStep =1;

Servo panServo;
int panPosition = 0;
Servo tiltServo;
int tiltPosition = 0;


void setup() {
    
  // put your setup code here, to run once:
  panServo.attach(8);
  tiltServo.attach(7);
  changePositions();

  Serial1.begin(115200);
  Serial.begin(115200);
}

void loop() 
{
  // put your main code here, to run repeatedly:  
  char key;
    
  while (Serial1.available()) 
  {
    changePositions();
    key = Serial1.read();
  
    //  Serial.println(key);
    if (key == keyUp)
    {
      if (panPosition + rotateStep <= 180)
        {
          panPosition += rotateStep;
          delay(10);
        }
    }

    if (key == keyDown)
    {
      if (panPosition - rotateStep >= 0)
      { 
          panPosition -= rotateStep;
          delay(10);
      }
    }

    if (key == keyRight)
    {
      if (tiltPosition + rotateStep <= 180)
        {
          tiltPosition += rotateStep;
          delay(10);
        }
    }
     

    if (key == keyLeft)
    {
      if (tiltPosition - rotateStep >= 0)
        {
          tiltPosition -= rotateStep;
          delay(10);
        } 
    }
  }
}

void changePositions(){
    panServo.write(panPosition);
    tiltServo.write(tiltPosition);
    //Serial.print("moving to: ");Serial.print(panPosition);Serial.print(" ");Serial.println(tiltPosition);
}
