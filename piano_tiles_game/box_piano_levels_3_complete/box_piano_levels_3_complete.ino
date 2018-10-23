/* Project Title: Piano Tiles Game Using LED Box
 * Connect the circuit as per the below mentioned ir,r,g array starting from 1,2,3......
 * R Led in the RGB led is not used.
 * Always check grounding conditions. Repeatedly facing lose connectivity issues. Check them out before start of the game.  */
int ir[12]={53,46,24,26,30,33,A13,36,A8,A0,13,10};
int g[12]={50,47,27,28,31,35,A7,39,A5,A1,11,A11};
int b[12]={52,23,25,29,32,34,A14,37,A9,A2,12,8};

int score[12];
long interval=5000;
long previousMillis=0;
int i,j,k=0;//index variables for various arrays. Use case changes from function to function
int flag2,flag1,flag3=0;//counter variable to check if a particular level is completed or not
long total=0;
int q,r,s,t=0;//variables to generate randomised cells
int check1,check2=0;//variable to control the entry of compiler into randomised number generator function only once for a particular level

int l[12];
unsigned long currentMillis = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(i=0;i<12;i++)
{
  pinMode(ir[i],INPUT);
  pinMode(g[i],OUTPUT);
  pinMode(b[i],OUTPUT);
}
}

void loop() 
{
     currentMillis = millis();
     if(total<3)
     level1();
     else if( (total>=3) && (total<6) )
     level2();  
     else if( (total>=6) && (total<11) )
     level3();
     /*else 
     gameOver();*/
     
   total=score[0]+score[2]+score[1]+score[3]+score[4]+score[5]+score[6]+score[7]+score[8]+score[10]+score[9]+score[11];
  
    Serial.print("Total Score=");
    Serial.println(total);
    
    
}


void level1()
{
 if(flag1<1)
 {
  if(l[0]<1)
 digitalWrite(g[0],HIGH);
 if(l[1]<1)
 digitalWrite(b[1],HIGH);
 if(l[2]<1)
{
 digitalWrite(g[2],HIGH);
 digitalWrite(b[2],HIGH);
}
 }
 if(digitalRead(ir[0])==0)
 {
  if(l[0]<1)
  {
 digitalWrite(g[0],LOW);
 score[0]++;
 l[0]++;
   }
 }
  if(digitalRead(ir[1])==0)
  {
    if(l[1]<1)
    {
    digitalWrite(b[1],LOW);
    score[1]++;
    l[1]++;
     
    }
  }
  if(digitalRead(ir[2])==0)
  {
    if(l[2]<1)
    {
    digitalWrite(g[2],LOW);
    digitalWrite(b[2],LOW);
    score[2]++;
    l[2]++;
     
    }
  }
  
  
  //l++;
  if (currentMillis - previousMillis >= interval)
 {
     previousMillis = currentMillis;
     digitalWrite(g[0],LOW);
 digitalWrite(b[1],LOW);
 digitalWrite(g[2],LOW);
 digitalWrite(b[2],LOW);
  flag1++; 
  l[0]=l[1]=l[2]=l[3]=l[4]=l[5]=l[6]=l[7]=l[8]=l[9]=l[10]=l[11]=0;
 }
}





void level2()
{
  random_generate();//function generates random q,r,s values
  //q=3;r=4;s=5;
  check1=1;
  //Making the next 3 leds to glow
 if(flag2<1)
 {
  if(l[q]<1)
 digitalWrite(g[q],HIGH);
 if(l[r]<1)
 digitalWrite(b[r],HIGH);
 if(l[s]<1)
{
 digitalWrite(g[s],HIGH);
 //digitalWrite(b[s],HIGH);
}
 }
 if(digitalRead(ir[q])==0)
 {
  if(l[q]<1)
  {
 digitalWrite(g[q],LOW);
 score[q]++;
 l[q]++;
   }
 }
  if(digitalRead(ir[r])==0)
  {
    if(l[r]<1)
    {
    digitalWrite(b[r],LOW);
    score[r]++;
    l[r]++;
     
    }
  }
  if(digitalRead(ir[s])==0)
  {
    if(l[s]<1)
    {
    digitalWrite(g[s],LOW);
    //digitalWrite(b[s],LOW);
    score[s]++;
    l[s]++;
     
    }
  }
  
  
  if (currentMillis - previousMillis >= 3000)
 {
     previousMillis = currentMillis;
     digitalWrite(g[q],LOW);
 digitalWrite(b[r],LOW);
 digitalWrite(g[s],LOW);
 //digitalWrite(b[s],LOW);
  flag2++; 
  l[0]=l[1]=l[2]=l[3]=l[4]=l[5]=l[6]=l[7]=l[8]=l[9]=l[10]=l[11]=0;
 }
}



void level3()
{
  
  random_generate_2();//function generates random q,r,s values
  check2=1;
  //q=3;r=4;s=5;
  
  //Making the next 3 leds to glow
 if(flag3<1)
 {
  if(l[q]<1)
 digitalWrite(g[q],HIGH);
 if(l[r]<1)
 digitalWrite(b[r],HIGH);
 if(l[s]<1)
{
 digitalWrite(g[s],HIGH);
 //digitalWrite(b[s],HIGH);
}
if(l[t]<1)
{
digitalWrite(g[t],HIGH);
digitalWrite(b[t],HIGH);
 }

 }


 //Taking Readings
  if(digitalRead(ir[q])==0)
 {
  if(l[q]<1)
  {
 digitalWrite(g[q],LOW);
 score[q]++;
 l[q]++;
   }
 }
  if(digitalRead(ir[r])==0)
  {
    if(l[r]<1)
    {
    digitalWrite(b[r],LOW);
    score[r]++;
    l[r]++;
     
    }
  }
  if(digitalRead(ir[s])==0)
  {
    if(l[s]<1)
    {
    digitalWrite(g[s],LOW);
    //digitalWrite(b[s],LOW);
    score[s]++;
    l[s]++;
     
    }
  }

  if(digitalRead(ir[t])==0)
  {
    if(l[t]<1)
    {
    digitalWrite(g[t],LOW);
    digitalWrite(b[t],LOW);
    score[t]+=2;
    l[t]++;
     
    }
  }
  
  
  if (currentMillis - previousMillis >= 2500)
 {
     previousMillis = currentMillis;
     digitalWrite(g[q],LOW);
 digitalWrite(b[r],LOW);
 digitalWrite(g[s],LOW);
 digitalWrite(g[t],LOW);
 digitalWrite(b[t],LOW);
   flag3++; 
  l[0]=l[1]=l[2]=l[3]=l[4]=l[5]=l[6]=l[7]=l[8]=l[9]=l[10]=l[11]=0;
 }
}



void random_generate()
{
  if (check1==0) 
  {
  l[0]=l[1]=l[2]=l[3]=l[4]=l[5]=l[6]=l[7]=l[8]=l[9]=l[10]=l[11]=0;
  q=random(0,6);
  r=random(6,11);
  s=random(2,9);
  t=random(0,5);
  //Below Lines for debugging 
  /*Serial.print("q=");
  Serial.println(q);
  Serial.print("r=");
  Serial.println(r);
  Serial.print("s=");
  Serial.println(s);*/
  
  }
  
}



void random_generate_2()
{
  if (check2==0) 
  {
  l[0]=l[1]=l[2]=l[3]=l[4]=l[5]=l[6]=l[7]=l[8]=l[9]=l[10]=l[11]=0;
  q=random(0,6);
  r=random(6,11);
  s=random(2,9);
  t=random(0,5);
  }
}

void gameOver()
{
  total=score[0]+score[2]+score[1]+score[3]+score[4]+score[5]+score[6]+score[7]+score[8]+score[10]+score[9]+score[11];
  
    Serial.print("Total Score=");
    Serial.println(total);
    //delay(50000);
}

 
   /*   
 void test()
 {
  if (currentMillis - previousMillis <= interval)
 {
   previousMillis = currentMillis;
    j=random(1,12);
   if(j>6)
   {
   k=random(j,12);
   }
   else
   {
     k=random(1,j);
   }
   digitalWrite(g[j],LOW);
   digitalWrite(b[k],HIGH );
   int a=digitalRead(ir[j]);
   int b=digitalRead(ir[k]);
   if(a==0)
   {
  //  digitalWrite(g[j],HIGH);
    score++;
    if(b==0)
    {
//      digitalWrite(b[k],HIGH);
    score++;
    }
   }
   l++;
 }
 }
    
    

*/
