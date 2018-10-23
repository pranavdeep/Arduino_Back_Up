#include "LedControl.h"
LedControl lc=LedControl(2,5,3,4); 

int delayTime = 0.001;
//int charBreak = 10;
int charBreak = 0.001;

byte a[]={B00000001,
B00000010,
B00000100,
B00001000,
B00010000,
B00001000,
B00000100,
B00000010};

void setup()
{
lc.shutdown(0,false);  
  lc.shutdown(1,false);
  lc.shutdown(2,false);  
  lc.shutdown(3,false);
  lc.setIntensity(1,5);
  lc.setIntensity(2,5);  
  lc.setIntensity(3,5);
  clear_all(100);
}


void clear_all(int interval)
{
  lc.clearDisplay(0); 
  lc.clearDisplay(1);
  lc.clearDisplay(2);  
  lc.clearDisplay(3);
  delay(interval);
}


void a_1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,a[i]);
    delay(150);
  }
}


void loop()
{
  a_1();
  clear_all(100);
}

