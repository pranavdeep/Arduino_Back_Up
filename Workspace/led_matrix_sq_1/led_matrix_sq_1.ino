#include "LedControl.h"
LedControl lc=LedControl(2,5,3,4); 

int delayTime = 0.001;
//int charBreak = 2.1;
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
  side_1();
  clear_2(1);
  side_2(); 
  side_3();
  side_3();
  side_4();
  side_5();
 side_8();
 side_9();
 side_10();
  side_11();
  clear_1(1);
  
  clear_all(15);
}
void side_1()
{
  lc.setLed(1,0,2,true);
  lc.setLed(1,0,3,true);
  lc.setLed(1,0,4,true);
  lc.setLed(1,0,5,true);
  lc.setLed(1,0,6,true);
  lc.setLed(1,0,7,true);
 // delay(1);
}
void side_11()
{
  lc.setLed(1,7,2,true);
  lc.setLed(1,7,3,true);
  lc.setLed(1,7,4,true);
  lc.setLed(1,7,5,true);
  lc.setLed(1,7,6,true);
  lc.setLed(1,7,7,true);
 // delay(1);
}
void side_8()
{
  lc.setLed(1,3,2,true);
  lc.setLed(1,3,7,true);
  delay(1);
}

void side_9()
{
  lc.setLed(1,2,2,true);
  lc.setLed(1,2,7,true);
  delay(1);
}
void side_10()
{
  lc.setLed(1,1,2,true);
  lc.setLed(1,1,7,true);
  delay(1);
}
void side_2()
{
  lc.setLed(1,4,2,true);
  lc.setLed(1,4,7,true);
  delay(1);
}
void side_3()
{
  lc.setLed(1,5,2,true);
  lc.setLed(1,5,7,true);
  delay(1);
}
void side_4()
{
  lc.setLed(1,6,2,true);
  lc.setLed(1,6,7,true);
  delay(1);
}

void side_5()
{
  lc.setLed(1,7,2,true);
  lc.setLed(1,7,7,true);
  delay(1);
}
void clear_1(int interval)
{

  lc.setLed(1,7,2,false);
  lc.setLed(1,7,3,false);
  lc.setLed(1,7,4,false);
  lc.setLed(1,7,5,false);
  lc.setLed(1,7,6,false);
  lc.setLed(1,7,7,false);
  delay(interval);
}
void clear_2(int interval)
{

  lc.setLed(1,0,2,false);
  lc.setLed(1,0,3,false);
  lc.setLed(1,0,4,false);
  lc.setLed(1,0,5,false);
  lc.setLed(1,0,6,false);
  lc.setLed(1,0,7,false);
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

