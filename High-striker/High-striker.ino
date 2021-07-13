// C++ code
//
const int l1 = 8;
const int l2 = 10;
const int l3 = 11;
const int l4 = 12;
const int l5 = 13;

const int buzz = 9;

float fsrReading = 0;      //reading from FSR
//float forceReading = 0;    //force in Newton (N)

void setup()
{
  Serial.begin(9600);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
  
  pinMode(buzz, OUTPUT);
  
  pinMode(A0, OUTPUT);
}

void loop()
{
  fsrReading = analogRead(A0);
  //forceReading = fsrReading / 3.9 ; 
  
  Serial.println(fsrReading);
  if(fsrReading>=0 && fsrReading <7.8 ){
    digitalWrite(l1,HIGH);
  } else if(fsrReading>=7.8 && fsrReading <15.6 ){
    digitalWrite(l1,HIGH);
    digitalWrite(l2,HIGH);
  }else if(fsrReading>=15.6 && fsrReading <23.4 ){
    digitalWrite(l1,HIGH);
    digitalWrite(l2,HIGH);
    digitalWrite(l3,HIGH);
  }else if(fsrReading>=23.4 && fsrReading <31.2 ){
    digitalWrite(l1,HIGH);
    digitalWrite(l2,HIGH);
    digitalWrite(l3,HIGH);
    digitalWrite(l4,HIGH);
  }else if(fsrReading>=31.2 && fsrReading <39.0 ){
    digitalWrite(l1,HIGH);
    digitalWrite(l2,HIGH);
    digitalWrite(l3,HIGH);
    digitalWrite(l4,HIGH);
    digitalWrite(l5,HIGH);
  }else if(fsrReading>=39.0){
    tone(buzz, 1000); 
    digitalWrite(l1,HIGH);
    delay(500);
    noTone(buzz);
    digitalWrite(l2,HIGH);
    digitalWrite(l1,LOW);
    delay(500);
    noTone(buzz);
    digitalWrite(l3,HIGH);
    digitalWrite(l2,LOW);
    delay(500);
    noTone(buzz);
    digitalWrite(l4,HIGH);
    digitalWrite(l3,LOW);
    delay(500);
    noTone(buzz);
    digitalWrite(l5,HIGH);
    digitalWrite(l4,LOW);
    delay(500);
    noTone(buzz);
    digitalWrite(l5,LOW);
   }
}