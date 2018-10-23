#include "LedControl.h"

LedControl lc=LedControl(10,12,11,4);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames



byte face[] = {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
byte happy[] = {B00000000,B00000000,B00100100,B00000000,B00100100,B00011000,B00000000,B00000000};byte happy_trial[] = {B00000000,B00000000,B00100100,B00000000,B01000010,B00100100,B00011000,B00000000};
byte blank[] = {B00000000,B00000000,B00100100,B00000000,B00000000,B11111111,B00000000,B00000000};
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


//  Take values in Arrays and Display them






void face1()
{
  
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(1,i,face[i]);
    lc.setIntensity(0,3);
    //delay(100);
  }
  
}

void happy1()
{
  //face1();
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,happy[i]);
    lc.setIntensity(0,5);
    //delay(100);
  }
  //lc.clearDisplay(0); 
}
void blank1()
{
  
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(3,i,blank[i]);
    //delay(100);
  }
  //lc.clearDisplay(0); 
}

void happy12()
{
  face1();
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(2,i,happy_trial[i]);
    //delay(100);
  }
}
void loop()
{
     
     face1();
     //delay(1000);
     happy1();
     //delay(1000);
     happy12();
     //delay(1000);
     blank1();
     //delay(1000);
     
   
    
  }
     
    /*test1();
    delay(1500);
    p1();
   delay(1500);*/

