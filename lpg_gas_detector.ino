#include "LiquidCrystal.h"
LiquidCrystal lcd(9,8,7,6,5,4);

int gas_value= 0;

void setup()
{
  pinMode(A0, INPUT); 
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(11,OUTPUT); 
  pinMode(12,OUTPUT); 
  
  lcd.setCursor(0,0);
  lcd.print("   GAS SENSOR  ");
 
}

void loop()
{
  gas_value = analogRead(A0);
  Serial.println(gas_value);


 if (gas_value > 500)
 {
    lcd.setCursor(0,1);
    lcd.print("  LPG Detected    ");
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
  }
  
  else
 {
     lcd.setCursor(0,1);
     lcd.print("LPG Not Detected    ");
     digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
  }
  
  delay(10); 
}
