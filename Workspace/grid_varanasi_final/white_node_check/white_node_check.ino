int ss1 = 13;
int ss2 = 12;
int ss3 = 11;
int ss4 = 8;
int ss5 = 7;
int ss6 = 4;
int ss7 = 3;
int ss8 = 2;
int a, b, c, d, e, f, g, h;
void setup() {
  // put your setup code here, to run once:
  pinMode(ss1, INPUT);
  pinMode(ss2, INPUT);
  pinMode(ss3, INPUT);
  pinMode(ss4, INPUT);
  pinMode(ss5, INPUT);
  pinMode(ss6, INPUT);
  pinMode(ss7, INPUT);
  pinMode(ss8, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
white_node_check();
}

void white_node_check()
{
  Serial.println("Entered white_node_check()");
  /*if( (digitalRead(ss1)==LOW) && (digitalRead(ss2)==LOW) && ((digitalRead(ss4)==HIGH) || (digitalRead(ss5)==HIGH)) && (digitalRead(ss7)==LOW) && (digitalRead(ss8)==LOW) )
  {
    just_check();*/
    
    //delay(100);
      if( ( (digitalRead(ss1)==LOW) || (digitalRead(ss2)==LOW)) && ( (digitalRead(ss4)==HIGH) || (digitalRead(ss5)==HIGH) || (digitalRead(ss6)==HIGH) ) && ( (digitalRead(ss7)==LOW) || (digitalRead(ss8)==LOW) ) )
     {
      Serial.println("White Node Detected");
    //buzz1();
    //node[i]=flag;
    Serial.print("Storing node point=");
    //Serial.println(flag);
//    i++;
     }
     }
