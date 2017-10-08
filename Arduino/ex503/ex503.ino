#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

double R1=10000.0;
double V_IN=5.0;
double A=0.001129148;
double B=0.000234125;
double C=0.0000000876741;
double adcRaw;
double Vout;
double R_th;
double kelvin;
double celsius;

void setup()
{
  lcd.begin(8,2);
  lcd.setCursor(0,0);
  Serial.begin(9600);
}
void loop()
{
  adcRaw=analogRead(0);
  Vout=adcRaw/1024*V_IN;
  R_th=(R1*Vout)/(V_IN-Vout);
  Serial.print(R_th);
  kelvin=SteinhartHart(R_th);
  celsius=kelvin-273.15;
  printTemp(celsius);
  delay(1000);
}
double SteinhartHart(double R)
{
  double logR=log(R);
  double logR3=logR*logR*logR;
  return 1.0 / (A+B * logR + C*logR3);
}
void printTemp(double temp)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("*Temp.C*");
  lcd.setCursor(1,1);
  lcd.print(temp);
  lcd.print(" C");
}

