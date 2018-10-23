int lm1=10;
int lm2=9;
int rm1=6;
int rm2=5;


int ss1=13;
int ss2=12;
int ss3=11;
int ss4=8;
int ss5=7;
int ss6=4;
int ss7=3;
int ss8=2;


int a,b,c,d,e,f,g,h;
int flag=0, temp=0;
int led=A0;




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
  
  
  
  //pinMode(dobba,INPUT);
  //pinMode(led,OUTPUT);
  
  Serial.begin(9600);
  
}

void readsensors()
{
  a=digitalRead(ss1);
  b=digitalRead(ss2);
  c=digitalRead(ss3);
  d=digitalRead(ss4);
  e=digitalRead(ss5);
  f=digitalRead(ss6);
  g=digitalRead(ss7);
  h=digitalRead(ss8);

  //dabba=digitalRead(dobba);
}

void loop() 
{
   WELCOME :
  readsensors();
  if(a==HIGH && h==HIGH && ( d==LOW || e==LOW ))
    {
       straight();
       Serial.print("flag=");
       Serial.println(flag);
      //delay(2000);
    }
    else if((a==LOW || b==LOW) && (d==LOW || e==LOW) && (g==LOW || h==LOW))
{
  just_check();
  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) )
  {  
    //flag++;
    //delay(1);
    //led_test();
    //Serial.print("flag=");
    //Serial.println(flag);
    //delay(1);
    line_traverse();      //delay(2000);

  }
  else
  {
    goto WELCOME;
    }
}
else if((a==LOW || b==LOW) && (e==LOW || d==LOW) && (h==HIGH || g==HIGH))
{
  just_check();
  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) )
  {
    //flag++;
    //delay(1);
    //led_test();
    //Serial.print("flag=");
    //Serial.println(flag);
    //delay(1);
    line_traverse();      //delay(2000);

  }
  else
  {
    goto WELCOME;
    }
}

else if( a==HIGH && (g==LOW || h==LOW) && (e==LOW || d==LOW))
{
  just_check();  
  if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) )
  {
    //flag++;
    //delay(1);
    //led_test();
    //Serial.print("flag=");
    //Serial.println(flag);
    //delay(1);
    line_traverse();      //delay(2000);

  }
  else
  {
    goto WELCOME;
    }
}

else if(a==HIGH && b==HIGH && c==HIGH && d==HIGH && e==HIGH && f==HIGH && g==HIGH && h==HIGH)
{
  just_check();
  if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {
  half_distance();
  turnover();
  //delay(1);
  }
  else {
    goto WELCOME;
    }
}
}


void line_traverse()
{
  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) )
  {
    flag++;
    delay(1);
    if(flag%5==0)
    {
      if(temp==0)
      {
        half_distance();
        rightturn();
        temp=1;
      }
      else
      {
        half_distance();
        leftturn();
        temp=0;
      }
      
    }
  }
     /*if(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW )
    {
      straight();
    }*/
  
  else if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digi
    half_distance();
    rightturn();
    //delay(1);
       
   }
   else if( flag==25)
   {
    stop1();
   }
  }
  else if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) )
  {
    flag++;
    delay(1);
    if( (flag==5) || (flag==6) || (flag==16) )
    {
      half_distance();
      leftturn();
      //delay(1);
    }
      
   /*if ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) 
   {*/
    //straight();
    //delay(1);
   //}
  }
   
}
void half_distance()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(265);
}


void just_check()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(25);
}


void stop1()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
}

void straight()
{
  if( digitalRead(ss5)==HIGH || digitalRead(ss3)==LOW ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
  if(digitalRead(ss4)==HIGH || digitalRead(ss6)==LOW ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, HIGH);;//changing from 230 to HIGH
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
    delay(1);
    
  }


void leftturn(){
  while(digitalRead(ss1)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }
    while(digitalRead(ss4)==HIGH || digitalRead(ss3)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH); 
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }
    if(digitalRead(ss5)==LOW){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
  }

  void turnover(){
  while(digitalRead(ss1)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }
    while(digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);
    }*/
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
    while(digitalRead(ss8)==HIGH){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, HIGH);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }

    while(digitalRead(ss5)==HIGH || digitalRead(ss6)==HIGH){
    analogWrite(lm1, 255);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 255);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);*/
    }
    if(digitalRead(ss4)==LOW){
      /*digitalWrite(lm1, LOW);
      analogWrite(lm2, 150);
      analogWrite(rm1, 150);
      digitalWrite(rm2, LOW);
      delay(1);*/
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(1);//5
      }
  }
void led_test()
{
  digitalWrite(led,HIGH);
  delay(15);
  digitalWrite(led,LOW);
}



