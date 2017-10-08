int buttonState=0;
void setup() {
for(int i=8;i<=11;i++)
{
  pinMode(i,OUTPUT);
}
pinMode(2,INPUT);
pinMode(3,INPUT);
}

void loop() {
  buttonState=digitalRead(2);
  if(buttonState==HIGH)
  {
    for(int i=8;i<=11;i++)
    {
      digitalWrite(i,HIGH);
    }
  }
  buttonState=digitalRead(3);
  if(buttonState==HIGH)
  {
   for(int i=8;i<=11;i++)
   {
    digitalWrite(i,LOW);
   }
  }
}

