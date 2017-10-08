void setup() {
  for(int i=8;i<=11;i++)
  {
    pinMode(i,OUTPUT);
  }
}
void loop() {
  for(int i=8;i<=11;i++)
  {
    if(i%2==1)
    {
      digitalWrite(i,HIGH);
    }
    else
    {
      digitalWrite(i,LOW);
    }
  }
  delay(500);
  for(int i=8;i<=11;i++)
  {
    if(i%2==1)
    {
      digitalWrite(i,LOW);
    }
    else
    {
      digitalWrite(i,HIGH);
    }
  } 
  delay(500);
}

