#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,5,4,3,2);

int TempSensor=A0;
int buzzer=11;
bool buzzer_on=true;

float Tempvalue;
float voltage;
float Realtemp;

int current;
int previous=0;
unsigned long starttime=0;

void setup(){
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Temperature:");
  
  
}

void loop(){
  
  Tempvalue=analogRead(TempSensor);
  voltage=Tempvalue *(5.0/1023.0);
  Realtemp=(voltage-0.5)*100.0;
  current=round(Realtemp);
  if(current!=previous){
    lcd.setCursor(12,0);
    lcd.print("     ");
    lcd.setCursor(12,0);
    lcd.print(current);
    lcd.print("C");
    
    if(current<18){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("Below Ideal Temp");
      noTone(buzzer);
    }
    else if(current<=28){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("Suitable Temp");
      noTone(buzzer);
    }
    else if(current<=35){
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("Above Ideal Temp");
      
    }
    else{
      lcd.setCursor(0,1);
      lcd.print("                ");
      lcd.setCursor(0,1);
      lcd.print("Dangerous Temp");
      
    }
  }else{}
  previous=current;
  
  if(millis()-starttime>=200 &&current<=35 && current>28){
    
    if(buzzer_on){
      tone(buzzer,800);
      buzzer_on=false;
    }
    else{
      noTone(buzzer);
      buzzer_on=true;
    }
    starttime=millis();
  }
  else if(millis()-starttime>=100 && current>35){
    
    if(buzzer_on){
      tone(buzzer,1500);
      buzzer_on=false;
    }
    else{
      noTone(buzzer);
      buzzer_on=true;
    }
    starttime=millis();
  }
  
}
