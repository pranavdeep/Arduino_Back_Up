#define LED 2
unsigned long previousMillis = 0;        // will store last time LED was updated
unsigned int IR_State=3;
unsigned int ReadShaft=0;
const long interval = 60000;           // interval at which to blink (milliseconds)
static unsigned int AnemometerCount=0;
float windSpeed=0;
int statusLED=0;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);  
}

void loop() {
  ReadShaft = digitalRead(IR_State);
  if(ReadShaft==1){
    AnemometerCount++;
  }
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // save the last time you blinked the LED
    ReadSpeed();
    digitalWrite(LED,!statusLED);
    AnemometerCount = 0;
   }// interval
}

void ReadSpeed(void){
  if(AnemometerCount>0 && AnemometerCount<=50){
      if(AnemometerCount=10){ windSpeed = 1.60; }
      else if(AnemometerCount>10 && AnemometerCount<=20){ windSpeed  = 3.21; }
      else if(AnemometerCount>20 && AnemometerCount<=30){ windSpeed  = 4.82; }
      else if(AnemometerCount>30 && AnemometerCount<=40){ windSpeed  = 6.43; }
      else if(AnemometerCount>40 && AnemometerCount<=50){ windSpeed  = 8.04; } 
      Serial.println("Calm");
   }
   else if(AnemometerCount>50 && AnemometerCount<=200){
      if(AnemometerCount<=50){ windSpeed = 1.60; }
      else if(AnemometerCount>50 && AnemometerCount<=60){ windSpeed  = 9.65; }
      else if(AnemometerCount>60 && AnemometerCount<=70){ windSpeed  = 11.26; }
      else if(AnemometerCount>70 && AnemometerCount<=80){ windSpeed  = 12.87; }
      else if(AnemometerCount>80 && AnemometerCount<=90){ windSpeed  = 14.48; } 
      else if(AnemometerCount>90 && AnemometerCount<=100){ windSpeed  = 16.09; }
      else if(AnemometerCount>100 && AnemometerCount<=110){ windSpeed  = 14.70; }
      else if(AnemometerCount>110 && AnemometerCount<=120){ windSpeed  = 19.31; }
      else if(AnemometerCount>120 && AnemometerCount<=130){ windSpeed  = 20.92; } 
      else if(AnemometerCount>130 && AnemometerCount<=140){ windSpeed  = 22.53; }
      else if(AnemometerCount>140 && AnemometerCount<=150){ windSpeed  = 24.14; }
      else if(AnemometerCount>150 && AnemometerCount<=160){ windSpeed  = 25.74; }
      else if(AnemometerCount>160 && AnemometerCount<=170){ windSpeed  = 27.35; } 
      else if(AnemometerCount>170 && AnemometerCount<=180){ windSpeed  = 28.96; }
      else if(AnemometerCount>180 && AnemometerCount<=190){ windSpeed  = 30.57; }
      else if(AnemometerCount>190 && AnemometerCount<=200){ windSpeed  = 32.18; }      
      Serial.println("Light");
   }
  /* else if(AnemometerCount>200 && AnemometerCount<=390){
      if(AnemometerCount<=210){ windSpeed = 1.60; }
      else if(AnemometerCount>100 && AnemometerCount<=110){ windSpeed  = 14.70; }
      else if(AnemometerCount>110 && AnemometerCount<=120){ windSpeed  = 19.31; }
      else if(AnemometerCount>120 && AnemometerCount<=130){ windSpeed  = 20.92; } 
      else if(AnemometerCount>130 && AnemometerCount<=140){ windSpeed  = 22.53; }
      else if(AnemometerCount>140 && AnemometerCount<=150){ windSpeed  = 24.14; }
      else if(AnemometerCount>150 && AnemometerCount<=160){ windSpeed  = 25.74; }
      else if(AnemometerCount>160 && AnemometerCount<=170){ windSpeed  = 27.35; } 
      else if(AnemometerCount>170 && AnemometerCount<=180){ windSpeed  = 28.96; }
      else if(AnemometerCount>180 && AnemometerCount<=190){ windSpeed  = 30.57; }
      else if(AnemometerCount>190 && AnemometerCount<=200){ windSpeed  = 32.18; }      
      else if(AnemometerCount>100 && AnemometerCount<=110){ windSpeed  = 14.70; }
      else if(AnemometerCount>110 && AnemometerCount<=120){ windSpeed  = 19.31; }
      else if(AnemometerCount>120 && AnemometerCount<=130){ windSpeed  = 20.92; } 
      else if(AnemometerCount>130 && AnemometerCount<=140){ windSpeed  = 22.53; }
      else if(AnemometerCount>140 && AnemometerCount<=150){ windSpeed  = 24.14; }
      else if(AnemometerCount>150 && AnemometerCount<=160){ windSpeed  = 25.74; }
      else if(AnemometerCount>160 && AnemometerCount<=170){ windSpeed  = 27.35; } 
      else if(AnemometerCount>170 && AnemometerCount<=180){ windSpeed  = 28.96; }
      else if(AnemometerCount>180 && AnemometerCount<=190){ windSpeed  = 30.57; }
      else if(AnemometerCount>190 && AnemometerCount<=200){ windSpeed  = 32.18; }      
      else if(AnemometerCount>100 && AnemometerCount<=110){ windSpeed  = 14.70; }
      else if(AnemometerCount>110 && AnemometerCount<=120){ windSpeed  = 19.31; }
      else if(AnemometerCount>120 && AnemometerCount<=130){ windSpeed  = 20.92; } 
      else if(AnemometerCount>130 && AnemometerCount<=140){ windSpeed  = 22.53; }
      else if(AnemometerCount>140 && AnemometerCount<=150){ windSpeed  = 24.14; }
      else if(AnemometerCount>150 && AnemometerCount<=160){ windSpeed  = 25.74; }
      else if(AnemometerCount>160 && AnemometerCount<=170){ windSpeed  = 27.35; } 
      else if(AnemometerCount>170 && AnemometerCount<=180){ windSpeed  = 28.96; }
      else if(AnemometerCount>180 && AnemometerCount<=190){ windSpeed  = 30.57; }
      else if(AnemometerCount>190 && AnemometerCount<=200){ windSpeed  = 32.18; }      
      Serial.println("Calm");
  }*/
}

