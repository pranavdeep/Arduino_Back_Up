#include "LedControl.h"
LedControl lc=LedControl(10,12,11,1);  // Pins: DIN,CLK,CS, # of Display connected
unsigned long delayTime=200;  // Delay between Frames
byte l[] = {B10000000,B10000000,B10000000,B00000000,B00000000,B00000000,B00000000,B00000000};


void setup() {
  
Serial.begin(9600);
lc.shutdown(0,false);  // Wake up display
lc.setIntensity(0,5);  // Set intensity levels
lc.clearDisplay(0);  // Clear Display

}

void loop()
{
  evil1();
  delay(1000  );

}

void evil1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,l[i]);
    delay(100);
  }
  }
