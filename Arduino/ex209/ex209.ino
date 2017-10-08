void setup() {
  for(int i=9;i<=11;i++)
    pinMode(i,OUTPUT);  
}
void loop() {
  if(digitalRead(6)==1)
  {
    tone(7,262,250);
    digitalWrite(9,HIGH);
    delay(325);
    tone(7,330,250);
    digitalWrite(10,HIGH);
    delay(325);
    tone(7,392,500);
    digitalWrite(11,HIGH);
    delay(325);
  }
  noTone(7);
  for(int i=9;i<=11;i++)
  {
    digitalWrite(i,LOW);
  }
  delay(500);
}

