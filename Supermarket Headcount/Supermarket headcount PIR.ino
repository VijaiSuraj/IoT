#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pir_IN = 8;
int pir_OUT = 13;

int in_signal = 0;
int out_signal = 0;

int n = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.print("HEAD COUNT");
  pinMode(pir_IN,INPUT);
  pinMode(pir_OUT,INPUT);
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(n);
  in_signal = digitalRead(pir_IN);
  out_signal = digitalRead(pir_OUT);
  if(in_signal == HIGH){
    n = n+1;
    delay(2000);//assuming a person takes 2 seconds to get past the range of the sensor
    in_signal=0;
  }
  if(out_signal == HIGH){
    if(n != 0){
    	n = n-1;
        delay(2000);//assuming a person takes 2 seconds to get past the range of the sensor
    }
    out_signal=0;
  }
}
 