// C++ code
//
#include <Wire.h>

int g = 0;
int p = 0;

void setup()
{
  Wire.begin();          //join i2c bus
  //Serial.begin(9600); 
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop()
{
  Wire.requestFrom(1,1);
  while(Wire.available()){
    g = Wire.read();
  }
  
  Wire.requestFrom(2,1);
  while(Wire.available()){
    p = Wire.read();
  }
   
  if(g>5 && p!=335){
    tone(12,400,300);
    digitalWrite(8,HIGH);
    delay(500);
    digitalWrite(8,LOW);
    noTone(12);
    delay(500);
  }
}