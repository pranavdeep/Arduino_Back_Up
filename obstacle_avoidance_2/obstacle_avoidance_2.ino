#include <Servo.h>
Servo h_servo,v_servo;//horizontal servo on 10

//Ultrasonic Pins
const int trigPin = 12;
const int echoPin = 8;



int temp,temp1,pos_1,i,obj,crazy=0;
const long interval = 1000;
unsigned long previousMillis = 0; 
unsigned long currentMillis=0; 
bool flag=false;


//Motor Pins lm1 stands for left motor 1 and accordingly
int lm1=3;
int lm2=5;
int rm2=6;
int rm1=11;


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
  //v_servo.attach(11);
  h_servo.write(45); 

  
  Serial.begin(9600); 
}

void loop() 
{
  ultrasonic();
  if(distance<=14)
  {
     stop1(500); 
     reverse(180);
     stop1(5);
    start_servo();
    Serial.println("First condition");
  }
  else //if(distance>=5)
  {
    forward();
    delay(1);
    //stop1(1);
    Serial.println("else condition");
  }
  //delay(100);

}

void start_servo()
{
  
  //ultrasonic();
   for (pos_1=45; pos_1 <= 105; pos_1 += 1) 
    {    
      h_servo.write(pos_1);   Serial.println("Entered servo");          
      delay(45);                       
    }
    
    ultrasonic();
    if(distance>=14)
    {
      servo_look_straight();
      left_turn(225);
      
      stop1(25);
      Serial.println("Left turn"); 
    }
    else
    {
      for (pos_1 = 105; pos_1 >= 0; pos_1 -= 1) 
    {    
      h_servo.write(pos_1);             
      delay(75);                       
    }
      ultrasonic();
      if(distance>=14)
    {
      right_turn(150);//changing from 225 to 150
     servo_look_straight();
      stop1(55);
    }
    else
    {
    reverse(500);
    //delay(1000);//Making a Turn Over
    servo_look_straight();
    
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
  analogWrite(lm1,90);
  analogWrite(rm1,105);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  //delay(1);
  delay(1);
  
  
  Serial.println("Straight");
  }
}
void reverse(int interval)
{
  analogWrite(lm2,155);
  analogWrite(rm2,155);
  analogWrite(rm1,0);
  digitalWrite(lm1,LOW);
  delay(interval);
}
void right_turn(int interval)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(rm2,HIGH);
  analogWrite(rm1,0);
  digitalWrite(lm2,LOW);
  delay(interval);
  /*analogWrite(lm1,0);
  analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  delay(1);*/
  
  Serial.println("Right turn");
}

void left_turn(int interval)
{
  analogWrite(rm1,125);
  analogWrite(lm2,125);
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,LOW);
  delay(interval);
  Serial.println("Left turn");
}

void stop1(int interval)
{
  digitalWrite(lm1,LOW);
  digitalWrite(rm2,LOW);
  analogWrite(rm1,0);
  digitalWrite(lm2,LOW);
  delay(interval);
  Serial.println("Stopped");
}


 
void servo_look_straight()
{
  if(pos_1<=45)
  {
    for (; pos_1 <= 45; pos_1 += 1) 
    {    
      h_servo.write(pos_1);            
      delay(15);                       
    }
  }
  else
  {
    for (; pos_1 >= 45; pos_1 -= 1)
    { 
    h_servo.write(pos_1);              
    delay(15);
  }
}
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
