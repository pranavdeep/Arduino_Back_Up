int elbdrop=7;
int elblift=8;
int gripopen=9;
int gripclose=10;

void setup() {
  // put your setup code here, to run once:
pinMode(elblift,OUTPUT);
   pinMode(elbdrop,OUTPUT);
   pinMode(gripopen,OUTPUT);
   pinMode(gripclose,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//void pickup();
analogWrite(elbdrop,255);

}
void pickup()
{
  //digitalWrite(gripopen,HIGH);
  //delay(2000);
  //analogWrite(elbdrop,255);
  //delay(4000);
  digitalWrite(gripclose,HIGH);
  delay(3000);
  analogWrite(elblift,255);
  delay(4000);
  analogWrite(elblift,0);
  delay(2000);//changed this delay value
}
