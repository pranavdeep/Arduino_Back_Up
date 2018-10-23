 //working on the unspecified combinational sensors and their specific allotment
 
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
int a,b,c,d,e,f,g,h,dabba;
int toogle=A1;
int led=A0;
int replaystage;

char path[30] = {};
int pathLength;
int readLength;

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
  pinMode(toogle,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
  
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

  dabba=digitalRead(toogle);
}
void loop()
{
  WELCOME :
  readsensors();
if (dabba==HIGH)
{
  done();
  }
  
else if(a==HIGH && h==HIGH && ( d==LOW || e==LOW ))
{
  Serial.println("1");
straight();
}

else if( (a==LOW || b==LOW) && (d==LOW || e==LOW) && (g==LOW || h==LOW)  )
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
    Serial.println("2");

  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) )
  {
  Serial.println("3");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300);//changing from 140 to 300
  
  leftturn();
  }
  else{
      Serial.println("4");
    goto WELCOME;
    }
}

//making changes just down here if not working go for prev version opt 4

else if(a==LOW && b==LOW &&h=HIGH (e==LOW || d==LOW ) )
{
    Serial.println("5");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(25);
}
  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) )
  {
      Serial.println("6");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300);
  
  leftturn();
  }
  else{
      Serial.println("7");
    goto WELCOME;
    }


else if(g==LOW && h==LOW && a==HIGH  && (e==LOW || d==LOW))
{
    Serial.println("8");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(25);

}
  
  if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) )
  {
    Serial.println("8");
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300); 
  
  if ( ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss8)==HIGH ) && (digitalRead(ss1)==HIGH ) )
  {

      path[pathLength]='S';
   // Serial.println("s");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
    if(path[pathLength-2]=='B'){
    //Serial.println("shortening path");
    shortPath();
     }
  
  straight();
  }

  else if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH&& digitalRead(ss8)==HIGH ) ) {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(30);
       rightturn();
    }
  
  }

    else if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) ){
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(140);
    leftturn();
    }

  else{
    goto WELCOME;
    }
}

else if(a==HIGH && b== HIGH&& c==HIGH && d==HIGH && e==HIGH && f==HIGH && g==HIGH && h==HIGH)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(300);
  
  
  turnover();
  }
  else {
    goto WELCOME;
    }
}


}

void done(){
  digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
  replaystage=1;
  path[pathLength]='D';
  pathLength++;
 while(digitalRead(toogle)==HIGH){
   digitalWrite(led, LOW);
   delay(150);
   digitalWrite(led, HIGH);
   delay(150);
 }
 delay(500);
  replay();
}

void straight()
{
    Serial.println("9");
  if( digitalRead(ss5)==HIGH || digitalRead(ss3)==LOW )
  {
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
  /*if(digitalRead(ss4)==HIGH || digitalRead(ss6)==LOW )
  {
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    analogWrite(lm1, 180);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }*/
 
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    
  }

void leftturn()
{
    Serial.println("10");

  while(digitalRead(ss1)==HIGH)
  {
      Serial.println("11");

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
    
    while(digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH)
    {
        Serial.println("12");

    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);
    }*/
    if(digitalRead(ss5)==HIGH)
    {
        Serial.println("13");

      digitalWrite(lm1, LOW);//changed from 180 to 255
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      analogWrite(rm2, LOW);
      delay(2);//commenting the below lines just to check
      
     /* digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);*/
      }
    if(replaystage==0)
    {
    path[pathLength]='L';
    //Serial.println("l");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
      if(path[pathLength-2]=='B'){
        //Serial.println("shortening path");
        shortPath();
      }
  }  
  }
}
void turnover()
{
  while(digitalRead(ss1)==HIGH)
  {
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    }

    while(digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH){
    analogWrite(lm1, 180);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 180);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);
    }
    if(digitalRead(ss5)==LOW){
      /*digitalWrite(lm1, LOW);
      analogWrite(lm2, 150);
      analogWrite(rm1, 150);
      digitalWrite(rm2, LOW);
      delay(2);*/
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      path[pathLength]='B';
  pathLength++;
  straight();
      
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

    while(digitalRead(ss4)==HIGH|| digitalRead(ss5)==HIGH){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, HIGH);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);
    }
    /*if(digitalRead(ss4)==LOW){
      digitalWrite(lm1, LOW);
      analogWrite(lm2, 150);
      analogWrite(rm1, 150);
      digitalWrite(rm2, LOW);
      delay(1);*/
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      if(replaystage==0){
  path[pathLength]='R';
  Serial.println("r");
  pathLength++;
  Serial.print("Path length: ");
  Serial.println(pathLength);
    if(path[pathLength-2]=='B'){
      Serial.println("shortening path");
      shortPath();
    }
  }
      
}

void shortPath(){
 int shortDone=0;
  if(path[pathLength-3]=='L' && path[pathLength-1]=='R'){
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test1");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='L' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
    //Serial.println("test2");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='R' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test3");
    shortDone=1;
  }
  
   
  if(path[pathLength-3]=='S' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
    //Serial.println("test4");
    shortDone=1;
  }
     
  if(path[pathLength-3]=='S' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
    //Serial.println("test5");
    shortDone=1;
  }
    if(path[pathLength-3]=='L' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='S';
    //Serial.println("test6");
    shortDone=1;
  }
  
  path[pathLength+1]='D';
  path[pathLength+2]='D';
  pathLength++;
  //Serial.print("Path length: ");
  //Serial.println(pathLength);
  //printPath();
}




void printPath(){
  Serial.println("+++++++++++++++++");
  int x;
  while(x<=pathLength){
  Serial.println(path[x]);
  x++;
  }
  Serial.println("+++++++++++++++++");
}


void replay(){
   readsensors();
  if(a==HIGH && h==HIGH){
    straight();
  }
  else{
    if(path[readLength]=='D'){
       digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(100);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
      endMotion();
    }
    if(path[readLength]=='L'){
     digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(150);
      leftturn();
    }
    if(path[readLength]=='R'){
       digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(150);
    rightturn();
    }
    if(path[readLength]=='S'){
       digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(150);
    straight();
    }
    
    readLength++;
  }
    
  replay();
  
}

void endMotion(){
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(200);
      digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
    delay(500);
  endMotion();
}

