#include <ESP8266WiFi.h>
 
const char* ssid = "Indrakanti";//Chane here your hostspot id
const char* password = "indrakanti1997";//change here your hotspot password
 


WiFiServer server(80);
WiFiClient client;
 
void setup() {
  Serial.begin(115200);
  delay(10);  
  WiFiConnect(); // Connect to WiFi network
  Serial.println(WiFi.localIP()); // idi NodeMCU IP address.
  delay(1000);
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client){
    Serial.println("Client Not Connected");
    delay(1000);
    return;
  }
  // Wait until the client sends some data
  /*while(client.available()){
    //if client is  connected, buzzer will keep buzzing
    Serial.println("Client Connected");
        delay(1);
  }*/
 // Read the first line of the request
  String request = client.readStringUntil('\r');
  client.flush();
  
  if (request.indexOf("/cmd=left") != -1){ 
   int j=0;
   for(j=0;j<250;j++){
    Serial.println("Left");//left();
    if (request.indexOf("/cmd=stop") != -1){
      Serial.println("Stop");//stop_all();
      break;
     }
   }
  }
  if (request.indexOf("/cmd=right") != -1){   
   int j=0;
   for(j=0;j<250;j++){
    Serial.println("right");//right();
    if (request.indexOf("/cmd=stop") != -1){
      Serial.println("Stop");
      break;
     }
   }
  }  
  if (request.indexOf("/cmd=slowforward") != -1){ 
   int j=0;
   for(j=0;j<100;j++){
    Serial.println("Sf");
    if (request.indexOf("/cmd=stop") != -1){
      Serial.println("Stop");
      break;
     }
   }
  }
  if (request.indexOf("/cmd=slowreverse") != -1){
   int k=0;
   for(k=0;k<100;k++){ 
     Serial.println("Rev");
     if (request.indexOf("/cmd=stop") != -1){
       Serial.println("Stop");
       break;
     }
   }
  } 
  if (request.indexOf("/cmd=radialright") != -1){
   int j=0;
   for(j=0;j<250;j++){
    Serial.println("Rad r");
//    straight();
    if (request.indexOf("/cmd=stop") != -1){
      Serial.println("Stop");
      break;
     }
   }
  }
  if (request.indexOf("/cmd=radialleft") != -1){
   int j=0;
   for(j=0;j<250;j++){
    Serial.println("R l");
    if (request.indexOf("/cmd=stop") != -1){
      Serial.println("Stop");
      break;
     }
   }
  }
  /*if (request.indexOf("/cmd=reverseright") != -1){ 
   int j=0;
   for(j=0;j<125;j++){
    reverseRight();
    if (request.indexOf("/cmd=stop") != -1){
      stop_all();
      break;
     }
   } 
  }
  if (request.indexOf("/cmd=reverseleft") != -1){
   int j=0;
   for(j=0;j<125;j++){
     reverseLeft();
     if (request.indexOf("/cmd=stop") != -1){
      stop_all();
      break;
     }
   }
  } 
  if (request.indexOf("/cmd=stop") != -1){
    stop_all();
  }
  if (request.indexOf("/cmd=UP") != -1){
    digitalWrite(up_motor,HIGH);
    digitalWrite(down_motor,LOW); 
    if (request.indexOf("/cmd=stop") != -1){
      stop_all();
    }
  }
  if (request.indexOf("/cmd=DOWN") != -1){
    digitalWrite(down_motor,HIGH);
    digitalWrite(up_motor,LOW);
    if (request.indexOf("/cmd=stop") != -1){
      stop_all();
    }
  }
  if (request.indexOf("/cmd=OPEN") != -1){
    digitalWrite(open_motor,HIGH);
    digitalWrite(close_motor,HIGH);
    if (request.indexOf("/cmd=stop") != -1){
      stop_all();
    }
  }
  if (request.indexOf("/cmd=CLOSE") != -1){
    digitalWrite(close_motor,HIGH);
    digitalWrite(up_motor,LOW);
    if (request.indexOf("/cmd=stop") != -1){
      stop_all();
    }
  }
  if (request.indexOf("/cmd=frontLeft") != -1){
   int j=0;
   for(j=0;j<125;j++){
    left();
    if (request.indexOf("/cmd=stop") != -1){
      stop_all();
      break;
     }
   }
  }
  if (request.indexOf("/cmd=frontRight") != -1){
    int j=0;
   for(j=0;j<125;j++){
    right();
    if (request.indexOf("/cmd=stop") != -1){
      stop_all();
      break;
     }
   }
  }*/
  
 { // exapand for HTML CODE
  // Return the response0
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css' integrity='sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u' crossorigin='anonymous'>");
  client.println("<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css' integrity='sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp' crossorigin='anonymous'>");
  client.println("<script src='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js' integrity='sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa' crossorigin='anonymous'></script>");
  client.println("</head>");
  client.println("<body>");
  client.println("<div class='container'>");
  client.println("<div class='row'>");
  client.println("<div class='md-col-2'></div>");
  client.println("<div class='md-col-8'>");
  
  client.println("<br><br><center>");
  client.println("<a href=\"/cmd=frontLeft\"\"><button class='btn btn-primary'>FL&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</button>&nbsp;&nbsp&nbsp;&nbsp</a><a href=\"/cmd=slowforward\"\"><button class='btn btn-primary'>Forward&nbsp;&nbsp;</button></a>&nbsp;&nbsp&nbsp;&nbsp<a href=\"/cmd=frontRight\"\"><button class='btn btn-primary'>FR&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</button>&nbsp;&nbsp&nbsp;&nbsp</a>");
  client.println("<hr/>");
  client.println("<a href=\"/cmd=radialleft\"\"><button class='btn btn-primary'>Radial Left</button></a>--------------------<a href=\"/cmd=left\"\"><button class='btn btn-primary'>Left</button></a>------<a href=\"/cmd=stop\"\"><button class='btn btn-primary'>Stop</button></a>------<a href=\"/cmd=right\"\"><button class='btn btn-primary'>Right</button></a>--------------------<a href=\"/cmd=radialright\"\"><button class='btn btn-primary'>Radial Right</button></a>");
  client.println("<hr/>");
  client.println("<a href=\"/cmd=reverseleft\"\"><button class='btn btn-primary'>RL&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</button>&nbsp;&nbsp&nbsp;&nbsp</a><a href=\"/cmd=slowreverse\"\"><button class='btn btn-primary'>Reverse&nbsp;&nbsp;</button>&nbsp;&nbsp;</a>&nbsp;&nbsp&nbsp;&nbsp<a href=\"/cmd=reverseright\"\"><button class='btn btn-primary'>RR&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</button></a>");
  client.println("<hr/>");
  client.println("</center></div>");
  client.println("<hr/>");
  client.println("<br>");
  client.println("<center>");
  client.println("<a href=\"/cmd=UP\"\"><button class='btn btn-primary'>&nbsp;&nbsp;UP &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</button></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
  client.println("<a href=\"/cmd=DOWN\"\"><button class='btn btn-primary'>DOWN &nbsp;&nbsp;</button></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
  client.println("<a href=\"/cmd=OPEN\"\"><button class='btn btn-primary'>OPEN &nbsp;&nbsp;</button></a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;");
  client.println("<a href=\"/cmd=CLOSE\"\"><button class='btn btn-primary'>CLOSE &nbsp;&nbsp;</button></a>");
  client.println("</center>");
  client.println("<br>");
  client.println("<div class='md-col-2'></div>");
  client.println("</div>");
  client.println("</div>");
  client.println("</body>");  
  client.println("</html>");
  delay(1);
 }
}// void loop ends here


void WiFiConnect(void){
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
    //digitalWrite(buzzer,HIGH);
  }
  // Start the server
  server.begin();
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}


