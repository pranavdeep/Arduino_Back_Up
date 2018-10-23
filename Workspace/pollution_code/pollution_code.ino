#include "MQ135.h"
#include "ESP8266WiFi.h"
//SoftwareSerial esp8266(9,10); // This makes pin 9 of Arduino as RX pin and pin 10 of Arduino as the TX pin
const int sensorPin= D0;
int air_quality;
const char* ssid = "J-JUB2";
const char* password = "jntu12345";
// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() 
{
  Serial.begin(115200);
  delay(10);

  // prepare GPIO2
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
  // Connect to WiFi network
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
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());



pinMode(8, OUTPUT);
//esp8266.begin(115200); // your esp's baud rate might be different
pinMode(sensorPin, INPUT);        //Gas sensor will be an input to the arduino

}
void loop() 
{
 WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
MQ135 gasSensor = MQ135(A0);
float air_quality = gasSensor.getPPM();
  WiFiClient client = server.available();

 if (client)  // check if the esp is sending a message 
  {
        Serial.println("new client");           // print a message out the serial port

   while (client.connected()) 
   {            // loop while the client's connected
      if (client.available()) 
      {   
     delay(1000);
     
     //int connectionId = esp8266.read()-48; /* We are subtracting 48 from the output because the read() function returns the ASCII decimal value and the first decimal number which is 0 starts at 48*/ 
     // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
             client.println("Content-type:text/html");
             client.println("<html>"); // Start of HTML
             client.println("<head>");
             client.println("<h1>IOT Air Pollution Monitoring System</h1>");
            client.println("<meta http-equiv='refresh' content='1' />");  // Refresh webpage every 3 seconds
            client.println("</head>");
            client.println("<body style = 'background-color: black'>");      
            client.print("<p style = 'color: #FFDF00;'><strong style='font-size: large;'>&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp Air Quality = ");
            client.print(air_quality);
            client.print("&nbsp</span></strong></p>");

     
       client.println(" PPM");
       wclient.println("<p>";
     if (air_quality<=1000)
{
  webpage+= "Fresh Air";
}
else if(air_quality<=2000 && air_quality>=1000)
{
  client.println("Poor Air");
}

else if (air_quality>=2000 )
{
 client.println("Danger! Move to Fresh Air");
}

 client.println("</h2></p></body>"); 
 }
  }
}

