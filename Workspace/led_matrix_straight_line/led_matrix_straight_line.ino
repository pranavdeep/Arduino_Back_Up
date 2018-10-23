#include "LedControl.h"

LedControl lc=LedControl(10,12,11,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames


byte st_0[] = { B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000,B00000000};
byte st_1[] = { B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000,B00000000};
byte st_2[] = { B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000,B00000000};
byte st_3[] = { B00000000,B00000000,B00000000,B11111111,B00000000,B00000000,B00000000,B00000000};

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

void loop() 
{
  st1();
  delay(100);
  st2();
  delay(100);
  st3();
  delay(100);
  st4();
  delay(100);

}

void st1()
{
  
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,st_1[i]);
    lc.setIntensity(1,5);
    delay(400);
  }
}
  void st2()
{
  
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,st_2[i]);
    lc.setIntensity(2,5);
    delay(400);
  }
}
void st3()
{
  
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(2,i,st_3[i]);
    lc.setIntensity(3,5);
    delay(400);
  }
}

void st4()
{
  
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,st_0[i]);
    lc.setIntensity(0,5);
    delay(400);
  }
}

  

