#include "LedControl.h"
LedControl lc=LedControl(2,5,3,4); 

int delayTime = 0.001;
//int charBreak = 10;
int charBreak = 0.001;


void setup(){
lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.shutdown(2,false);  // Wake up displays
  lc.shutdown(3,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);  // Set intensity levels
  lc.setIntensity(3,5);
  clear_all(100);
}


void loop()
{
  side_1(10);
  side_t1(10);
  side_t1(10);
  side_1(10);  
  //clear_all(100);
}
void side_1(int interval)
{
  lc.setLed(1,0,2,true);
  lc.setLed(1,0,3,true);
  lc.setLed(1,0,4,true);
  lc.setLed(1,0,5,true);
  lc.setLed(1,0,6,true);
  lc.setLed(1,0,7,true);
  delay(interval);
}
void side_t1(int interval)
{
  lc.setLed(1,0,2,true);
  lc.setLed(1,0,3,false);
  lc.setLed(1,0,4,false);
  lc.setLed(1,0,5,false);
  lc.setLed(1,0,6,false);
  lc.setLed(1,0,7,true);
  delay(interval);
}



void clear_all(int interval)
{
  lc.clearDisplay(0); 
  lc.clearDisplay(1);
  lc.clearDisplay(2);  
  lc.clearDisplay(3);
  delay(interval);
}

