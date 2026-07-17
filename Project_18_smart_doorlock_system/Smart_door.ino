#include <Servo.h>*
#include <LiquidCrystal.h>
#include <Keypad.h>
int lcd1=A2;
int lcd2=A3;
char keys[4][4]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rows[4]={13,12,11,10};
byte cols[4]={7,6,5,4};

Keypad KP=Keypad(makeKeymap(keys),
                 rows,
                 cols,
                 4,
                 4);



LiquidCrystal lcd(9,8,3,2,lcd1,lcd2);

Servo door;

int buzzer=A0;
int index=0;

char password[4]={'2','5','8','0'};
char attempt[4];
bool correct_attempt=false;

void setup(){
  door.attach(A5);
  door.write(0);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Enter pin:");
}

void loop(){
  char key=KP.getKey();
  if(key){
    lcd.print(key);
    attempt[index]=key;
    index++;
    if(index>4){
      lcd.setCursor(14,0);
      lcd.print("  ");
      lcd.setCursor(14,0);
    }
  }
  
  
  if(key=='*'){
    lcd.setCursor(10,0);
    lcd.print("      ");
    lcd.setCursor(10,0);
    index=0;
    
  }
  else if(key=='#'){
    for(int i=0; i<4; i++){
        if(attempt[i]==password[i]){
          correct_attempt=true;
        }
        else{
          correct_attempt=false;
          break;
        }
        
      }
      if(correct_attempt){
        lcd.setCursor(0,1);
        lcd.print("Access Granted");
        door.write(90);
        tone(buzzer,800,800);
        delay(4000);
        door.write(0);
      }
      else{
        lcd.setCursor(0,1);
        lcd.print("Access Denialed");
        tone(buzzer,1000,2000);
      }
    delay(2000);
    lcd.setCursor(10,0);
    lcd.print("      ");
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(10,0);
    index=0;
  }
  
  
}
