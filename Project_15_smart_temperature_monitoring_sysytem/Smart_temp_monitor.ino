#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);

int red=9;
int green= 8;
int Temp=A0;
int value;
float voltage;
float realTemp;

int current;
int previous=0;
bool lcdPrinted=true;




void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Temperature");
  lcd.setCursor(0,1);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop(){
  value= analogRead(Temp);
  voltage=value*(5.0/1023.0);
  realTemp=(voltage-0.5)*100.0;
  current=round(realTemp);
  
  
  if(current!=previous){
    lcdPrinted=false;
  }
  else{
    lcdPrinted=true;
  }
  
  if(realTemp<=20){
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    if(lcdPrinted==false){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(current);
      lcd.print(" C (Cold)");
    }
    
  }
  else if(realTemp<=40){
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    if(lcdPrinted==false){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(current);
      lcd.print(" C (Normal)");
    }
  }
  else{
    digitalWrite(green,LOW);
    digitalWrite(red,HIGH);
    if(lcdPrinted==false){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print(current);
      lcd.print(" C (Hot)");
    }
  }
  previous=current;
  
  
}
