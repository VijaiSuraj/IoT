// C++ code
//

#include <Wire.h>
 
int g =0;

void setup()
{
  Serial.begin(9600);
  Wire.begin(1);                  //join i2c bus with address 1
  Wire.onRequest(requestEvent);  //register event
  pinMode(A0,OUTPUT);
}

void loop()
{
  delay(100);
}

void requestEvent() {
  g = analogRead(A0);
  Wire.write(g);
  //Serial.println(g);
}