/* Small Sound Detection Module (KY-038) [S053] : http://rdiot.tistory.com/152 [RDIoT Demo] */

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // LCD2004

int threshold = 30; 

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;

int pin = A0;

void setup()
{
  lcd.init();  // initialize the lcd 
  lcd.backlight();
  lcd.print("start LCD2004");

  pinMode(pin,INPUT);

  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);

  delay(1000);

  lcd.clear();
}

void loop()
{
 
  lcd.setCursor(0,0);
  lcd.print("S052:SoundDetect");

  int val = analogRead(pin);

  lcd.setCursor(0,1);
  lcd.print("val=" + (String)val + "  ");

  if(val <= threshold)
  { 
    lcd.setCursor(0,2);
    lcd.print("                    ");
  }
  else
  {
    lcd.setCursor(0,2);
    lcd.print("Small Sound Detected");
    delay(100);  
  }

  digitalWrite(led1, LOW); 
  digitalWrite(led2, LOW); 
  digitalWrite(led3, LOW); 
  digitalWrite(led4, LOW); 
  digitalWrite(led5, LOW); 
 
  if(val > 30) { digitalWrite(led1, HIGH); }
  if(val > 31) { digitalWrite(led2, HIGH); }
  if(val > 32) { digitalWrite(led3, HIGH); }
  if(val > 35) { digitalWrite(led4, HIGH); }
  if(val > 40) { digitalWrite(led5, HIGH); }

  delay(50);
}
