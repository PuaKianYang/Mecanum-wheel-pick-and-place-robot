#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Servo.h>

Servo Servo1;
Servo Servo2;
Servo Servo3;

const byte rxPin = A5;
const byte txPin = A4;
SoftwareSerial BTSerial(rxPin, txPin); // RX TX

int Motor1Speed=3;
int Motor1Dir1=2;
int Motor1Dir2=4;

int Motor2Speed=5;
int Motor2Dir1=7;
int Motor2Dir2=A2;

int Motor3Speed=9;
int Motor3Dir1=8;
int Motor3Dir2=A3;

int Motor4Dir1=12;
int Motor4Dir2=13;

int Servo1Pin=11;
int Servo2Pin=10;
int Servo3Pin=6;
int angle1=0;
int angle2=0;
int angle3=0;

void Motor1F(){
digitalWrite(Motor1Dir1,HIGH);
digitalWrite(Motor1Dir2,LOW);
analogWrite(Motor1Speed,255);
}

void Motor1B(){
digitalWrite(Motor1Dir2,HIGH);
analogWrite(Motor1Speed,255);
}

void Motor2F(){
digitalWrite(Motor2Dir1,HIGH);
analogWrite(Motor2Speed,255);
}

void Motor2B(){
digitalWrite(Motor2Dir2,HIGH);
}

void Motor3F(){
digitalWrite(Motor3Dir1,HIGH);
digitalWrite(Motor3Dir2,LOW);
analogWrite(Motor3Speed,255);
}

void Motor3B(){
digitalWrite(Motor3Dir2,HIGH);
analogWrite(Motor3Speed,255);
}

void Motor4F(){
digitalWrite(Motor4Dir1,HIGH);
}

void Motor4B(){
digitalWrite(Motor4Dir2,HIGH);

}
void turnoff(){

  digitalWrite(Motor1Dir1,LOW);
  digitalWrite(Motor1Dir2,LOW);
  digitalWrite(Motor2Dir1,LOW);
  digitalWrite(Motor2Dir2,LOW);
  digitalWrite(Motor3Dir1,LOW);
  digitalWrite(Motor3Dir2,LOW);
  digitalWrite(Motor4Dir1,LOW);
  digitalWrite(Motor4Dir2,LOW);
}
void Forward(){
  Motor1F();
  Motor2F();
  Motor3F();
  Motor4F();
 }
void Backward(){
  Motor1B();
  Motor2B();
  Motor3B();
  Motor4B();
 }
void Right(){
  Motor1B();
  Motor2F();
  Motor3B();
  Motor4F();
}
void Left(){
  Motor1F();
  Motor2B();
  Motor3F();
  Motor4B();
}
void setup() {
  // put your setup code here, to run once:
pinMode(rxPin, INPUT);
pinMode(txPin, OUTPUT);
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
Servo1.attach(Servo1Pin);
Servo2.attach(Servo2Pin);
Servo3.attach(Servo3Pin);
BTSerial.begin(9600);
Serial.begin(9600);
Servo1.write(0);
Servo2.write(0);
Servo3.write(0);
}

void loop() {

while (BTSerial.available() > 0) {
    char data = (char) BTSerial.read();
  if (data == 'F') {
  Forward();

 }else if (data == 'B'){
  Backward();
  
 }else if (data == 'L'){
  Left();

 }else if (data == 'R'){
  Right();

 }else if (data == 'G'){
  Motor2F();
  Motor4F();

 }else if (data == 'I'){
  Motor1F();
  Motor3F();

 }else if (data == 'H'){
  Motor1B();
  Motor3B();

 }else if (data == 'J'){
  Motor2B();
  Motor4B();

 }else if (data == 'W'){
  angle1=angle1+15;
  delay(50);
  if(angle1>90){
    angle1=90;
  }
  Servo1.write(angle1);
 }else if (data == 'w'){
  angle1=angle1+15;  
  delay(50);
  if(angle1>90){
    angle1=90;
  }
  Servo1.write(angle1);
 }else if (data == 'U'){
  angle1=angle1-15;
  delay(50);
  if(angle1<=0){
    angle1=0;
  }
  Servo1.write(angle1);
 }else if (data == 'u'){
  angle1=angle1-15;
  delay(50);
  if(angle1<=0){
    angle1=0;
  }
  Servo1.write(angle1);
 }else if (data == 'V'){
  angle2=angle2+15;
  delay(50);
  if(angle2>105){
    angle2=0;
  }
  Servo2.write(angle2);
 }else if (data == 'v'){
  angle2=angle2+15;
  delay(50);
  if(angle2>105){
    angle2=0;
  }
  Servo2.write(angle2);
 }else if (data == 'X'){
  angle3=angle3+10;
  delay(50);
  if(angle3>20){
    angle3=0;
  }
  Servo3.write(angle3);
 }else if (data == 'x'){
  angle3=angle3+10;
  delay(50);
  if(angle3>20){
    angle3=0;
  }
  Servo3.write(angle3);
 }else{
 turnoff(); 
 }
 }
}