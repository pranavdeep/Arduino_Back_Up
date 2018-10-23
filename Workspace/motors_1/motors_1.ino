int lm1=3;
int lm2=5;
int rm1=6;
int rm2=8;

void setup() {
  // put your setup code here, to run once:
pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(lm1,150);
    analogWrite(lm2,0);
  analogWrite(rm1,150);
  analogWrite(rm2,0);
   /* delay(5000);
    digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
    delay(5000);*/
  
}
