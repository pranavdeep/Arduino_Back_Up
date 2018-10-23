int ir[12]={53,46,24,26,30,33,A13,36,A8,A0,13,10};
int g[12]={50,47,27,28,31,35,A7,39,A5,A1,11,A11};
int b[12]={52,23,25,29,32,34,A14,37,A9,A2,12,8};

int score[12];
long interval=5000;
long previousMillis=0;
int i,j,k,flag=0;
long total=0;

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
     set1();
   
    
    total=score[0]+score[2]+score[1];
  
    Serial.print("Total Score=");
    Serial.println(total);
}


void set1()
{
 if(flag<1)
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
 }
  //l++;
  if (currentMillis - previousMillis >= interval)
 {
     previousMillis = currentMillis;
     digitalWrite(g[0],LOW);
 digitalWrite(b[1],LOW);
 digitalWrite(g[2],LOW);
 digitalWrite(b[2],LOW);
  flag++; 
 }
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
