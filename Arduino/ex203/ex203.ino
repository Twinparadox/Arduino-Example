void setup() {
  for(int i=8;i<=11;i++)
  {
    pinMode(i,OUTPUT);
  }
}
void loop() {
  for(int i=8;i<=11;i++)
  {
    digitalWrite(i,HIGH);
    delay(200);
  }
  for(int i=8;i<=11;i++)
  {
    digitalWrite(i,LOW);
    delay(200);
  }
}

