#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);
String Incoming_value = "";
int pos=0;

void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Please send a ");
  lcd.setCursor(0,1);
  lcd.print("message: ");

}

void loop() {
  if(Serial.available()>0)
  {
    lcd.clear();
    Incoming_value=Serial.readString();
    Serial.print(Incoming_value);
    lcd.setCursor(0,0);
    lcd.print(Incoming_value);
    
    Serial.print("\n");
    if(Incoming_value=="1" || Incoming_value=="On" || Incoming_value=="on"){
      digitalWrite(13, HIGH);
      lcd.setCursor(0,0);
      lcd.print("The light is on");
      lcd.setCursor(0,1);
      lcd.print("Message: ");
      
    }
    else if(Incoming_value=="0"|| Incoming_value=="Off" || Incoming_value=="off"){
      digitalWrite(13,LOW);
      lcd.setCursor(0,0);
      lcd.print("The light is off");
      lcd.setCursor(0,1);
      lcd.print("Message: ");
    }
    else{
      lcd.setCursor(0,0);
      lcd.print(Incoming_value);
      if(Incoming_value.length()>16){
        lcd.setCursor(0,1);
        lcd.print(Incoming_value.substring(16));
        }
      delay(1000);
      }
    
    
  }
  

}
