#include <SoftwareSerial.h> //시리얼 통신 라이브러리 호출
#include <Servo.h>

Servo serv;
int blueTx = 2; //Tx (블투 보내는핀 설정)
int blueRx = 3; //Rx (블투 받는핀 설정)
int dcMotor = 11;
int dcMotors = 12;
int servMotor = 7;
int isTurn = 0;
int spd=0;

SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString = ""; //받는 문자열
void turn() {
  for (int angle = 90 - 30 * isTurn; angle < 90 + 30 * isTurn; angle++) {
    serv.write(angle);
    analogWrite(dcMotor, (int)((0.33*spd) * 255));
    delay(40);
    Serial.println(serv.read());
    if (isInput())
    {
      break;
      return;
    }
  }
  for (int angle = 90 + 30 * isTurn; angle > 90 - 30 * isTurn; angle--) {
    serv.write(angle);
    delay(40);
    Serial.println(serv.read());
    if (isInput())
    {
      break;
      return;
    }
  }
}
boolean isInput() {
  if (!myString.equals(""))
    return true;
  else
    return false;
}
void setup() {
  serv.attach(servMotor);
  serv.write(90);
  Serial.begin(9600);
  Serial.println("Hello!");
  Serial.println(serv.read());
  mySerial.begin(9600); //블루투스 시리얼 개방
  pinMode (dcMotor, OUTPUT); // relay를 output으로 설정
  pinMode (dcMotors, OUTPUT);
  digitalWrite(dcMotor,LOW);
  digitalWrite(dcMotors,LOW);
}

void loop() {
  while (mySerial.available()) //mySerial 값이 있으면
  {
    char myChar = (char)mySerial.read();  //mySerial int형식의 값을 char형식으로 변환
    if (myChar != '\n')
      myString += myChar; //수신되는 문자열을 myString에 모두 붙임 (1바이트씩 전송되는 것을 모두 붙임)
    delay(5);           //수신 문자열 끊김 방지
  }

  if (!myString.equals("")) //myString 값이 있다면
  {
    Serial.println("input value: " + myString); //시리얼모니터에 myString값 출력

    if (myString == "on1") //myString 값이 'on' 이라면
    {
      spd=1;
    }
    else if (myString == "on2")
    {
      spd=2;
    }
    else if (myString == "on3")
    {
      spd=3; 
    }
    else if (myString == "on4")
    {
      serv.attach(servMotor);
      Serial.println(serv.read());
      isTurn = 1;
    }
    else if (myString == "off4")
    {
      analogWrite(dcMotor, 0);
      Serial.println(serv.read());
      isTurn = 0;      
    }
    else if (myString == "on5")
    {
      serv.attach(servMotor);
      Serial.println(serv.read());
      isTurn = 2;
    }
    else if (myString == "on6")
    {
      serv.attach(servMotor);      
      Serial.println(serv.read());
      isTurn = 3;
    }
    else {
      analogWrite(dcMotor, 0);
      Serial.println(serv.read());
      isTurn = 0;
      spd=0;
    }
    myString = ""; //myString 변수값 초기화
  }
  turn();
  analogWrite(dcMotor, (int)((0.33*spd) * 255));
}
