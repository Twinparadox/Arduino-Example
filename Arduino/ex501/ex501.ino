#include <LiquidCrystal.h>
#include <MsTimer2.h>

LiquidCrystal lcd(12,11,5,4,3,2);
unsigned char count;
unsigned char secs;
unsigned char mins;
unsigned char hours;
boolean ledState=0;

void displayDigits(int digits)
{
  if(digits<10) lcd.print('0');
  lcd.print(digits);
  lcd.print(":");
}
void clock() 
{
  count++;
  if(count==100){
    count=0;
    secs++;
    ledState=!ledState;
    digitalWrite(14,ledState);
  }
  if(secs==60) {
    mins++;
    secs=0;
    if(mins==60) {
      hours++;
      mins=0;
      if(hours==24) {
        hours=0;
      }
    }
  }
}

void setup() {
  for(int i=7;i<=10;i++) {
    pinMode(i,INPUT);
  }
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);

  lcd.begin(8,2);
  lcd.setCursor(0,0);
  lcd.print("*Clock1*");
  MsTimer2::set(10,clock);
  MsTimer2::start();

}

void loop() {
  if(digitalRead(7)==1) {
    hours++;
    secs=0;
    if(hours>23) hours=0;
  }
  else if(digitalRead(8)==1) {
    mins++;
    secs=0;
    if(mins>59) mins=0;
  }

  lcd.setCursor(0,1);
  displayDigits(hours);
  displayDigits(mins);
  displayDigits(secs);
  delay(1000);
}
