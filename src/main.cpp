#include <Arduino.h> //

//#include <M5Stack.h>
#include <M5Core2.h>
int RawValue= 0;
double Voltage = 0;
double tempC = 0;
double Sum;
double OldTemp;
double minTemp = 200;
double maxTemp = 0;

void setup(){
   Serial.begin(115200);
   M5.begin();
   //M5.Power.begin();
   M5.Lcd.fillScreen(BLACK);
   //M5.Lcd.setTextColor(WHITE);
   M5.Lcd.setTextSize(7);
   //M5.Lcd.setCursor(40, 10);
   //M5.Lcd.printf("M5Stack Thermometer");
   //M5.Lcd.fillCircle(65, 180, 30, RED);
   //M5.Lcd.fillRect(55, 60, 20, 150, RED);
   //M5.Lcd.fillCircle(65, 60, 10, RED);   
      OldTemp = 0;
}

void loop(){

   //for(int k=1;k<=100;k++) {
      RawValue = analogRead(35);

      
   //}
   //Sum /= 100;
   Voltage = (RawValue / 2048.0) * 3300; // in millivots
   tempC = Voltage * 0.1;

   //Serial.println(tempC,1);
   //M5.Lcd.fillRect(140, 40, 170, 190, YELLOW);
   //M5.Lcd.setTextSize(4);
   //M5.Lcd.setTextColor(BLUE);
     if (tempC != OldTemp) {
    //overwrite old value with inverted color
    M5.Lcd.setCursor(100, 100);
    M5.Lcd.setTextColor(BLACK);
    M5.Lcd.printf("%.1f", OldTemp);
    //write new value
    M5.Lcd.setCursor(100, 100);
    M5.Lcd.setTextColor(WHITE);
    M5.Lcd.printf("%.1f", tempC);
    OldTemp = tempC;
    
    //delay(250);
  }
   
   
   //M5.Lcd.fillScreen(WHITE);
   //M5.Lcd.setCursor(175, 80);
   //M5.Lcd.printf("%.1f",tempC);
   //M5.Lcd.setTextSize(2);
   //M5.Lcd.setTextColor(BLACK);
   //M5.Lcd.setCursor(170, 150);
   //M5.Lcd.printf("MIN: %.1f",minTemp);
   //M5.Lcd.setCursor(170, 190);
   //M5.Lcd.printf("MAX: %.1f",maxTemp);
   //delay(1000);
}