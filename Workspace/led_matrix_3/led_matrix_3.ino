#include "LedControl.h"

LedControl lc=LedControl(10,12,11,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames
int i=7,j=0;

void setup()
{
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);  // Wake up displays
  lc.shutdown(3,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);  // Set intensity levels
  lc.setIntensity(3,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
}
byte heart[] = {B00000000,B01100110,B10011001,B10000001,B10000001,B01000010,B00100100,B00011000};
void loop() 
{
  heart1(j);
  delay(250);
  
  if(j<4)
  j++;
  else
  {
  j=0;
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
  }

}


void heart1(int n)
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(n,i,heart[i]);
    delay(100);
  }
}
