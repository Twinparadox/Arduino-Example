#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
 
int sensor;
int delay_time;
 
byte heart[8]={
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000
 };
 
 byte lee[8]={0x09,0x15,0x15,0x15,0x15,0x15,0x15,0x09};
 byte so[8]={0x04,0x0A,0x0A,0x11,0x11,0x04,0x04,0x1AF};
 byte young1[8]={0x0E,0x11,0x11,0x0E,0x00,0x03,0x04,0x03};
 byte young2[8]={0x04,0x1C,0x04,0x1C,0x04,0x1C,0x02,0x1C};

 byte armsDown[8]={0x04,0x0E,0x04,0x04,0x0E,0x15,0x04,0x0A};
 byte armsUp[8]={0x04,0x0A,0x04,0x15,0x0E,0x04,0x04,0x0A};
 
void setup() {
  lcd.createChar(1,heart);
  lcd.createChar(2,lee);
  lcd.createChar(3,so);
  lcd.createChar(4,young1);
  lcd.createChar(5,young2);
  lcd.createChar(6,armsDown);
  lcd.createChar(7,armsUp);  
 
  lcd.begin(8,2);
  lcd.clear();
 
  lcd.print("8x2 LCD");
  lcd.setCursor(0,1);
  lcd.write(1);
  lcd.setCursor(2,1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}
void loop() {
  sensor=analogRead(A5);
  delay_time=sensor+200;
 
  lcd.setCursor(7,1);
 
  lcd.write(6);
  delay(delay_time);
 
  lcd.setCursor(7,1);
 
  lcd.write(7);
  delay(delay_time);
}

