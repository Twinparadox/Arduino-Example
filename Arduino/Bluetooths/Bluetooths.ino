#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
 
int blueTx=9;   //Tx (블투 보내는핀 설정)
int blueRx=8;   //Rx (블투 받는핀 설정)
int relay[4] = {13,12,11,10}; //릴레이 Signal 핀 설정
 
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString=""; //받는 문자열
 
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); //블루투스 시리얼 개방
  for(int i=0;i<4;i++) {
   pinMode (relay[i], OUTPUT); // relay를 output으로 설정
   digitalWrite(relay[i],HIGH); 
  }
}
 
void loop() {
  while(mySerial.available())  //mySerial 값이 있으면
  {
    char myChar = (char)mySerial.read();  //mySerial int형식의 값을 char형식으로 변환
    myString+=myChar;   //수신되는 문자열을 myString에 모두 붙임 (1바이트씩 전송되는 것을 모두 붙임)
    delay(5);           //수신 문자열 끊김 방지
  }
  
  if(!myString.equals(""))  //myString 값이 있다면
  {
    Serial.println("input value: "+myString); //시리얼모니터에 myString값 출력
      if(myString=="on")  //myString 값이 'on' 이라면
      {
        // 모든 릴레이 ON
        for(int i=0;i<4;i++) {
          digitalWrite (relay[i], LOW);
        }
      }
      else if(myString=="off")
      {
        // 모든 릴레이 ON
        for(int i=0;i<4;i++) {
          digitalWrite (relay[i], HIGH);
        }
      }
      else if(myString=="on1")
      {
        digitalWrite(relay[0],LOW);
      }
      else if(myString=="off1")
      {
        digitalWrite(relay[0],HIGH);
      }
      else if(myString=="on2")
      {
        digitalWrite(relay[1],LOW);
      }
      else if(myString=="off2")
      {
        digitalWrite(relay[1],HIGH);
      }
      else if(myString=="on3")
      {
        digitalWrite(relay[2],LOW);
      }
      else if(myString=="off3")
      {
        digitalWrite(relay[2],HIGH);
      }
      else if(myString=="on4")
      {
        digitalWrite(relay[3],LOW);
      }
      else if(myString=="off4")
      {
        digitalWrite(relay[3],HIGH);
      }
      myString="";  //myString 변수값 초기화
  }

  if(Serial.available()) {
    mySerial.write(Serial.read());
  }
}
