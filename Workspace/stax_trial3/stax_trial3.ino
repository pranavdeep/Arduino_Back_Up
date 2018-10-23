int lm1=5;
int lm2=6;
int rm1=4;
int rm2=2;
int ss1=51;
int ss2=49;
int ss3=47;
int ss4=45;
int ss5=43;
int ss6=41;
int ss7=39;
int ss8=37;
int OutPut= 26;

char color;
int temp=0;
int flag=0;
int elbdrop=8 ;
int elblift=7;
int gripopen=9;
int gripclose=10;


int a,b,c,d,e,f,g,h,dabba;
int led1=A8;
int led2=A9;
int led3=A10;
int indicator[3];
int distance,duration;
int i=0;
//int color;
//int flag=0;
//int gf,bf,rf=0;
unsigned int rfrequency = 0;
unsigned int gfrequency = 0;
unsigned int bfrequency = 0;
int r1,g1,b1;
//int i,Sum=0,numbers;
  float Average;
 
//char color;

/*#define trigPin 11
#define echoPin 12
#define S0 8
#define S1 13
#define S2 14
#define S3 12
#define sensorOut 7*/

void setup()
{
Serial.begin(9600);
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
  pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

/*  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(34, OUTPUT);*/
                 pinMode(34, OUTPUT);

                pinMode(32, OUTPUT);//PINS 2, 3,4,5 as OUTPUT

                pinMode(30, OUTPUT);

                pinMode(28, OUTPUT);

                pinMode(26, INPUT);//PIN 10 as input

 

                digitalWrite(34,HIGH);

                digitalWrite(32,LOW);//setting frequency selection to 20%


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

else if(a==HIGH && b==HIGH && h==LOW && (e==HIGH || d==HIGH))
{
  analogWrite(lm1,255);
  digitalWrite(lm2,LOW);
    analogWrite(rm1,255);
  digitalWrite(rm2,LOW);
  delay(20);
  
  if((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) )
  {
  analogWrite(lm1,0);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  delay(500);
  //Serial.println("1");

  //colorsensing();
  indicator[i]=color;
  i++;
  analogWrite(lm1,255);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,255);
  digitalWrite(rm2,LOW);
  delay(400);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(500);
  reverse();
  analogWrite(lm1,155);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,155);
  digitalWrite(rm2,LOW);
  delay(165);
;
  
  delay(25);
  leftturn();
  //delay(300);
Serial.println("2");
//leftturn();
//
//the delay at this point fir delay should be >400-450  
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
      analogWrite(lm1,0);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  delay(300);
  /*analogWrite(lm1,155);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,155);
  digitalWrite(rm2,LOW);
  delay(65);*/
   
    /*ultrasonic();
    delay(500);
    if(distance<=5)
    {
      digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
    delay(500);*/
     /*analogWrite(lm1,160);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,160);
  digitalWrite(rm2,LOW);
  delay(150); */
       //colorsensing();
       //delay(300);
               //reverse();
    //delay(100);
    analogWrite(lm1,255);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,255);
  digitalWrite(rm2,LOW);
  delay(400);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(500);
  reverse();
  analogWrite(lm1,155);
  digitalWrite(lm2,LOW);
   analogWrite(rm1,155);
  digitalWrite(rm2,LOW);
  delay(165);
  colorsensing();
    delay(25);

   indicator[i]=color;
       i++;
       delay(50);
  //delay(1);
    rightturn();
    }
  }




else if(a==HIGH && b==HIGH && d==HIGH && e==HIGH && g==HIGH && h==HIGH)
{
  analogWrite(lm1,150);
  digitalWrite(lm2,LOW);
    analogWrite(rm1,150);
  digitalWrite(rm2,LOW);
  delay(20);
    if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {
    analogWrite(lm1,0);
  digitalWrite(lm2,LOW);
    analogWrite(rm1,0);
  digitalWrite(rm2,LOW);
  delay(500);
  if(flag==0)
  {
    digitalWrite(elbdrop,HIGH);
    delay(1000);
    digitalWrite(elbdrop,LOW);
    straight();
    flag++;
  }
   else if(flag==1)
   {
    pickup();
    while((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
    {
      reverse();
    }
    flag++;
   }
    else if(flag==3)
    {
      analogWrite(lm1,150);
  digitalWrite(lm2,LOW);
    analogWrite(rm1,150);
  digitalWrite(rm2,LOW);
  delay(165);
  rightturn();
  flag++;
    }
    else if(flag==4)
    {
      drop();
      delay(50);
      reverse();
     
         }
   }

      /*if(flag==0)
      {
       /*ultrasonic();
       delay(500);       
       while(distance>5)
       {
        straight();
       }
       if(distance<=5)
       {
          digitalWrite(lm1,LOW);
         digitalWrite(lm2,LOW);
         digitalWrite(rm1,LOW);
          digitalWrite(rm2,LOW);
         */ 
               //flag++;
       /*colorsensing();
       delay(2000);
      //pickup();        
      delay(100);
       //reverse();//reverse of straight function
       delay(100);
       //turnover();*/
       }
      }
       





void straight()
{
 /* ultrasonic();
  if(distance<=5)
  {
    digitalWrite(lm1,LOW);
         digitalWrite(lm2,LOW);
         digitalWrite(rm1,LOW);
          digitalWrite(rm2,LOW);
          delay(2000);
          colorsensing();
          delay(1000);
          reverse();
          delay(100);
          leftturn();
  }*/
  if( digitalRead(ss6)==LOW || digitalRead(ss2)==HIGH )
  {
  analogWrite(lm1, 165);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 165);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 180);
    digitalWrite(rm2, LOW);
    delay(1);
    return;         
  }
  if(digitalRead(ss3)==LOW || digitalRead(ss7)==HIGH ){
    analogWrite(lm1, 165);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 165);
    digitalWrite(rm2, LOW);
    delay(1);
    analogWrite(lm1, 180);
    digitalWrite(lm2, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
     analogWrite(lm1, 160);
     digitalWrite(lm2, LOW);
     analogWrite(rm1, 160);
      digitalWrite(rm2, LOW);
    delay(5);
    }
    void leftturn(){
    while(digitalRead(ss1)==LOW)
    {
      analogWrite(lm1, 0);
      analogWrite(lm2, 255);
      analogWrite(rm1, 255);
      analogWrite(rm2, LOW);
      delay(3);
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(1);*/
      }
      while(digitalRead(ss3)==LOW || digitalRead(ss6)==LOW){
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
      if((digitalRead(ss6)==HIGH)&&(digitalRead(ss4)==HIGH)&&(digitalRead(ss3)==HIGH))
    {
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      else
      {
        straight();
        delay(100);
      }
        
    }
    void rightturn(){
    while(digitalRead(ss8)==LOW){
    analogWrite(lm1, 225);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 225);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }

    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
    analogWrite(lm1, 225);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 225);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }
    if((digitalRead(ss6)==HIGH)&&(digitalRead(ss4)==HIGH)&&(digitalRead(ss3)==HIGH))
    {
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      else
      {
        straight();
        delay(100);
      }
      
  }
      void reverse()
      {
        digitalWrite(lm2,HIGH);
        digitalWrite(rm2,HIGH);
        digitalWrite(rm1,LOW);
        digitalWrite(lm1,LOW);
        delay(400);
       digitalWrite(lm2,LOW);
        digitalWrite(rm2,LOW);
        digitalWrite(rm1,LOW);
        digitalWrite(lm1,LOW);
        delay(100); 
      }
        /*if(((digitalRead(ss1)==HIGH)&& (digitalRead(ss2)==HIGH)) && ((digitalRead(ss3)==HIGH) || (digitalRead(ss4)==HIGH)) && ((digitalRead(ss5)==HIGH) || (digitalRead(ss6)==HIGH)) && ((digitalRead(ss7)==LOW) || (digitalRead(ss8)==LOW)))
{
      digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2, LOW);
      delay(250);
  leftturn();
         
}
      
else if((digitalRead(ss7)==HIGH)&& (digitalRead(ss8)==HIGH) && ((digitalRead(ss3)==HIGH) || (digitalRead(ss4)==HIGH)) && ((digitalRead(ss5)==HIGH) || (digitalRead(ss6)==HIGH)) && ((digitalRead(ss1)==LOW) || (digitalRead(ss2)==LOW)))
{
  digitalWrite(lm1, HIGH);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, HIGH);
      digitalWrite(rm2, LOW);
      delay(250);
     rightturn();
}
      }*/
      void colorsensing()
      {
          int rfrequency,bfrequency,gfrequency;
        Serial.print("R=");//printing name

                digitalWrite(30,LOW);

                digitalWrite(28,LOW);//setting for RED color sensor

                rfrequency = pulseIn(OutPut, LOW);//reading frequency

            Serial.print(rfrequency);//printing RED color frequency

               Serial.print("  ");
               r1=rfrequency;
              // scanf("%d",&r);
                delay(50);
 
  
 /* for(i=0;i<1000;++i)
   {
     scanf("%d",&r);
     Sum = Sum +r;
   }
 
  Average = Sum/r;
 
  printf("\nSum of the n Numbers = %d",r, Sum);
  printf("\nAverage of n Numbers = %.2f",r, Average);
 
  return 0;
   */  

              //  lcd.setCursor(7, 0);//moving courser to position 7
                       

               
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                Serial.print("B=");// printing name

                digitalWrite(30,LOW);

                digitalWrite(28,HIGH);// setting for BLUE color sensor

                bfrequency = pulseIn(OutPut, LOW);// reading frequency

                 Serial.print(bfrequency);// printing BLUE color frequency

                 Serial.print("  ");
                 b1=bfrequency;

                //lcd.setCursor(0, 1);

                delay(50);

            /*  for(i=0;i<1000;++i)
   {
     scanf("%d",&b);
     Sum = Sum +b;
   }
 
  Average = Sum/b;
 
  printf("\nSum of the n Numbers = %d",b, Sum);
  printf("\nAverage of n Numbers = %.2f",b, Average);
  return 0;
 
*/
              Serial.print("G=");// printing name

                digitalWrite(30,HIGH);

                digitalWrite(28,HIGH);// setting for GREEN color sensor

                gfrequency = pulseIn(OutPut, LOW);// reading frequency

               Serial.print(gfrequency);// printing GREEN color frequency

                Serial.print("    ");
                g1=gfrequency;
              /*  for(i=0;i<1000;++i)
   {
     scanf("%d",&g);
     Sum = Sum +g;
   }
 
  Average = Sum/g;
 
  printf("\nSum of the n Numbers = %d",r, Sum);
  printf("\nAverage of n Numbers = %.2f",r, Average);
 
return 0;*/
                //lcd.setCursor(0, 0);

                delay(50);        
                if(g1<80)
                {
                  /*Serial.println("RED DETECTED!");
                  delay(500);*/
                  color='O';
                  digitalWrite(led1,HIGH);
                  delay(250);
                  digitalWrite(led1,LOW);
                }
                else if(g1<130)
                {
                  color='Y';
                 /* Serial.println("GREEN DETECTED!");
                  delay(1000);*/
                  digitalWrite(led2,HIGH);
                  delay(250);
                  digitalWrite(led2,LOW);
                }
                else if(g1<250)
                {
                  color='P';
                  /*Serial.println("BLUE DETECTED!");
                  delay(1000);*/
                  digitalWrite(led3,HIGH);
                  delay(250);
                  digitalWrite(led3,LOW);
                }
                  else if(temp==0)
                  {
                    digitalWrite(led3,HIGH);
                    delay(250);
                    digitalWrite(led3,LOW);
                    temp++;
                  }
                  else if(temp==1)
                  {
                    digitalWrite(led2,HIGH);
                  delay(250);
                  digitalWrite(led2,LOW);
                  temp++;
                  }
                  else if(temp==2)
                  {
                    digitalWrite(led1,HIGH);
                  delay(250);
                  digitalWrite(led1,LOW);
                  }
                }
      


      void pickup()
{
  /*digitalWrite(gripopen,HIGH);
  delay(2000);*/
  digitalWrite(gripclose,HIGH);
  delay(3000);
  digitalWrite(gripclose,LOW);
  delay(10);
  analogWrite(elblift,255);
  delay(950);
  digitalWrite(elblift,LOW);
  delay(10);
}

void drop()
{
  analogWrite(elbdrop,255);
  delay(950);
  digitalWrite(elbdrop,LOW);
  delay(10);
  digitalWrite(gripopen,HIGH);
  delay(1500);
  digitalWrite(gripopen,LOW);
  delay(10);
  /*analogWrite(elblift,255);
  delay(4000);
  analogWrite(elblift,0);
  delay(4000);
  digitalWrite(gripclose,HIGH);
  delay(2000);//changed this delay value*/
}
      
      
      /*void turnover()
      {
        while(digitalRead(ss1)==LOW){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(3);
        }
    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW){
    digitalWrite(lm1, LOW);
    analogWrite(lm2, 255);
    analogWrite(rm1, 255);
    digitalWrite(rm2, LOW);
    delay(3);
          }
          if(digitalRead(ss5)==HIGH){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
        }
/*void ultrasonic()
{
    digitalWrite(trigPin, LOW);
delayMicroseconds(25);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
}*/
