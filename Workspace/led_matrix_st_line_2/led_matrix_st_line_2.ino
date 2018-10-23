  #include "LedControl.h"

LedControl lc=LedControl(10,12,11,4);  // Pins: DIN,CLK,CS, # of Display connected
//LedControl lc=LedControl(2,5,3,4);

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
  
}
void loop() 
{
  up();
  //delay(700);
  clear_all();
  //delay(700);
  down();
}

void up()
{
   i=7;j=0;
while (i>=0)
{  
  lc.setLed(j,3,i,true);
   delay(100);
   lc.clearDisplay(j);
   delay(100);
 
 i--;
}
i=7;
if(j<4)
j++;
else
j=0;
}

void down()
{
   i=0;j=3;
while (i<=7)
{  
  lc.setLed(j,3,i,true);
   delay(100);
   lc.clearDisplay(j);
   delay(100);
 
 i++;
}
i=0;
if(j>=0)
j--;
else
j=3;
}

void clear_all()
{
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
  delay(500);
}




