#include <Servo.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(11,10,5,4,3,2);
Servo gate;


int red=9;
int green=8;
int sigpin=13;
unsigned long sigpin_value;
int distance;


enum State{
  Open,
  Close,
};
State currentState;
  


void setup(){
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  gate.attach(7);
  gate.write(0);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  
  lcd.print("Automatic gate");
  lcd.setCursor(0,1);
}

void loop(){
  pinMode(sigpin,OUTPUT);
  digitalWrite(sigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigpin,HIGH);
  delayMicroseconds(5);
  digitalWrite(sigpin,LOW);
  
  pinMode(sigpin,INPUT);
  sigpin_value=pulseIn(sigpin,HIGH);
  distance=sigpin_value/58;
  
    
  if(distance<=30){
    currentState=Open;
  }
  else{
    currentState=Close;
  }
  
  
  
  switch(currentState){
    
    case Open:
    gate.write(90);
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Welcome");
    break;
    
    case Close:
    gate.write(0);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Goodbye");
    break;
    
  }
  
 
  
}
