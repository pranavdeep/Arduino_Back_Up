#include "LedControl.h"

LedControl lc=LedControl(10,12,11,3);

unsigned long delayTime=200; 

byte block[] = { B00111000,B00010000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};

int r1,r2,r3,r4;
int c1,c2,c3,c4;

void setup() {
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  Serial.begin(9600);

}
//setRow(addr,row,value)
void loop() {
  /*for(int i=0;i<8;i++)
  {
lc.setRow(0,i,B00111000);
lc.setRow(0,i+1,B00010000);

delay(1000);
lc.clearDisplay(0);
  }
  
//T move left
for(i=2;i>=0;i++)
{
  */
//void setLed(int addr, int row, int col, boolean state);
if(i==1)
new_t_block();

else
{
  
  delay(5000);
   lc.clearDisplay(0);  // Clear Displays
  left();
   

  
  
  }

void t_block()
{
  lc.setLed(0,r1,c1,HIGH);//L1
  lc.setLed(0,r2,c2,HIGH);//L2
  lc.setLed(0,r3,c3,HIGH);//L3
  lc.setLed(0,r4,c4,HIGH);//L4
}

void new_t_block()
{
     r1=r2=r3=0;
     c1=3;
     c2=c4=4;
     c3=5;
     r4=1;
     t_block();
  
}

void left()
{
  if( (c1<=8)&& (c2<=8)&& (c3<=8)&& (c4<=8) )
  {
    c2--;
    c1--;
    c3--;
    c4--;
  }
  t_block();
  
}




