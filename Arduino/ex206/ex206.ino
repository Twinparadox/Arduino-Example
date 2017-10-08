int sensorValue=0;
void setup() {
  for(int i=8;i<=12;i++)
  {
    pinMode(i,OUTPUT);
  }
}
void loop() {
  sensorValue=analogRead(A4);

  for(int i=8;i<=12;i++)
  {
    digitalWrite(i,HIGH);
  }
  delay(sensorValue);
  for(int i=8;i<=12;i++)
  {
    digitalWrite(i,LOW);
  }
  delay(sensorValue);
}

