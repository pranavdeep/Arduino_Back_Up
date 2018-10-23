 //working on the unspecified combinational sensors and their specific allotment
 
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
int dobba=A1;
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
  pinMode(dobba,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
  
}
void readsensors()
{
  a=digitalRead(ss1);
  b=digitalRead(ss2);
  
  c=digitalRead(ss3);
  
  d=digitalRead(ss4);
  e=digitalRead(ss5);
  
  f=digitalRead(ss6);
  
  g=digitalRead(ss7);
  h=digitalRead(ss8);

  dabba=digitalRead(dobba);
  Serial.println(dabba);
}
void loop()
{
  WELCOME :
  readsensors();
if (dabba==HIGH)
{
  done();
  }
else if(a==LOW && h==LOW && ( d==HIGH || e==HIGH ))
{
straight();
}

else if(a==HIGH && b==HIGH && d==HIGH && e==HIGH && g==HIGH && h==HIGH)//(a||b)&&(c||d)&&(g||h)logic gates difference
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
  {

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(285);//delay 200
      if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
      {
         digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(led,HIGH);
  delay(25000);//delay 50000
      }
      else
      {
  leftturn();
  }
  }
  else{
    goto WELCOME;
    }
}

//making changes just down here if not working go for prev version opt 4

else if(a==HIGH && b==HIGH && h==LOW && (e==HIGH || d==HIGH))//(a=h||b=h)&&(e=h||d=h)&&(h=l||g=l)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);//25
  if( (digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) ){

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(285);//150
  
  leftturn();
  }
  else{
    goto WELCOME;
    }
}

else if(g==HIGH && h==HIGH && a==LOW && (e==HIGH || d==HIGH))//(a=l&&(g=h||h=h)&&(e=h||d=h)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);//25
  if( (digitalRead(ss1)==LOW || digitalRead(ss2)==LOW) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) ){
  
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(285); //200
  
  if ( ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss8)==LOW ) && (digitalRead(ss1)==LOW ) )
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
  else if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) ) {
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);//30
       rightturn();
    }
    }

    else if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) ){
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(285);//200
    leftturn();
    }

  else{
    goto WELCOME;
    }
}

else if(a==LOW && b==LOW && c==LOW && d==LOW && e==LOW && f==LOW && g==LOW && h==LOW)
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(20);
  if(a==LOW && b==LOW && c==LOW && d==LOW && e==LOW && f==LOW && g==LOW && h==LOW){

  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(285);
  
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
 while(digitalRead(dobba)==HIGH){
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
  if( digitalRead(ss5)==LOW || digitalRead(ss3)==HIGH ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 180);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
  if(digitalRead(ss4)==LOW || digitalRead(ss6)==HIGH )//ss5 and ss3 instead of ss4 
 {
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    analogWrite(lm1, 255);//220
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
 
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(5);//1
    
  }

void leftturn(){
  while(digitalRead(ss1)==LOW){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);*/
    //delay(1);
    //Serial.println(" 1st in left turn");
    }
    while(digitalRead(ss5)==LOW || digitalRead(ss4)==LOW)// changing from ss3 and ss3 to ss4 and ss5//(ss3=l0w||ss4=low)
    {
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH);//analogwrite,220
    digitalWrite(rm1, HIGH);//analogwrite,220
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    Serial.println(" 2nd in left turn");*/
    }
    if(digitalRead(ss5)==HIGH)//CHAnging from HIGH TO LOW
    {
      digitalWrite(lm1, LOW);//analogwrite 220
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);//analogwrite 220
      //Serial.println("XXXXX");
      delay(2);
      
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);*/
              
       }
       if(replaystage==0){
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

void turnover(){
  while(digitalRead(ss1)==LOW){
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

    while(digitalRead(ss4)==LOW || digitalRead(ss5)==LOW)//(ss5=low||ss6=low)
    {
    digitalWrite(lm1,LOW);//analogwrite 255
    digitalWrite(lm2, HIGH);//low
    digitalWrite(rm1, HIGH);//low
    digitalWrite(rm2, LOW);//analogwrite 255
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }
    if(digitalRead(ss5)==HIGH)//ss4 instead of ss5
    {
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, HIGH);\\
      digitalWrite(rm1, HIGH);\\
      digitalWrite(rm2, LOW);
      delay(2);*/
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);//analogwrite 0
      digitalWrite(rm1, LOW);//analogwrite 0
      digitalWrite(rm2, LOW);
      delay(2);//5
      }
      path[pathLength]='B';
  pathLength++;
  straight();
      
  }

void rightturn(){
    while(digitalRead(ss8)==LOW){
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

    while(digitalRead(ss5)==LOW || digitalRead(ss4)==LOW)//changing from ss5 and ss6 to ss4 and ss5,ss5,ss6
    {
    digitalWrite(lm1, HIGH);//analogwrite 255
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
  digitalWrite(rm2, HIGH);//analogwrite 255
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);//changing from 3 to 1*/
    }
    if(digitalRead(ss4)==HIGH){
      /*digitalWrite(lm1, LOW);
      analogWrite(lm2, 150);
      analogWrite(rm1, 150);
      digitalWrite(rm2, LOW);
      delay(1);*/
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);//5
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
  if(a==LOW && h==LOW){
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

