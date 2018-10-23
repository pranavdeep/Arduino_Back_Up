#include "LedControl.h"
LedControl lc=LedControl(10,12,11,1);  // Pins: DIN,CLK,CS, # of Display connected
unsigned long delayTime=200;  // Delay between Frames
byte data = 0;            //Variable for storing received data from bluetooth

/*Emojis defining*/

byte face[] = {B00111100,B01000010,B10000001,B10000001,B10000001,B10000001,B01000010,B00111100};
//byte happy[] = {B00000000,B00000000,B00100100,B00000000,B00100100,B00011000,B00000000,B00000000};
byte confused[] = {B00111100,B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
//byte heart[] = {B00000000,B01000010,B10100101,B00011000,B10000001,B01000010,B00100100,B00011000};
//imp byte heart[] = {B00000000,B00000000,B01000010,B10100101,B10011001,B01000010,B00100100,B00011000};
//imp 2byte heart[] = {B00000000,B01100110,B10011001,B00000000,B10000001,B01000010,B00100100,B00011000};
byte heart[] = {B00000000,B01100110,B10011001,B10000001,B10000001,B01000010,B00100100,B00011000};
byte sad[] = {B00000000,B00000000,B00100100,B00000000,B00011000,B00100100,B01000010,B00000000};
byte happy[] = {B00000000,B00000000,B01101010,B00000100,B00000000,B01000010,B00100100,B00011000};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //Sets the baud for serial data transmission
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  pinMode(LED_BUILTIN, OUTPUT);  //Sets digital pin 13 as output pin


}

void loop()
{
  
 if(Serial.available() > 0)      // Send data only when you receive data:
   {
        Serial.println("Connected");
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == 1)              // Checks whether value of data is equal to 1
      {
         digitalWrite(LED_BUILTIN, HIGH);   //If value is 1 then LED turns ON
         Serial.println("xyz");
         face1();
         delay(1);
         happy1();
         delay(1000);
      }
      else if(data == 3)         //  Checks whether value of data is equal to 0
      {
         digitalWrite(LED_BUILTIN, HIGH);    //If value is 0 then LED turns OFF
         confused1();
      }

      else if(data == 2)         //  Checks whether value of data is equal to 0
      {
         digitalWrite(LED_BUILTIN, HIGH);    //If value is 0 then LED turns OFF
         
         sad1();
      }

      else if(data == 4)         //  Checks whether value of data is equal to 0
      {
         digitalWrite(LED_BUILTIN, HIGH);    //If value is 0 then LED turns OFF
         heart1();
      }
   }
//face1();
}

void heart1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(1,i,heart[i]);
    delay(100);
  }
}




void sad1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,sad[i]);
    delay(100);
  }
}




void confused1()
{
  
  for (int i = 0; i < 8; i++)
  {
    //Serial.println("0");
    lc.setRow(0,i,confused[i]);
    delay(100);
  }
}
  void happy1()
{
  //face1();
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,happy[i]);
    lc.setIntensity(0,5);
    //Serial.println("1");

    //delay(100);
  }
  //lc.clearDisplay(0); 
}



void face1()
{
  
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,face[i]);
    lc.setIntensity(0,3);
    //delay(100);
  }
  
}
