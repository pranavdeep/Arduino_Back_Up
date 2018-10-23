
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



digitalWrite(g1,LOW);
digitalWrite(b1,LOW);
digitalWrite(g2,LOW);
digitalWrite(b2,LOW);
digitalWrite(g3,LOW);
digitalWrite(b3,LOW);
digitalWrite(g4,LOW);
digitalWrite(b4,LOW);
digitalWrite(g5,LOW);
digitalWrite(b5,LOW);   
digitalWrite(g6,LOW);
digitalWrite(b6,LOW);
digitalWrite(g7,LOW);
digitalWrite(b7,LOW);
digitalWrite(g8,LOW);
digitalWrite(b8,LOW);
digitalWrite(g9,LOW);
digitalWrite(b9,LOW);
digitalWrite(g10,LOW);
digitalWrite(b10,LOW);
digitalWrite(g11,LOW);
digitalWrite(b11,LOW);
digitalWrite(g12,LOW);
digitalWrite(b12,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  //digitalWrite(r1,HIGH);
  //digitalWrite(g1,HIGH);
  //digitalWrite(b1,HIGH);

  int val=analogRead(ir8);
  Serial.println(val);
  
 if(digitalRead(ir1)==LOW)
 {
  //digitalWrite(r1,HIGH);
  //digitalWrite(g1,HIGH);
  //Serial.println("dsfasfsd");
  digitalWrite(g1,HIGH);
 }
  if(digitalRead(ir1)==HIGH)
  {
    //Serial.println("ACV");
    digitalWrite(g1,LOW);
  }
 
if(digitalRead(ir2)==LOW)
 {
  digitalWrite(g2,HIGH);
  
 }
  if(digitalRead(ir2)==HIGH)
  {
    
    digitalWrite(g2,LOW);
  }
  
if(digitalRead(ir3)==LOW)
 {
  
  digitalWrite(g3,HIGH);
 }
  if(digitalRead(ir3)==HIGH)
  {
    
    digitalWrite(g3,LOW);
  }
  if(digitalRead(ir4)==LOW)
 {
  
  digitalWrite(g4,HIGH);
 }
  if(digitalRead(ir4)==HIGH)
  {
    
    digitalWrite(g4,LOW);
  }
if(digitalRead(ir5)==LOW)
 {
  
  digitalWrite(g5,HIGH);
 }
  if(digitalRead(ir5)==HIGH)
 {
  
  digitalWrite(g5,LOW);
 }
  
  if(digitalRead(ir6)==LOW)
 {
  
  digitalWrite(g6,HIGH);
 }
  if(digitalRead(ir6)==HIGH)
 {
  
  digitalWrite(g6,LOW);
 }

if(analogRead(ir7)<200)
 {
  
  analogWrite(g7,255);
 }
  if(analogRead(ir7)>200)
  {
    
    analogWrite(g7,0);
  }


  if(digitalRead(ir8)==HIGH)
 {
  
  digitalWrite(g8,LOW);
 }
if(digitalRead(ir8)==LOW)
 {
  
  digitalWrite(g8,HIGH);
 }
 
  
  
  if(analogRead(ir9)<200)
 {
  
  analogWrite(g9,255);
 }
 if(analogRead(ir9)>200)
  {
    
    analogWrite(g9,0);
  }
  if(analogRead(ir10)<200)
 {
  
  analogWrite(g10,255);
 }
  if(analogRead(ir10)>200)
  {
    
    analogWrite(g10,0);
  }
  if(digitalRead(ir11)==LOW)
 {
  
  
  digitalWrite(g11,HIGH);
 }
  if(digitalRead(ir11)==HIGH)
  {
    
    digitalWrite(g11,LOW);
  }

  if(digitalRead(ir12)==LOW)
 {
  analogWrite(g12,255);
 }
  if(digitalRead(ir12 )==HIGH)
  {
    analogWrite(g12,0);
  }
} 
