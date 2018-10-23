/*Author: Pranav Deep Indrakanti
 * Date: 27-06-2018
 * Title: Interactive Table
 */

//defining all the pins




int ir0=A0;

int ir1=3;

int ir2=28;

int ir3=29;

int ir4=17;

int ir5=18;

int ir6=31;
/*
int ir7=A13;

int ir8=A6;

int ir9=A12;

int ir10=48;

int ir11=44;

//i=0;

//RGB pins
int r2=22;
int g2=24;
int b2=26;

int r1=5;
int g1=7;
int b1=6;

int r0=8;
int g0=9;
int b0=10;

/*
int r3=23;
int g3=25;
int b3=27;

int r4=15;
int g4=14;
int b4=16;

int r5=12;
int g5=13;
int b5=A0;

int r6=32;
int g6=33;
int b6=53;

int r7=A15;
int g7=A14;
int b7=52;

int r8=A2;
int g8=A4;
int b8=A5;

int r9=A8;
int g9=A9;
int b9=A10;

int r10=49;
int g10=50;
int b10=51;

int r11=37;
int g11=40;
int b11=36;


*/
void setup() 
{
  Serial.begin(9600);
  
   pinMode(ir0,INPUT);
 
  }
  

void loop()
{
 int a=analogRead(ir0);
  Serial.print("a=");
  Serial.println(a);
  /*
   if(digitalRead(ir0==LOW))
 {
  digitalWrite(r0,HIGH);
  digitalWrite(g0,HIGH);
  digitalWrite(b0,HIGH);
  Serial.println("abc");
 }

 else if(digitalRead(ir0==HIGH))
 {
  digitalWrite(r0,LOW);
  digitalWrite(g0,LOW);
  digitalWrite(b0,LOW);
    Serial.println("hjkhk");

 }
if(digitalRead(ir1==LOW))
 {
  digitalWrite(r1,HIGH);
  digitalWrite(g1,HIGH);
  digitalWrite(b1,HIGH);
 }


if(digitalRead(ir2==LOW)) {
  digitalWrite(r1,HIGH);
  digitalWrite(g1,HIGH);
  digitalWrite(b1,HIGH);
 }

if(digitalRead(ir3==HIGH))
 {
  digitalWrite(r3,HIGH);
  digitalWrite(g3,HIGH);
  digitalWrite(b3,HIGH);
 }

 if(digitalRead(ir4==HIGH))
 {
  digitalWrite(r4,HIGH);
  digitalWrite(g4,HIGH);
  analogWrite(b5,255);
 }

 if(digitalRead(ir5==HIGH))
 {
  digitalWrite(r5,HIGH);
  digitalWrite(g5,HIGH);
  digitalWrite(b5,HIGH);
 }

 if(digitalRead(ir6==HIGH))
 {
  digitalWrite(r6,HIGH);
  digitalWrite(g6,HIGH);
  digitalWrite(b6,HIGH);
 }

 if(analogRead(ir7>200))
 {
  analogWrite(r7,HIGH);
  analogWrite(g7,HIGH);
  digitalWrite(b7,HIGH);
 }

 if(analogRead(ir8>200))
 {
    analogWrite(r8,255);
    analogWrite(g8,255);
    analogWrite(b8,255);  
 }

 if(digitalRead(ir9==HIGH))
 {
  analogWrite(r9,255);
    analogWrite(g9,255);
    analogWrite(b9,255); 
 }

 if(digitalRead(ir10==1))
 {
  digitalWrite(r10,HIGH);
  digitalWrite(g10,HIGH);
  digitalWrite(b10,HIGH);
 }
 
 if(digitalRead(ir11==1))
 {
  digitalWrite(r11,HIGH);
  digitalWrite(g11,HIGH);
  digitalWrite(b11,HIGH);
 }

  Serial.println(digitalRead(ir3));
*/




//test_rgb();

  }
/*
  void test_ir()
  {
    int a=digitalRead(ir0);
    Serial.print("a=");
    Serial.println(a);
    int b=digitalRead(ir1);
    Serial.print("b=");
    Serial.println(b);
    int c=digitalRead(ir2);
    Serial.print("c=");
    Serial.println(c);
    
  }
  
  /*
void test_rgb()
{
  digitalWrite(r0,HIGH);
  digitalWrite(g0,HIGH);
  digitalWrite(b0,HIGH);
  delay(2000);
  digitalWrite(r1,HIGH);
  digitalWrite(g2,HIGH);
  digitalWrite(b2,HIGH);
  delay(2000);
  digitalWrite(r3,HIGH);
  digitalWrite(g3,HIGH);
  digitalWrite(b3,HIGH);
  delay(2000);
  digitalWrite(r4,HIGH);
  digitalWrite(g4,HIGH);
  digitalWrite(b4,HIGH);
  delay(2000);
  digitalWrite(r5,HIGH);
  digitalWrite(g5,HIGH);
  digitalWrite(b5,HIGH);
  delay(2000);
  digitalWrite(r6,HIGH);
  digitalWrite(g6,HIGH);
  digitalWrite(b6,HIGH);
  delay(2000);
  digitalWrite(r7,HIGH);
  digitalWrite(g7,HIGH);
  digitalWrite(b7,HIGH);
  delay(2000);
  digitalWrite(r8,HIGH);
  digitalWrite(g8,HIGH);
  digitalWrite(b8,HIGH);
  delay(2000);
  digitalWrite(r9,HIGH);
  digitalWrite(g9,HIGH);
  digitalWrite(b9,HIGH);
  delay(2000);
  digitalWrite(r10,HIGH);
  digitalWrite(g10,HIGH);
  digitalWrite(b10,HIGH);
  delay(2000);
  digitalWrite(r11,HIGH);
  digitalWrite(g11,HIGH);
  digitalWrite(b11,HIGH);
  delay(3000);



  digitalWrite(r0,LOW);
  digitalWrite(g0,LOW);
  digitalWrite(b0,LOW);
  
  digitalWrite(r1,LOW);
  digitalWrite(g1,LOW);
  digitalWrite(b1,LOW);
  
  digitalWrite(r2,LOW);
  digitalWrite(g2,LOW);
  digitalWrite(b2,LOW);

  digitalWrite(r3,LOW);
  digitalWrite(g3,LOW);
  digitalWrite(b3,LOW);

  digitalWrite(r4,LOW);
  digitalWrite(g4,LOW);
  digitalWrite(b4,LOW);

  digitalWrite(r5,LOW);
  digitalWrite(g5,LOW);
  digitalWrite(b5,LOW);

  digitalWrite(r6,LOW);
  digitalWrite(g6,LOW);
  digitalWrite(b6,LOW);

  digitalWrite(r7,LOW);
  digitalWrite(g7,LOW);
  digitalWrite(b7,LOW);

  digitalWrite(r8,LOW);
  digitalWrite(g8,LOW);
  digitalWrite(b8,LOW);

  digitalWrite(r9,LOW);
  digitalWrite(g9,LOW);
  digitalWrite(b9,LOW);

  digitalWrite(r10,LOW);
  digitalWrite(g10,LOW);
  digitalWrite(b10,LOW);


  digitalWrite(r11,LOW);
  digitalWrite(g11,LOW);
  digitalWrite(b11,LOW);
  
  
  
  
  
  
  
  
  
  
  
  
  
}
*/
