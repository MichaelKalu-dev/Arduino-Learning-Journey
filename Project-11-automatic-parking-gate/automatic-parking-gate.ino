#include <Servo.h>
int red=13;
int green=11;
int sigpin=7;
unsigned long sigpin_value;
int distance;

Servo gate;

void setup(){
  gate.attach(9);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  
}

void loop(){
  
  pinMode(sigpin,OUTPUT);
  digitalWrite(sigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(sigpin,HIGH);
  delayMicroseconds(5);
  digitalWrite(sigpin,LOW);
  
  pinMode(sigpin,INPUT);
  sigpin_value=pulseIn(sigpin,HIGH);
  distance=sigpin_value/58;
  
  if(distance<=10){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    gate.write(90);
    delay(5000);
  }
  else{
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    gate.write(0);
  }
    
}
