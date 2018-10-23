
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
byte anger[] = {B11000011,B01100110,B00100100,B00000000,B10000001,B01000010,B00100100,B00011000};//evil
byte evil[] = {B11000011,B01100110,B00100100,B00000000,B00000000,B00111100,B01000010,B00000000};//anger
byte frowned[] = {B00000000,B11100111,B00000000,B00000000,B00000000,B01111110,B00000000,B00000000};//frowned
byte swag[] = {B00010001,B00010001,B10010001,B01011111,B00111111,B00011111,B00011111,B00000000};//swag
byte happy[] = {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};



void setup() 
{
  // put your setup code here, to run once:
  
  
  Serial.begin(9600);   //Sets the baud for serial data transmission
  lc.shutdown(0,false);  // Wake up displays
  lc.shutdown(1,false);
  lc.setIntensity(0,5);  // Set intensity levels
  lc.setIntensity(1,5);
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  pinMode(LED_BUILTIN, OUTPUT);  


}

void loop()
{
  
 if(Serial.available() > 0)      
   {
        Serial.println("Bluetooth Device Connected");
      data = Serial.read();        
      Serial.print(data);          
      Serial.print("\n");        
      if(data == 1)              
      {
         //digitalWrite(LED_BUILTIN, HIGH);   
         //Serial.println("xyz");
         //face1();
         //delay(1);
         happy1();
         //delay(1000);
      }
      else if(data == 3)         
      {
         digitalWrite(LED_BUILTIN, HIGH);    
         confused1();
      }

      else if(data == 2)         
      {
         digitalWrite(LED_BUILTIN, HIGH);    
         
         sad1();
      }

      else if(data == 4)         
      {
         digitalWrite(LED_BUILTIN, HIGH);    
         
         heart1();
      }
       else if(data == 5)         
      {//anger
         digitalWrite(LED_BUILTIN, HIGH);    
         anger1();
        
      }
      else if(data == 6)         
      {//evil
         digitalWrite(LED_BUILTIN, HIGH);    
         evil1();
      }
      else if(data == 7)         
      {//frowned
         digitalWrite(LED_BUILTIN, HIGH);    
         frowned1();
      }
      else if(data == 8)         
      {//swag
         digitalWrite(LED_BUILTIN, HIGH);    
         swag1();
      }
   }
   //face1();
}


void evil1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,evil[i]);
    delay(100);
  }
}

void frowned1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,frowned[i]);
    delay(100);
  }
}

void swag1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,swag[i]);
    delay(100);
  }
}

void anger1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,anger[i]);
    delay(100);
  }
}

void heart1()
{
  
  for (int i = 0; i < 8; i++)
  {
    Serial.println("0");
    lc.setRow(0,i,heart[i]);
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
