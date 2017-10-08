#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2); 
void setup() {
  lcd.begin(8,2);
} 
void loop() {
  lcd.clear();
  lcd.print("Cursor");
  lcd.setCursor(3,1);
  lcd.cursor();
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("noCursor");
  lcd.setCursor(3,1);
  lcd.noCursor();
  delay(3000);
 
  lcd.clear();
  lcd.print("Blink");
  lcd.setCursor(3,1);
  lcd.blink();
  delay(3000);
 
  lcd.setCursor(0,0);
  lcd.print("noBlink");
  lcd.setCursor(3,1);
  lcd.noBlink();
  delay(3000);
 
  lcd.clear();
  lcd.print("Display");
  lcd.display();
  delay(1500);
  lcd.noDisplay();
  delay(1500);
  lcd.display();
}

