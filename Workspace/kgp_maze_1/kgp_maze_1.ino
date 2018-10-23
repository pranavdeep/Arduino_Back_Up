 //working on the unspecified combinational sensors and their specific allotment
/*Step 1: (pending work) To find the current node{(x,y)coordinates} & check if the node point has already been visited or not
  //Step 2: Write an if-else condition for the above mentioned
  //Step 3: In the left condition change direction to West
  //Step 4: In the right condition chanage direction to East
  //We are using step 3 and step in this sense because we have to know the current move which wouldn't be possible otherwise */
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
int dobba=A0;
int led=A1;
int replaystage;
//int flag=0;
//char dir='N';
//int arrX[30];
//int arrY[30];
int i,j,x,y=0;
char path[30] = {};
int pathLength;
int readLength;
//int temp=0;

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
  Serial.begin(9600);
  
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

  dabba=digitalRead(dobba);
}
void loop()
{
  WELCOME :
  readsensors();
if (dabba==HIGH)
{
  //Serial.println("LABENDFASFSDFDSK");
  done();
  }
else if(a==HIGH && h==HIGH && ( d==LOW || e==LOW ))
{
  /*if(temp!=0)
  {
  search();
  delay(1);
  straight();
  }
  else
  {*/
  straight();
  //temp++;
  //}
}
else if((a==LOW || b==LOW) && (d==LOW || e==LOW) && (g==LOW || h==LOW)  )
{
  analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) )
  {
    //search();
  analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(240);
if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) ) 
{

    digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(led,HIGH);
  delay(7000);
  
  }
 
  else
  {
      leftturn();
     /* search();
    delay(1);*/
  }
  }
  else{
    goto WELCOME;
    }
}

//making changes just down here if not working go for prev version opt 4

else if((a==LOW || b==LOW) && (e==LOW || d==LOW) && (h==HIGH || g==HIGH)  )
{
 analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(20);
  if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) ){

  analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(240);
    leftturn();
    /*search();
  delay(1);*/
  }
  else{
    goto WELCOME;
    }
}

else if( a==HIGH && (g==LOW || h==LOW) && (e==LOW || d==LOW))
{
 analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(25);
  
  if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW || digitalRead(ss8)==LOW ) ){
  
analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(240); 
  if ( ( digitalRead(ss4)==LOW || digitalRead(ss5)==LOW ) && ( digitalRead(ss8)==HIGH ) && (digitalRead(ss1)==HIGH ) ){

      path[pathLength]='S';
   // Serial.println("s");
    pathLength++;
    //Serial.print("Path length: ");
    //Serial.println(pathLength);
    if(path[pathLength-2]=='B'){
    //Serial.println("shortening path");
    shortPath();
     }
 /*search();
 delay(1); */
  straight();
  }

  else if( (digitalRead(ss1)==HIGH && digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH && digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH && digitalRead(ss8)==HIGH ) ) 
  {
  analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(15);
       rightturn();
       //Serial.println("1");
       /*search();
      delay(1);*/
    }
  
  }

    else if( (digitalRead(ss1)==LOW && digitalRead(ss2)==LOW) && ( digitalRead(ss4)==LOW && digitalRead(ss5)==LOW ) && ( digitalRead(ss7)==LOW && digitalRead(ss8)==LOW ) ){
  analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(240);
  Serial.println("2");
    /*search();
    delay(1);*/
    leftturn();
    //search();
    //delay(1);
    }

  else{
    goto WELCOME;
    }
}

else if(a==HIGH && b==HIGH && c==HIGH && d==HIGH && e==HIGH && f==HIGH && g==HIGH && h==HIGH)
{
  analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(20);
  if(a==HIGH && b==HIGH && c==HIGH && d==HIGH && e==HIGH && f==HIGH && g==HIGH && h==HIGH)
  {
  analogWrite(lm1,225);
  digitalWrite(lm2,LOW);
  analogWrite(rm1,225);
  digitalWrite(rm2,LOW);
  delay(240);
    turnover();
    /*search();
    delay(1);*/
  }
  else {
    goto WELCOME;
    }
}

}

void done()
{
  //Serial.println("+ Motors off");
  digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
  replaystage=1;
  path[pathLength]='D';
  pathLength++;
 while(digitalRead(dobba)==HIGH)
 {
   digitalWrite(led, LOW);
   delay(350);
   digitalWrite(led, HIGH);
   delay(350);
 }
 delay(500);
  replay();
}

void straight()
{
  //coordinates();
  if( digitalRead(ss5)==HIGH || digitalRead(ss3)==LOW ){
    analogWrite(lm1, 225);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 225);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 225);//changing from 220 to high
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
  if(digitalRead(ss4)==HIGH || digitalRead(ss6)==LOW ){
    analogWrite(lm1, 225);
    digitalWrite(lm2, LOW);
    analogWrite(rm1, 225);
    digitalWrite(rm2, LOW);
    delay(1);
    analogWrite(lm1, 225);//changing from 220 to high
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);
    return;
  }
 
    analogWrite(lm1, 225);
    digitalWrite(lm2, LOW);
   analogWrite(rm1, 225);
    digitalWrite(rm2, LOW);
    delay(5);
    
  }

void leftturn()
{
  /*if(dir=='N')
  {
    dir='W';
  }
  else if(dir=='E')
  {
    dir='N';
  }
  else if(dir=='S')
  {
    dir='E';
  }
  else if(dir=='W')
  {
    dir='S';
  }
   coordinates();*/
   while(digitalRead(ss1)==HIGH){
    digitalWrite(lm1, LOW);
   analogWrite(lm2, 255);
    analogWrite(rm1, 255);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }
    while(digitalRead(ss5)==HIGH || digitalRead(ss4)==HIGH)
    {//previously it was ss4 and ss3 (changed based on obstacle code)
    digitalWrite(lm1, LOW);
    analogWrite(lm2, 255);
    analogWrite(rm1, 255);
    digitalWrite(rm2, LOW);
    delay(1);//the below comment lines are not commented in obstacle code
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);*/
    }
    if(digitalRead(ss5)==LOW)
    {// previously it was ss4 (changed based on obstacle code)
      //the entire condition is changed go through original code before any further changes
      //CHECK AGAIN
      analogWrite(lm1, 0);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      analogWrite(rm2, 0);
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
    Serial.print("Path length: ");
    Serial.println(pathLength);
      if(path[pathLength-2]=='B'){
        Serial.println("shortening path");
        shortPath();
      }
  }
      
  }

void turnover()
{
  /*if(dir=='N')
  {
    dir='S';
  }
  else if(dir=='E')
  {
    dir='W';
  }
  else if(dir=='S')
  {
    dir='N';
  }
  else if(dir=='W')
  {
    dir='E';
  }
   coordinates();*/
  while(digitalRead(ss8)==HIGH){
    analogWrite(lm1, 225);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 225);
    delay(1);//below lines are not commented in obstacle code
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }

    while(digitalRead(ss5)==HIGH || digitalRead(ss4)==HIGH)
    {//changing from ss5 & ss6 to ss4 & ss5
      //below conditions also changed
      //if further changes required, then check with original and
    analogWrite(lm1, 225);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 225);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);*/
    }
    if(digitalRead(ss5)==LOW){
      digitalWrite(lm1, LOW);
      analogWrite(lm2, 0);
      analogWrite(rm1, 0);
      digitalWrite(rm2, LOW);
      delay(5);
      /*digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(3);*/
      }
      path[pathLength]='B';
  pathLength++;
  straight();
      
  }

void rightturn()
{
  /*if(dir=='N')
  {
    dir='E';
  }
  else if(dir=='E')
  {
    dir='S';
  }
  else if(dir=='S')
  {
    dir='W';
  }
  else if(dir=='W')
  {
    dir='N';
  }
   coordinates();*/
    while(digitalRead(ss8)==HIGH)
    {
      Serial.println("X");
    digitalWrite(lm1, 255);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2,255);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(1);*/
    }

    while(digitalRead(ss5)==HIGH || digitalRead(ss6)==HIGH)
    {
      Serial.println("Y");
      //check the above condition again
    analogWrite(lm1, 255);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 255);
    delay(3);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);*/
    }
    if(digitalRead(ss4)==LOW){
      /*digitalWrite(lm1, LOW);
      analogWrite(lm2, 240);
      analogWrite(rm1, 240);
      digitalWrite(rm2, LOW);
      delay(1);*/
      Serial.println("Z");
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);//5
      }
      if(replaystage==0){
  path[pathLength]='R';
  //Serial.println("r");
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
    Serial.println("test1");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='L' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
    Serial.println("test2");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='R' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
    Serial.println("test3");
    shortDone=1;
  }
  
   
  if(path[pathLength-3]=='S' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
    Serial.println("test4");
    shortDone=1;
  }
     
  if(path[pathLength-3]=='S' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
    Serial.println("test5");
    shortDone=1;
  }
    if(path[pathLength-3]=='L' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='S';
    Serial.println("test6");
    shortDone=1;
  }
  
  path[pathLength+1]='D';
  path[pathLength+2]='D';
  pathLength++;
  Serial.print("Path length: ");
  Serial.println(pathLength);
  printPath();
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


void replay()
{ 
  //Serial.println("Entering replay function");
   readsensors();
  if(a==LOW && h==LOW)
  {
   Serial.println("Entering condition a==low or h==low");
    straight();
  }
  else
  {
      Serial.println("Entering else condition");
    if(path[readLength]=='D')
    {
       Serial.println(" path[readLength]==D So ending motion");
       digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(175);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);*/
      endMotion();
    }
    if(path[readLength]=='L'){
     digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(240);
      leftturn();
    }
    if(path[readLength]=='R'){
       digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(240);
    rightturn();
    }
    if(path[readLength]=='S'){
       digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(175);
    straight();
    }
    
    readLength++;
  }
    
  replay();
  
}

void endMotion()
{
    digitalWrite(led, LOW);
    delay(100);
    digitalWrite(led, HIGH);
    delay(100);
      digitalWrite(led, LOW);
    delay(240);
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
  endMotion();
}
/*void coordinates()
{
  /*a) If current direction is North, then ‘L’ changes direction to West and ‘R’ changes to East
b) If current direction is East, then ‘L’ changes direction to North and ‘R’ changes to South
c) If current direction is South, then ‘L’ changes direction to East and ‘R’ changes to West
d) If current direction is West, then ‘L’ changes direction to South and ‘R’ changes to North.
         
         if (dir == 'N')
         {
            y++;
         }
         else if (dir == 'E')
          {
            x++;
          }
         else if (dir == 'S')
           {
            y--;
           }
         else if (dir == 'W')
            {
            x--;     
            }
            arrX[i]=x;
            arrY[j]=y;
            i++;
            j++;
  }
void search()
{
  int l=0;
  for(int k=0;k<i;k++)
  {
    if (arrX[x]==arrX[k])
  {
   if(arrY[y]==arrY[l])
  {
    turnover(); 
 
  }
}
l++;
  }
}*/


