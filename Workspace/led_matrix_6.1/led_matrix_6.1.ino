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
  /*
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis <= t1)
  {
      previousMillis = currentMillis;
      currentMillis = millis();
      side_1();
  }
  else if (currentMillis - previousMillis <= t2)
  {
    previousMillis = currentMillis;
    currentMillis = millis();
    side_2();
  }
  else if (currentMillis - previousMillis <= t3)
  {
    previousMillis = currentMillis;
    currentMillis = millis();
    side_3();
  }
  else if (currentMillis - previousMillis <= t4)
  {
    previousMillis = currentMillis;
    currentMillis = millis();
    side_4();
  }
  */
   side_1();
   delay(500);
   side_2();
   delay(500);
   side_3();
   delay(500);
   side_4();
   delay(500);
   clear_all(500);
   
  
}


void side_1()
{
 i,j=0;
while(j<4)
{
  while(i<8)
  {
  lc.setLed(j,7,i,true);   
   i++;
  }
  i=0;
  j++;
  }
}


void side_2()
{
  x=0;
  while(x<8)
  {
  lc.setLed(3,x,0,true);   
   x++;
  }
  x=0;   
}


void side_3()
{
 y=0;
while(y<4)
{
  while(z<8)
  {
  lc.setLed(y,0,z,true);   
   z++;
  }
  z=0;
  y++;
}
}


void side_4()
{
  k=0;
  while(k<8)
  {
  lc.setLed(0,k,7,true);   
   k++;
  }
  k=0;   
}
void clear_all(int interval)
{
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
  delay(interval);
}




