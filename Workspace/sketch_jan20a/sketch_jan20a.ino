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
                      delay(100);
                pickup();
                delay(1000);
                turnover();
            }         
    }

