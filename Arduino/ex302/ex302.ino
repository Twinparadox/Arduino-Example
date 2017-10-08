int PWMValue;
void digitalLED(int red,int green,int blue){
  digitalWrite(9,blue);
  digitalWrite(10,green);
  digitalWrite(11,red);
}
void analogLED(int redPwm,int greenPwm,int bluePwm){
  analogWrite(9,bluePwm);
  analogWrite(10,greenPwm);
  analogWrite(11,redPwm);
}
void setup(){
}
void loop(){
  digitalLED(LOW,LOW,HIGH);
  delay(500);
  digitalLED(LOW,HIGH,LOW);
  delay(500);
  digitalLED(HIGH,LOW,LOW);
  delay(500);
  for(PWMValue=0;PWMValue<=255;PWMValue+=5){
    analogLED(0,0,PWMValue);
    delay(100);
  }
  for(PWMValue=0;PWMValue<=255;PWMValue+=5){
    analogLED(0,PWMValue,0);
    delay(100);
    }
  for(PWMValue=0;PWMValue<=255;PWMValue+=5){
    analogLED(PWMValue,0,0);
    delay(100);
  }
    for(PWMValue=0;PWMValue<=255;PWMValue+=5){
    analogLED(PWMValue,PWMValue,0);
    delay(100);
  }
  for(PWMValue=0;PWMValue<=255;PWMValue+=5){
    analogLED(PWMValue,0,PWMValue);
    delay(100);
  }  
  for(PWMValue=0;PWMValue<=255;PWMValue+=5){
    analogLED(0,PWMValue,PWMValue);
    delay(100);
  }
  for(PWMValue=0;PWMValue<=255;PWMValue+=5){
    analogLED(PWMValue,PWMValue,PWMValue);
    delay(100);
  }
}
