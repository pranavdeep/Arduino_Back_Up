/* Project Title: Piano Tiles Game Using LED Box
 * Connect the circuit as per the below mentioned ir,r,g array starting from 1,2,3......
 * R Led in the RGB led is not used.
 * Always check grounding conditions. Repeatedly facing lose connectivity issues. Check them out before start of the game.  */
int ir[12]={53,46,24,26,30,33,A13,36,A8,A0,13,10};
int g[12]={50,47,27,28,31,35,A7,39,A5,A1,11,A11};
int b[12]={52,23,25,29,32,34,A14,37,A9,A2,12,8};


int score[12];
//long interval=5000;
long previousMillis=0;
int i,j,k=0;//index variables for various arrays. Use case changes from function to function
int q[12],l[12];
int 
unsigned long currentMillis = 0;
long total=0;
int check1=0;

void setup()
{
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
  {
     next_level(1,3,5000,false);
  }

    //total=score[0]+score[2]+score[1]+score[3]+score[4]+score[5]+score[6]+score[7]+score[8]+score[10]+score[9]+score[11];
     Serial.print("Total Score=");
    Serial.println(total);
}




//int next_level(level no.,no.of leds,speed,flag)

int next_level(int level,int leds,int interval,bool flag)
{
  
   
  if(flag == false)
  {
    if(check1==0)
    {
    random_generate();
    check1=1;
    for(i=0;i<leds;i++)
    {
    digitalWrite(g[q[i]],HIGH);
    }
    }
    else
    {
      while(1)
      {
        currentMillis=millis();
        /*int a=digitalRead(ir[q[k]]);
        Serial.println(a);
        Serial.print("k=");
        Serial.println(k);*/
        //if(digitalRead(ir[j])==0)
        //{
         //Serial.println("read something");
          if (currentMillis - previousMillis >= interval)
      {
             previousMillis = currentMillis;
             off();
             Serial.println("Game Over");
             return total;
      }
          
          if(digitalRead(ir[q[k]])==0)
          {
            if(l[q[k]]==0)
            {
            Serial.println("read correctly & incrementing score");
            digitalWrite(g[q[k]],LOW);
              //score[q[i]]++;
              l[q[k]]=1;
              total++;
            } 
              
              //total++;
          }
          /*else
          {
            Serial.println("read wrongly");
            gameover();
            return total;
            
          }*/    
              if(total>=15)
              {
                flag=true;
                return total;
              }
          
          
        //}  
         //Serial.println("while 1");
         if(j<11)
         j++;
         else if(j>=11)
         j=0;
         if(k<leds)
         k++;
         else if(k>=leds)
         k=0;

      }
       
      }
    }

    else if(flag==true)
    {
      Serial.println("level Completed");
      return total;
    }
      
    
  }



void random_generate()
{
  if (check1==0) 
  {
 l[0]=l[1]=l[2]=l[3]=l[4]=l[5]=l[6]=l[7]=l[8]=l[9]=l[10]=l[11]=0;
  q[0]=random(0,6);
  q[1]=random(6,11);
  q[2]=random(2,9);
  q[3]=random(0,5);
  q[4]=random(0,11);
  q[5]=random(5,10);
  //Below Lines for debugging 
  /*Serial.print("q=");
  Serial.println(q);
  Serial.print("r=");
  Serial.println(r);
  Serial.print("s=");
  Serial.println(s);*/
  
  }
  
}
void gameover()
{
  off();
  Serial.println("GAME OVER: Minimum Score not Reached");
  }

void off()
{
  for(i=0;i<12;i++)
  {
  digitalWrite(g[i],LOW);
digitalWrite(b[i],LOW);
  }
}
/*
digitalWrite(g2,LOW);
digitalWrite(b2,LOW);
digitalWrite(g3,LOW);
digitalWrite(b3,LOW);
digitalWrite(g4,LOW);
digitalWrite(b4,LOW);
digitalWrite(g5,LOW);
digitalWrite(b5,LOW);   
digitalWrite(g6,LOW);
digitalWrite(b6,LOW);
digitalWrite(g7,LOW);
digitalWrite(b7,LOW);
digitalWrite(g8,LOW);
digitalWrite(b8,LOW);
digitalWrite(g9,LOW);
digitalWrite(b9,LOW);
digitalWrite(g10,LOW);
digitalWrite(b10,LOW);
digitalWrite(g11,LOW);
digitalWrite(b11,LOW);
digitalWrite(g12,LOW);
digitalWrite(b12,LOW);*/



