#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(8,2);
  lcd.setCursor(0,0);
  lcd.print("Hello !");
  lcd.setCursor(1,1);
  lcd.print("Arduino");
}
void loop() {}

