#include <LiquidCrystal.h>
#include <MsTimer2.h>

LiquidCrystal lcd(12,11,5,4,3,2);

unsigned char count;
unsigned char secs;
unsigned char mins;
unsigned char hours;
unsigned char alarm_sec=0x00;
unsigned char alarm_min;
unsigned char alarm_hour;
boolean alarm_set;
boolean alarm_ring=0x00;
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

void alarm_proc() {
  char lcd_text[16];
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("AlarmSet");
  delay(100);

  while(1) 
  {
    lcd.setCursor(0,1);
    displayDigits(alarm_hour);
    displayDigits(alarm_min);
    displayDigits(alarm_sec);
    delay(100);

    if(digitalRead(7)==1) {
      delay(100);
      alarm_hour++;
      if(alarm_hour>23) alarm_hour=0;
    }
    if(digitalRead(8)==1) {
      delay(100);
      alarm_min++;
      if(alarm_min>59) alarm_min=0;
    }
    if(digitalRead(9)==1) {
      delay(100);
      alarm_set=1;
      break;
    }
    if(digitalRead(10)==1) {
      delay(100);
      alarm_set=0;
      break;
    }
  }
  lcd.clear();
}


void setup() {
  for(int i=7;i<=10;i++) {
    pinMode(i,INPUT);
  }
  pinMode(6,OUTPUT);
  for(int i=14;i<=17;i++) {
    pinMode(i,OUTPUT);
  }

  lcd.begin(8,2);
  lcd.setCursor(0,0);
  lcd.print("AL-Clock");

  MsTimer2::set(10,clock);
  MsTimer2::start();
}

void loop() {
  if(alarm_set==0x01) 
  {
    digitalWrite(14,HIGH);
    lcd.setCursor(0,0);
    lcd.print("AL-");
    displayDigits(alarm_hour);
    displayDigits(alarm_min);
  }

  else {
    digitalWrite(14,LOW);
    lcd.setCursor(0,0);
    lcd.print("AL-Clock");
  }
  if ((alarm_set==1) && (alarm_hour==hours) && (alarm_min==mins) && (secs==0)) {
    alarm_ring=1;
  }
  if((digitalRead(10)==1) || (alarm_ring==1) && (mins!=alarm_min)) {
    alarm_ring=0;
    alarm_set=0;
    analogWrite(6,0);
  }
  if(alarm_ring == 0x01) {
    analogWrite(6,128);
  }
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
  else if(digitalRead(9)==1) {
    delay(200);
    alarm_proc();
  }

  lcd.setCursor(0,1);
  displayDigits(hours);
  displayDigits(mins);
  displayDigits(secs);
  delay(1000);
}
