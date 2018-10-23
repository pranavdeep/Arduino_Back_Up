#include "LedControl.h"
LedControl lc=LedControl(2,5,3,4); 

int delayTime = 0.001;
//int charBreak = 10;
int charBreak = 0.001;

byte a[]={B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000001,
B00000010,
B00000100,
B00001000,
B00010000,
B00100000,
B01000000,
B10000000,
B01000000,
B00100000,
B00010000,
B00001000,
B00000100,
B00000010,
B00000001,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000};
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


void loop()
{
  //a_1();
int x=150;
  lc.setLed(3,0,7,true);
  delay(x);
  //lc.setLed(3,0,7,false);
  //delay(x);
  
  lc.setLed(2,1,0,true);
  delay(x);
  //lc.setLed(2,1,0,false);
  //delay(x);
  
  lc.setLed(2,2,1,true);
  delay(x);
  //lc.setLed(2,2,1,false);
  //delay(x);
  
  lc.setLed(2,3,2,true);
  delay(x);
 // lc.setLed(2,3,2,false);delay(x);

  
  lc.setLed(2,4,3,true);delay(x);
  //lc.setLed(2,4,3,false);delay(x);
  
  lc.setLed(2,5,4,true);delay(x);
  //lc.setLed(2,5,4,false);delay(x);

  
  lc.setLed(2,6,5,true);delay(x);
  //lc.setLed(2,6,5,false);delay(x);

  
  lc.setLed(2,7,6,true);delay(x);
  //lc.setLed(2,7,6,false);delay(x);

  
  lc.setLed(2,6,7,true);delay(x);
   //lc.setLed(2,6,7,false);delay(x);

  
  lc.setLed(1,5,0,true);delay(x);
  //lc.setLed(1,5,0,false);delay(x);

  
  lc.setLed(1,4,1,true);delay(x);
  //lc.setLed(1,4,1,false);
//delay(x);
  
  lc.setLed(1,3,2,true);delay(x);
  //lc.setLed(1,3,2,false);delay(x);

  
  lc.setLed(1,2,3,true);delay(x);
  //lc.setLed(1,2,3,false);delay(x);

  
  lc.setLed(1,1,4,true);delay(x);
  //lc.setLed(1,1,4,false);delay(x);

  
  lc.setLed(1,0,5,true);delay(x);
  //lc.setLed(1,0,5,false);delay(x);
  clear_all(50);
  
  
  
}




void a_1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,a[i]);
    delay(100);
  }
}

void clear_all(int interval)
{
  lc.clearDisplay(0); 
  lc.clearDisplay(1);
  lc.clearDisplay(2);  
  lc.clearDisplay(3);
  delay(interval);
}

