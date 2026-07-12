#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);

int blue=11;
int green=10;
int yellow=9;
int red=8;
int tempSensor=A0;
int buzzer=A1;


float tempValue;
float voltage;
int currentTemp;
int previousTemp=0;


void setup(){
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  lcd.setCursor(0,1);
  lcd.print("Status:");
}

void loop(){
  tempValue=analogRead(tempSensor);
  voltage= tempValue *(5.0/1023.0);
  currentTemp=round((voltage-0.5)*100.0);
  
  if(currentTemp!=previousTemp){
    lcd.setCursor(12,0);
    lcd.print("    ");
    lcd.setCursor(12,0);
    lcd.print(currentTemp);
    lcd.print("C");
    lcd.setCursor(7,1);
    lcd.print("          ");
    lcd.setCursor(7,1);
    if(currentTemp<15){
      lcd.print("Too cold");
      digitalWrite(blue,HIGH);
      digitalWrite(red,LOW);
      digitalWrite(yellow,LOW);
      digitalWrite(green,LOW);
      tone(buzzer,500);
    }
    else if(currentTemp<=30){
      lcd.print("Suitable");
      digitalWrite(blue,LOW);
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      digitalWrite(yellow,LOW);
      noTone(buzzer);
      
    }
    else if(currentTemp<=40){
      lcd.print("Warm");
      digitalWrite(yellow,HIGH);
      digitalWrite(green,LOW);
      digitalWrite(red,LOW);
      digitalWrite(blue,LOW);
      tone(buzzer,800);
    }
    else{
      lcd.print("Too hot");
      digitalWrite(red,HIGH);
      digitalWrite(blue,LOW);
      digitalWrite(green,LOW);
      digitalWrite(yellow,LOW);
      tone(buzzer,1500);
    }
  }
  else{}
  previousTemp=currentTemp;
  
  
  
}
