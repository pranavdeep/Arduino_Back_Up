#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);

void setup(){
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(1000);
}


void loop(){
  if (Serial.available()>0)
   switch(Serial.read()){
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  
  mySerial.println("AT+CMGS=\"+919866655322\"\r"); // 
  delay(1000);
  mySerial.println(" Sending SMS from GSM Module");// The SMS text you want to send
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
 