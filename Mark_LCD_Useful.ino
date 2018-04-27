//
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include <Time.h>

LiquidCrystal_I2C lcd(0x3f,20,4);  // set the LCD address to 0x3f for a 16 chars and 4 line display
  
  long newTimeSec;
  long oldTimeSec;
  int temp;  


void setup()
{

  lcd.init();                      // initialize the lcd 
  lcd.backlight();                  //  
  lcd.clear();
  welcomeMessage();
  delay(1500);
  lcd.clear();
  screenSetup();
}


void loop()
{
 temp=random(100);
 newTimeSec = hour()*3600 + minute()*60 + second();
 

 if(newTimeSec > (oldTimeSec+4)){
 
 oldTimeSec=newTimeSec;
 printTime(newTimeSec);
 printTemp(temp);
 }
 delay(500);
}


void printTemp(int var) {
  lcd.setCursor(1,1);
  lcd.print("   ");  // over write the old value with ___
  lcd.setCursor(1,1); 
  lcd.print(var);      // write the new value
}

void printTime(int var) {
  lcd.setCursor(11,1);
  lcd.print("         ");  // over write the old value with ___
  lcd.setCursor(11,1);
  lcd.print(hour());   // write the new value
  lcd.print(":");
  lcd.print(minute());
  lcd.print(":");
  lcd.print(second());
}

void screenSetup() {
   // set up the main display         
  /*   
   *   Temp:       Time:
   *    xx   F      xxxxxx ms
   *    
   *   Text goes here
   */
  lcd.setCursor(0,0);    // logical line 0
  lcd.print("Temp:");
  lcd.setCursor(10,0);
  lcd.print("Time:");
  
  lcd.setCursor(4,1);    // logical line 1
  lcd.print("F");
  lcd.setCursor(17,1);
  lcd.print("sec");
  
  lcd.setCursor(0,3);     // logical line 3
  lcd.print("Text goes here");  
}

void welcomeMessage(){
    lcd.setCursor(0,0);
  lcd.print("Hello, world!");       // so cliche'd
  lcd.setCursor(0,1);              // left justified line 1 (2nd line)
  lcd.print("Mark Gryzwa");
}

