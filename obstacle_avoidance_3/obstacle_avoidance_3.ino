 #include <Servo.h>
Servo h_servo,v_servo;//horizontal servo on 10

//Ultrasonic Pins
const int trigPin = 12;
const int echoPin = 8;



int temp,temp1,pos,i,obj,crazy=0;
const long interval = 1000;
unsigned long previousMillis = 0; 
unsigned long currentMillis=0; 
bool flag=false;
//int pos=0;

//Motor Pins lm1 stands for left motor 1 and accordingly
int lm2=3;
int lm1=5;
int rm1=6;
int rm2=9;


long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);

  h_servo.attach(10);
  v_servo.attach(11);
  h_servo.write(45); 

  
  Serial.begin(9600); 
}

void loop() 
{
  ultrasonic();
  if(distance<=14)
  {
     stop1(500); 
     reverse(100);
     stop1(1);
    start_servo();
    Serial.println("First condition");
  }
  else //if(distance>=5)
  {
    forward();
    delay(1);
    stop1(1);
    Serial.println("else condition");
  }
  //delay(100);

}

void start_servo()
{
  Serial.println("Entered servo");
  ultrasonic();
   for (pos = 45; pos <= 105; pos += 1) 
    {    
      h_servo.write(pos);             
      delay(45);                       
    }
    
    ultrasonic();
    if(distance>=14)
    {
      left_turn();
      delay(225);
      h_servo.write(45);
      stop1(25);
      Serial.println("Left turn"); 
    }
    else
    {
      for (pos = 90; pos >= 0; pos -= 1) 
    {    
      h_servo.write(pos);             
      delay(75);                       
    }
      ultrasonic();
      if(distance>=14)
    {
      right_turn();
      delay(225);
      h_servo.write(45);
      stop1(25);
    }
    else
    {
    reverse(1000);
    //delay(1000);//Making a Turn Over
    h_servo.write(45);
    
    }
      
    }
    
    
    
    Serial.println("Rotating horizontal servo");            
      ultrasonic();      
  }
  
  

void forward()
{
  ultrasonic();
  if (distance>=14)
  {
  analogWrite(lm1,129);
  analogWrite(rm1,119);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  //delay(1);
  delay(1);
  
  
  Serial.println("Straight");
  }
}
void reverse(int interval)
{
  analogWrite(lm2,255);
  analogWrite(rm2,255);
  digitalWrite(rm1,LOW);
  digitalWrite(lm1,LOW);
  delay(interval);
}
void right_turn()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(rm2,HIGH);
  digitalWrite(rm1,LOW);
  digitalWrite(lm2,LOW);
  delay(1);
  /*analogWrite(lm1,0);
  analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  delay(1);*/
  
  Serial.println("Right turn");
}

void left_turn()
{
  digitalWrite(rm1,HIGH);
  digitalWrite(lm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,LOW);
  delay(1);
 /* analogWrite(lm1,0);
  analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  delay(1);*/
  Serial.println("Left turn");
}

void stop1(int interval)
{
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(lm2,LOW);
  delay(interval);
  Serial.println("Stopped");
}


void ultrasonic()
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
distance = (duration/2) / 29.1;
/*
Serial.print("Distance=");
Serial.println(distance);*/

}
