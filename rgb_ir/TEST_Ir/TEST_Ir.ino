#define ir2 8 
int g2=23;
int b2=47;

#define ir3 24 
int g3=27;
int b3=25;

#define ir6 33 
int g6=34;
int b6=35;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(ir2,INPUT);
pinMode(ir6,INPUT);
pinMode(g6,OUTPUT);
   pinMode(b6,OUTPUT);
   
   pinMode(g3,OUTPUT);
   pinMode(b3,OUTPUT);

pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int val=digitalRead(ir2);
Serial.println(val);
if(val==0)
digitalWrite(LED_BUILTIN,HIGH);
if(val==1)
digitalWrite(LED_BUILTIN,LOW);

if(digitalRead(ir3)==LOW)
 {
  digitalWrite(b3,HIGH);
}
if(digitalRead(ir3)==HIGH)
  {
    Serial.println("ACV");
    digitalWrite(b3,LOW);
  }
}
