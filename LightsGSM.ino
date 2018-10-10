#include<SoftwareSerial.h>
int board =7;
int recept=6;
int corridor=2;
int hub=5;
int me=8;
int admin=13;
int studio=4;
SoftwareSerial serie(9,10);
void setup() {
serie.begin(9600);
Serial.begin(9600);
delay(100);
pinMode(board,OUTPUT);
pinMode(recept,OUTPUT);
pinMode(corridor,OUTPUT);
pinMode(hub,OUTPUT);
pinMode(me,OUTPUT);
pinMode(admin,OUTPUT);
pinMode(studio,OUTPUT);
}

void loop() {
  if (Serial.available()>0){
  switch(Serial.read()){
    case'B':
      Send();
      digitalWrite(board,HIGH);
      break;
    case 'b':
      Receive();
      digitalWrite(board,LOW);
      break;
       case'R':
      Send();
      digitalWrite(recept,HIGH);
      break;
    case 'r':
      Receive();
      digitalWrite(recept,LOW);
      break;
       case'C':
      Send();
      digitalWrite(corridor,HIGH);
      break;
    case 'c':
      Receive();
      digitalWrite(corridor,LOW);
      break;
       case'H':
      Send();
      digitalWrite(hub,HIGH);
      break;
    case 'h':
      Receive();
      digitalWrite(hub,LOW);
      break;
       case'M':
      Send();
      digitalWrite(me,HIGH);
      break;
    case 'm':
      Receive();
      digitalWrite(me,LOW);
      break;
       case'A':
      Send();
      digitalWrite(admin,HIGH);
      break;
    case 'a':
      Receive();
      digitalWrite(admin,LOW);
      break;
       case'S':
      Send();
      digitalWrite(studio,HIGH);
      break;
    case 's':
      Receive();
      digitalWrite(studio,LOW);
      break;
      
      
  }}
  
}
void Send(){
    serie.println("AT+CMGF=1");
    delay(1000);
    serie.println("AT+CMGS=\"+256787509953\"r");
    delay(1000);
    serie.println("Light is on");
    delay(100);
    serie.println((char)26);
    delay(1000);
  }
void Receive(){
  serie.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
}
