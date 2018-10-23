#include "LedControl.h"

//LedControl lc=LedControl(10,12,11,4);  // Pins: DIN,CLK,CS, # of Display connected
LedControl lc=LedControl(2,5,3,4);
unsigned long delayTime=200;  
int i=7,j=0,x=0,y=3,temp=0;
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
  Serial.begin(9600);
}

void loop() 
{
 
  if(temp==0)
  {
 up();
 temp=1;
  }
  
 //clear_all(250);
 
 else if(temp==1)
 {
 down();
 temp=0;
 }
 
//up();

//down();
}
 




void up()
{
  while(j<4)
  {
  while (i>=0)
{  
    lc.setLed(j,3,i,true);
    delay(5);
    lc.clearDisplay(j);
    delay(5);
 

 i--;
}
 Serial.println(j);
  j++;
  i=7;
  }
  
  
  if(j>=4)
  j=0;
/*
i=7;

if(j<4)
j++;

else
return;
//j=0;
*/
  }


void down()
{
while(y>=0)
  {

while (x<=7)
{  
  lc.setLed(y,3,x,true);
   delay(5);
   lc.clearDisplay(y);
   delay(5);
 
 x++;
}
y--;
x=0;
  }


if(y<=0)
y=3;
}
/*
else
return;
//y=3;



}

void clear_all(int interval)
{
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
  delay(interval);
}
*/
