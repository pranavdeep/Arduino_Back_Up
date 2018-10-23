
#define ir1 53
int g1=50;
int b1=52;

#define ir2 46 
int b2=23;
int g2=47;

#define ir3 24 
int g3=27;
int b3=25;

#define ir4 26
int b4=29;
int g4=28;

#define ir5 30 
int g5=31;
int b5=32;

#define ir6 33 
int b6=34;
int g6=35;


#define ir7 A13 
int b7=A14;
int g7=A7;


#define ir8 36 
int b8=37;
int g8=39;

#define ir10 A0 
int g10=A1;
int b10=A2;


#define ir11 13 
int g11=11;
int b11=12;


#define ir12 10 
int b12=8;
int g12=A11;


#define ir9 A8 
int g9=A5;
int b9=A9;

int score=0;
unsigned long previousMillis = 0; 
const long interval = 1500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   
   pinMode(g1,OUTPUT);
   pinMode(b1,OUTPUT);
   
   pinMode(g2,OUTPUT);
   pinMode(b2,OUTPUT);
   
   pinMode(g3,OUTPUT);
   pinMode(b3,OUTPUT);
   
   pinMode(g4,OUTPUT);
   pinMode(b4,OUTPUT);
   
   pinMode(g5,OUTPUT);
   pinMode(b5,OUTPUT);
   
   pinMode(g6,OUTPUT);
   pinMode(b6,OUTPUT);
   
   pinMode(g7,OUTPUT);
   pinMode(b7,OUTPUT);
   
   pinMode(g8,OUTPUT);
   pinMode(b8,OUTPUT);
   
   pinMode(g9,OUTPUT);
   pinMode(b9,OUTPUT);
   
   pinMode(g10,OUTPUT);
   pinMode(b10,OUTPUT);
   
   pinMode(g11,OUTPUT);
   pinMode(b11,OUTPUT);
   
   pinMode(g12,OUTPUT);
   pinMode(b12,OUTPUT);
   

   pinMode(ir1,INPUT);
   pinMode(ir2,INPUT);
   pinMode(ir3,INPUT);
   pinMode(ir4,INPUT);
   pinMode(ir5,INPUT);
   pinMode(ir6,INPUT);
   pinMode(ir7,INPUT);
   pinMode(ir8,INPUT);
   pinMode(ir9,INPUT);
   pinMode(ir10,INPUT);
   pinMode(ir11,INPUT);
   pinMode(ir12,INPUT);
   
}
//analog irs are: 7, 9, 10
void loop() 
{
 game_test();
 //delay(10000);
}

void set1()
{
  digitalWrite(b1,HIGH);
  digitalWrite(g5,HIGH);
  analogWrite(g9,255);
}

void off()
{
  Serial.println(score);
  digitalWrite(b1,LOW);
  digitalWrite(g5,LOW);
  analogWrite(g9,0);
  //delay(20000);
}


void game_test()
{
  unsigned long currentMillis = millis();
  //delay(300);
  set1();  
 /*int ir1_val=digitalRead(ir1);
 int ir5_val=digitalRead(ir5);
 int ir9_val=analogRead(ir9);
 Serial.print("ir1_val=");
 Serial.println(ir1_val);
 Serial.print("ir5_val=");
 Serial.println(ir5_val);
 Serial.print("ir9_val=");
 Serial.println(ir9_val);*/

 if (currentMillis - previousMillis <= interval)
 {
 previousMillis = currentMillis;
 if(digitalRead(ir1)==0)
 {
  score++;
  digitalWrite(b1,LOW);
 }
 if(digitalRead(ir5)==0)
 {
  digitalWrite(g5,LOW);
  score++;
 }
 if(analogRead(ir9)<200)
 {
  analogWrite(g9,0);
  score++;
 }
 //delay(1500);
 //off();
 Serial.print("Score=");
 Serial.println(score);
 int time=millis();
 Serial.print("Time=");
 Serial.println(time);
 }
 if (currentMillis - previousMillis <= interval)
 {
  off();
 }
}

