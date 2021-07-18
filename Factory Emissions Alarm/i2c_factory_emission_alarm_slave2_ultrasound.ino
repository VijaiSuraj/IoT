// C++ code
//

# include <Wire.h>

int p = 0;
int distance;
long duration;
const int trigPin = 10;
const int echoPin = 9;

void setup()
{
  Serial.begin(9600);
  Wire.begin(2);                  //join i2c bus with address 2
  Wire.onRequest(requestEvent);  //register event
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop()
{
  delay(100);
}

void requestEvent() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  Serial.println(distance);
  p = distance;
  Wire.write(p);
  //Serial.println(p);
}