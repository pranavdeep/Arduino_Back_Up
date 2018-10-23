#include <Servo.h>
Servo h_servo,v_servo;//horizontal servo on 10

//Ultrasonic Pins
const int trigPin = 12;
const int echoPin = 8;

const int trigPin_1 = A1;
const int echoPin_1 = A0;

const int trigPin_2 = A3;
const int echoPin_2 = A2;



int temp,temp1,pos_1,i,obj,crazy=0;
const long interval = 1000;
unsigned long previousMillis = 0; 
unsigned long currentMillis=0; 
bool flag1,flag2=true;


//Motor Pins lm1 stands for left motor 1 and accordingly
int lm1=3;
int lm2=5;
int rm2=6;
int rm1=11;


long duration,duration_1,duration_2;
int distance,distance_1,distance_2;

void setup() 
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(trigPin_1, OUTPUT); 
  pinMode(echoPin_1, INPUT);
  pinMode(trigPin_2, OUTPUT); 
  pinMode(echoPin_2, INPUT);
  
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);

  h_servo.attach(10);
  //v_servo.attach(11);
  h_servo.write(45); 

  
  Serial.begin(9600); 
}
void(* resetFunc) (void) = 0;
void loop() 
{
  
  ultrasonic_1();
  ultrasonic_2();
  if( (flag1==true) && (flag2==true) )
  {
    ultrasonic();
  if(distance<=14)
  {
     stop1(300); 
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
else if( (flag1==true) && (flag2==false) )
{
  stop1(100);
  right_turn(500);//changing from 50 to 45
  stop1(10);
  
}
else if( (flag2==true) && (flag1==false) )
{
  stop1(100);
  left_turn(450);//changing from 225 to 150
  stop1(10);
}
else
{
stop1(500);
reverse(250);
Serial.println("Check");
return;
}
}

void start_servo()
{
  
  //ultrasonic();
   for (pos_1=45; pos_1 <= 95; pos_1 += 1) 
    {    
      h_servo.write(pos_1);   Serial.println("Entered servo");          
      delay(45);                       
    }
    
    ultrasonic();
    if(distance>=14)
    {
      servo_look_straight();
      left_turn(150);//changing from 225 to 150
      
      stop1(25);
      Serial.println("Left turn"); 
    }
    else
    {
      for (pos_1 = 95; pos_1 >= 0; pos_1 -= 1) 
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
    reverse(180);//changing from 250 to 180
    //delay(1000);//Making a Turn Over
    servo_look_straight();
    
    }
      
    }
    
    
    
    Serial.println("Rotating horizontal servo");            
      ultrasonic();      
  }
  
  
void forward()
{
  ultrasonic_1();
  ultrasonic_2();
  if( (flag1==true) && (flag2==true) )
  {
  ultrasonic();
   if (distance>=14)
  {
  analogWrite(lm1,75);
  analogWrite(rm1,90);
  digitalWrite(rm2,LOW);
  digitalWrite(lm2,LOW);
  //delay(1);
  delay(1);
  
  
  Serial.println("Straight");
  }
}
else
{
  stop1(25);
return;
}
}
void reverse(int interval)
{
  analogWrite(lm2,80);
  analogWrite(rm2,80);
  analogWrite(rm1,0);
  digitalWrite(lm1,LOW);
  delay(interval);

  Serial.println("Reverse");
}
void right_turn(int interval)
{
  
  analogWrite(rm2,105);
  analogWrite(lm1,105);
  analogWrite(rm1,0);
  digitalWrite(lm2,LOW);
  delay(interval);
  
  Serial.println("Right turn");
}

void left_turn(int interval)
{
  analogWrite(rm1,105);
  analogWrite(lm2,105);
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



void ultrasonic_1()
{
analogWrite(trigPin_1, 0);
//delayMicroseconds(25);
analogWrite(trigPin_1, 255);
//delayMicroseconds(25);
analogWrite(trigPin_1, 0);
duration_1 = pulseIn(echoPin_1, HIGH);
distance_1= duration_1*0.034/2;

Serial.print("distance_1: ");
Serial.println(distance_1);
if(distance_1>=12)
{
flag1=false;
}
else 
{
flag1=true;
}
Serial.println(flag1);
}


void ultrasonic_2()
{
analogWrite(trigPin_2, 0);
//delayMicroseconds(25);
analogWrite(trigPin_2, 255);
//delayMicroseconds(25);
analogWrite(trigPin_2, 0);
duration_2 = pulseIn(echoPin_2, HIGH);
//distance_2= duration_2*0.034/2;
distance_2 = (duration_2/2) / 29.1;

if(distance_2 >=12)
{
flag2=false;

}
else 
{
flag2=true;
}

Serial.print("distance_2: ");
Serial.println(distance_2);
}


void ultrasonic()
{
digitalWrite(trigPin, LOW);
//delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
//delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
distance = (duration/2) / 29.1;
if( (distance==0) || (distance>2000) )
{
  ultrasonic();
}

Serial.print("Distance=");
Serial.println(distance);

}
