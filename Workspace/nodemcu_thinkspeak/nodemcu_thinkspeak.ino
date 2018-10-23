#include "Wire.h"
#include <ESP8266WiFi.h>
String apiKey="21IN9SWE46KNABF6";
#define LED D1
#define LED2 D2
 
//int D1,D2;
const char* ssid     = "sastry";
const char* password = "cheerful";
const char* server = "api.thingspeak.com";
//const char* host = "api.devicehub.net";//api.devicehub.net
int gasSensor=0,air_quality=0;//initialise the value you are going to read
//String pubString1,pubString2;

WiFiClient client;

void setup()
{
     Serial.begin(115200); /* begin serial for debug */
          Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
          delay(100);
          
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

WiFi.begin(ssid, password);


while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address of NODEMCU= ");
  Serial.println(WiFi.localIP()); // idi NodeMCU IP address.



 // void post(); // this is just defining the function
/*
  //String apiKey = "Your API of thingsspeak";     //  Enter your Write API key from ThingSpeak
//const char* server = "api.thingspeak.com";
  Serial.println("Connecting to ");
       Serial.println(ssid);
       WiFi.begin(ssid,pass);
       while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");*/
 
}

void loop()
{
   
  //Wire.beginTransmission(8); /* begin with device address 8 */
 /*Wire.write("Hello Arduino");  /* sends hello s tring */
  //  Wire.write(gasSensors);  /* sends hello s tring */
  // Wire.write(air_quality);  /* sends hello s tring */
   // Wire.endTransmission();   /* stop transmitting */

  Wire.requestFrom(8, 13); /* request & read data of size 13 from slave */
  while(Wire.available())
  {
   gasSensor = Wire.read();
   gasSensor=gasSensor-48;
    Serial.print("Gas Sensors=");
    Serial.println(gasSensor);
   air_quality= Wire.read();
   air_quality=air_quality-48;
    Serial.print("Air QUALity=");
    Serial.println(air_quality);
 if (client.connect(server,80)){   //   "184.106.153.149" or api.thingspeak.com                      {  
                            
                             String postStr =apiKey;
                             postStr +="&field1=";
                             postStr += String(air_quality);
                             postStr +="&field2=";
                             postStr += String(gasSensor);
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             /*Serial.print("Air Quality ");
                             Serial.print(air_quality);
                             Serial.print(" gasSensor ");
                             Serial.print(gasSensor);*/
                             Serial.println(" Send to Thingspeak.");
                        }
          client.stop();
 
      }
  Serial.println();
  delay(1000);
}    


/*void Post(void)
{
  //this function shall post data from device to the cloud
  delay(1000);
  Serial.print("connecting to ");
  Serial.println(host);



  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  pubString1= "{\"value\": " + String(air_quality) + "}";
  String pubString1Length = String(pubString1.length(), DEC);
   pubString2= "{\"value\": " + String(gasSensor) + "}";
  String pubString2Length = String(pubString2.length(), DEC);
  
  // We now create a URI for the request
  Serial.print("Requesting POST: ");
  // Send request to the server:
  client.println("POST /v2/project/14397/device/f379e489-14af-4187-96e0-f7eca937f5e3/sensor/dustSensor/data HTTP/1.1");
  // Note: replace the ALL CAPS parts above with info from DeviceHub.net. After setting up an account,
  // add a project, a device (NodeMCU), a sensor (like pH_Sensor), and actuator if you need. After you set
  // up the project it should show you an API key, device UUID, and of course the sensor name you entered.
  client.println("Host: api.devicehub.net");
  client.print("X-ApiKey: dac0bead-10b4-4b04-8b10-8d3c0e7593e0\r\n"); // Get this from DeviceHub.net
  client.println("Content-Type: application/json");
  client.println("Connection: close");
  client.print("Content1-Length: ");
  client.println(pubString1Length);
  client.print("Content2-Length: ");
  client.println(pubString2Length);
  client.println();
  client.print(pubString2);
  client.println();
  delay(500); // Can be changed



  // Read all the lines of the reply from server and print them to Serial Monitor
  while (client.available()) 
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  Serial.println();
  Serial.println("closing connection");

}*/
















  

