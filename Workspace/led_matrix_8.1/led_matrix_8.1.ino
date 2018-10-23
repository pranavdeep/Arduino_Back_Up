#include "LedControl.h"
LedControl lc=LedControl(2,5,3,4); 

int delayTime = 0.001;
//int charBreak = 2.1;
int charBreak = 0.001;
int t=10;
int q[] = {31, 20, 22, 9, 0};
int s[] = {8, 21, 21, 2, 0};
int a[] = {16, 16, 31, 16, 16};
int u[] = {30, 1, 1, 30, 0};

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
displayString("squa");
}

void displayLine(int line){
int myline;
myline = line;
if (myline>=16) {lc.setLed(1,4,2,true); myline-=16;} else {lc.setLed(1,4,2,false);}
if (myline>=8)  {lc.setLed(1,4,3,true); myline-=8;}  else {lc.setLed(1,4,3,false);}
if (myline>=4)  {lc.setLed(1,4,4,true); myline-=4;}  else {lc.setLed(1,4,4,false);}
if (myline>=2)  {lc.setLed(1,4,5,true); myline-=2;}  else {lc.setLed(1,4,5,false);}
if (myline>=1)  {lc.setLed(1,4,6,true); myline-=1;}  else {lc.setLed(1,4,6,false);}
}

void displayChar(char c)
{
  if (c == 's'){for (int i = 0; i <5; i++){displayLine(s[i]);delay(delayTime);}displayLine(0);}
if (c == 'q'){for (int i = 0; i <5; i++){displayLine(q[i]);delay(delayTime);}displayLine(0);}
if (c == 'u'){for (int i = 0; i <5; i++){displayLine(u[i]);delay(delayTime);}displayLine(0);}
if (c == 'a'){for (int i = 0; i <5; i++){displayLine(a[i]);delay(delayTime);}displayLine(0);}
}

void displayString(char* s1)
{
for (int i = 0; i<=strlen(s1); i++)
{
displayChar(s[i]);
}
  }

void clear_all(int interval)
{
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);  // Clear Displays
  lc.clearDisplay(3);
  delay(interval);
}
