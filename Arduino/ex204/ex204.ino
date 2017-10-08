int buttonState=0;
 void setup() {
 for(int i=8;i<=11;i++)
 {
   pinMode(i,OUTPUT);
 }
 pinMode(2,INPUT);
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
   else
   {
    for(int i=8;i<=11;i++)
    {
     digitalWrite(i,LOW);
    }
   }
}

