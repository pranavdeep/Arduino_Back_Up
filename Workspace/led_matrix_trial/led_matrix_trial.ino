#include "LedControl.h"
LedControl lc=LedControl(2,5,3,4); 

unsigned long delayTime=200;  // Delay between Frames
int i=0,j=0;
int x,z,y,k=0;

const long interval = 1000;

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
  
}
void loop()
{
  lc.setLed(1,4,2,true);
  lc.setLed(1,4,3,true);
  lc.setLed(1,4,4,true);
  lc.setLed(1,4,5,true);
  lc.setLed(1,4,6,true);
}

