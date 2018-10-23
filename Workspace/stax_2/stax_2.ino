 //improvement of opt 2   trying to provide a left priority for bot
int lm1=9;
int lm2=10;
int rm1=5;
int rm2=6;
int ss1=13;
int ss2=12;
int ss3=11;
int ss4=8;
int ss5=7;
int ss6=4;
int ss7=3;
int ss8=2;
int a,b,c,d,e,f,g,h,dabba;
int led=A0;
int i,j,flag=0;
//char stack[3];


#define trigPin 44
#define echoPin 42
int duration, distance;

//pickup n drop parameters
int elbdrop=9;
int elblift=10;
int gripopen=11;
int gripclose=12;


//colour sensor parameters
#define S0 5
#define S1 6
#define S2 2
#define S3 4
#define sensorOut 7
int rfrequency = 0;
int gfrequency = 0;
int bfrequency = 0;
char stack[3]={};
char stack1[3]={};
char initial[3]={};
void setup()
{
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(ss1,INPUT);
  pinMode(ss2,INPUT);
  pinMode(ss3,INPUT);
  pinMode(ss4,INPUT);
  pinMode(ss5,INPUT);
  pinMode(ss6,INPUT);
  pinMode(ss7,INPUT);
  pinMode(ss8,INPUT);
  pinMode(led,OUTPUT);

  //ultrasonic sensor parameters
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


//colour sensor parameters
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  //pickup n drop parameters
   pinMode(elblift,OUTPUT);
   pinMode(elbdrop,OUTPUT);
   pinMode(gripopen,OUTPUT);
   pinMode(gripclose,OUTPUT);

}
void readsensors(){
  a=digitalRead(ss1);
  b=digitalRead(ss2);
  
  c=digitalRead(ss3);
  
  d=digitalRead(ss4);
  e=digitalRead(ss5);
  
  f=digitalRead(ss6);
  
  g=digitalRead(ss7);
  h=digitalRead(ss8);
}
void loop()
{
  WELCOME :
  readsensors();
if(a==LOW && h==LOW && ( d==HIGH || e==HIGH ))
{
straight();
}

else if(a==HIGH && b==HIGH && d==HIGH && e==HIGH && g==HIGH && h==HIGH)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
   //delay(500);
 if ( ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
    {
            ultrasonic();
             delay(250);
            if (distance<=2)
            {
                digitalWrite(lm1,LOW);
                digitalWrite(lm2,LOW);
                digitalWrite(rm1,LOW);
                digitalWrite(rm2,LOW);
                      delay();
                      sort();
              }
              else
              {
                straight();
              }
    /*digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(200);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {   
      leftturn();

  }*/
  
    }
  else{
    goto WELCOME;
    }
}

else if(a==HIGH && b==HIGH && h==LOW && (e==HIGH || d==HIGH))
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) ){

  ultrasonic();
  if (distance<=12)
  {
  color();
  }
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(200);
  
  leftturn();
  }
  else{
    goto WELCOME;
    }
}

else if(g==HIGH && h==HIGH && a==LOW && (e==HIGH || d==HIGH))
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
      
      if( (digitalRead(ss1)==LOW || digitalRead(ss2)==LOW) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
      {
        ultrasonic();
     if (distance<=12)
     {
      ultrasonic();
     if (distance<=12)
     {
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
        delay(200); 
        rightturn();
           }
     }
  
  else
  {
    digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(200); 
  
   if((digitalRead(ss4)==LOW && digitalRead(ss5)==LOW && digitalRead(ss1)==LOW && digitalRead(ss2)==LOW && digitalRead(ss3)==LOW && digitalRead(ss6)==LOW && digitalRead(ss7)==LOW
  && digitalRead(ss8)==LOW)){
  rightturn();
  }
  else {
    straight();
    }
  }
  }
  else{
    goto WELCOME;
    }
}

else if(a==LOW && b==LOW && c==LOW && d==LOW && e==LOW && f==LOW && g==LOW && h==LOW)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(200);
  turnover();
}





void straight()
{
  ultrasonic();
  delay(200);
if(distance >=5)
{
  if( digitalRead(ss5)==LOW || digitalRead(ss3)==HIGH ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 200);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
  if(digitalRead(ss4)==LOW || digitalRead(ss6)==HIGH ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    analogWrite(lm1, 180);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
 
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(5);
}
else
{
  analogWrite(lm1, 0);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(10);
}
  }

  void leftturn(){
    while(digitalRead(ss1)==LOW)
    {
      analogWrite(lm1, 0);
      analogWrite(lm2, 200);
      analogWrite(rm1, 200);
      analogWrite(rm2, LOW);
      delay(3);
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(1);*/
      }
      while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
      digitalWrite(lm1, LOW);
      analogWrite(lm2, 255);
      analogWrite(rm1, 255);
      digitalWrite(rm2, LOW);
      delay(3);
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
   digitalWrite(rm2, LOW);
      delay(2);*/
      }
      if(digitalRead(ss5)==HIGH){
        digitalWrite(lm1, LOW);
        digitalWrite(lm2, LOW);
        digitalWrite(rm1, LOW);
        digitalWrite(rm2, LOW);
        delay(2);
        }
        
    }

void turnover(){
  while(digitalRead(ss1)==LOW){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }
    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
    digitalWrite(lm1, LOW);
    analogWrite(lm2, 255);
    analogWrite(rm1, 255);
    digitalWrite(rm2, LOW);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }

    if(digitalRead(ss5)==HIGH){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
  }

void rightturn(){
    while(digitalRead(ss8)==LOW){
    analogWrite(lm1, 200);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 200);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }

    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
    analogWrite(lm1, 200);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 200);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }
    if(digitalRead(ss4)==HIGH)
    {
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
  }
  void ultrasonic()
{
    digitalWrite(trigPin, LOW);
delayMicroseconds(25);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  /*if (distance >= 200 || distance <= 0)
  {
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);*/
}
void pickup()
{
  digitalWrite(gripopen,HIGH);
  delay(2000);
  analogWrite(elbdrop,255);
  delay(4000);
  digitalWrite(gripclose,HIGH);
  delay(3000);
  analogWrite(elblift,255);
  delay(4000);
  analogWrite(elblift,0);
  delay(2000);//changed this delay value
}

void drop()
{
  analogWrite(elbdrop,255);
  delay(4000);
  digitalWrite(gripopen,HIGH);
  delay(2000);
  analogWrite(elblift,255);
  delay(4000);
  analogWrite(elblift,0);
  delay(4000);
  digitalWrite(gripclose,HIGH);
  delay(2000);//changed this delay value
}

void color()
  {
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  rfrequency = pulseIn(sensorOut, LOW);
  rfrequency = map(rfrequency, 25,72,255,0);
  rfrequency=rfrequency-(2*rfrequency);
  Serial.print("R= ");
  Serial.print(rfrequency);
  Serial.print("  ");
  delay(1000);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  gfrequency = pulseIn(sensorOut, LOW);
  gfrequency = map(gfrequency, 30,90,255,0);
  gfrequency=gfrequency-(2*gfrequency);
  Serial.print("G= ");
  Serial.print(gfrequency);
  Serial.print("  ");
  delay(1000);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  bfrequency = pulseIn(sensorOut, LOW);
  bfrequency = map(bfrequency,30,90,255,0);
  bfrequency=bfrequency-(2*bfrequency);
  Serial.print("B= ");
  Serial.print(bfrequency);
  Serial.println("  ");
  delay(1000);
  if((rfrequency <6000)&&(rfrequency >3000)&&(rfrequency<gfrequency)&&(rfrequency<bfrequency))
  {
      stack[i]='R';
      digitalWrite(led,HIGH);
      delay(50);
      digitalWrite(led,LOW);
      delay(50);
      i++;
      Serial.println(" - RED detected!");
  }
  if((gfrequency <6000)&&(gfrequency >3000)&&(gfrequency<rfrequency)&&(gfrequency<bfrequency)){
    stack[i]='G';
      i++;
      digitalWrite(led,HIGH);
      delay(2500);
      digitalWrite(led,LOW);
      
    Serial.println(" - GREEN detected!");
  }
  if((bfrequency <6000)&&(bfrequency >3000)&&(bfrequency<gfrequency)&&(bfrequency<rfrequency))
  {
    
  stack[i]='B';
  digitalWrite(led,HIGH);
  delay(1);
  digitalWrite(led,LOW);
    Serial.println(" - BLUE detected!");
  }
  
}
void color_stack()
{
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  rfrequency = pulseIn(sensorOut, LOW);
  rfrequency = map(rfrequency, 25,72,255,0);
  rfrequency=rfrequency-(2*rfrequency);
  Serial.print("R= ");
  Serial.print(rfrequency);
  Serial.print("  ");
  delay(1000);
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  gfrequency = pulseIn(sensorOut, LOW);
  gfrequency = map(gfrequency, 30,90,255,0);
  gfrequency=gfrequency-(2*gfrequency);
  Serial.print("G= ");
  Serial.print(gfrequency);
  Serial.print("  ");
  delay(1000);
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  bfrequency = pulseIn(sensorOut, LOW);
  bfrequency = map(bfrequency,30,90,255,0);
  bfrequency=bfrequency-(2*bfrequency);
  Serial.print("B= ");
  Serial.print(bfrequency);
  Serial.println("  ");
  delay(1000);
  if((rfrequency <6000)&&(rfrequency >3000)&&(rfrequency<gfrequency)&&(rfrequency<bfrequency))
  {
      stack1[j]='R';
      digitalWrite(led,HIGH);
      delay(50);
      digitalWrite(led,LOW);
      delay(50);
      j++;
      Serial.println(" - RED detected!");
  }
  if((gfrequency <6000)&&(gfrequency >3000)&&(gfrequency<rfrequency)&&(gfrequency<bfrequency)){
    stack1[j]='G';
      j++;
      digitalWrite(led,HIGH);
      delay(2500);
      digitalWrite(led,LOW);
      
    Serial.println(" - GREEN detected!");
  }
  if((bfrequency <6000)&&(bfrequency >3000)&&(bfrequency<gfrequency)&&(bfrequency<rfrequency))
  {
    
  stack1[j]='B';
  digitalWrite(led,HIGH);
  delay(1);
  digitalWrite(led,LOW);
    Serial.println(" - BLUE detected!");
    j++;
  }
}
void sort()
{
   color_stack();
    pickup();
    delay(2500);
    if(flag==0)
    {
    reverse();
    }
    readsensors();
   if(a==LOW && h==LOW && ( d==HIGH || e==HIGH ))
{
straight();
}
else if(a==HIGH && b==HIGH && d==HIGH && e==HIGH && g==HIGH && h==HIGH)
{
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
if ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
    {
       if(temp==0)
  {
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
        delay(200); 
        leftturn();
        temp++;
    }
   else if(temp==1)
   {
       straight();
       temp++;
   }
    else if(temp==2)
    {
      
        drop();
        temp++;
        turnover();
      
  }
  else if(temp==3)
  {
    
          straight();
          temp++;

  }
  else if(temp==4)
  {
    
      digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
        delay(200);
        leftturn();
    
    }
else if(temp==5)
{
  ultrasonic();
  while(distance<=2)
  {
    straight();
  }
  pickup();
  delay(100);
  reverse();
  temp++;
}
else if(temp==6)
{
  rightturn();
  temp++;
}
  else if(temp==7)
  {
    straight();
    temp++;
  }
  else if(temp==8)
  {
    drop();
    turnover();
    temp++;
  }
  else if(temp==9)
  {
    rightturn();
    temp++;
  }
  else if(temp==10)
  {
    ultrasonic();
     while(distance<=2)
     {
      straight();
      delay(1);
      temp++;
     }
     colorCheck();
     delay(100);
     /*reverse();*/
     
  }
    }
}
}

  void colorCheck()
  {
     if(stack1[0]==stack[2])
     {
      if(stack1[1]==stack[0]
      {
        reverse();
        delay();
        swap();
        //delay(100);
        
      }
     }
     
    
  }
    void swap()
    {
      if ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
       {
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
        delay(200);
        leftturn();
       }
      linefollow();
        ultrasonic();
        if(distance<=2)
        {
          pickup();      
        }
        turnover();
        delay(100);
        linefollow();
        if ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
       {
        digitalWrite(lm1,HIGH);
        digitalWrite(lm2,LOW);
        digitalWrite(rm1,HIGH);
        digitalWrite(rm2,LOW);
        delay(200);
        leftturn();
       }
       linefollow();
    if ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
    {
      straight();
    }
   
    }

    }
    
    
    
    
    
  

