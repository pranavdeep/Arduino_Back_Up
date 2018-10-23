//initialising motor pins
int lm1 = 10;
int lm2 = 9;
int rm1 = 6;
int rm2 = 5;


//initialising sensor pins
int ss1 = 13;
int ss2 = 12;
int ss3 = 11;
int ss4 = 8;
int ss5 = 7;
int ss6 = 4;
int ss7 = 3;
int ss8 = 2;
int a, b, c, d, e, f, g, h;

//all temporary & counting variables declaration
int flag = 0; // this is the main counter variable that marks all the node points
int temp1 = 0, temp2=0;//these temp variables are for pointing to right & left at the end of each row in the grid
int temp=0 ; //
int i,j,k,l,p=0, node[10];
int temporary=0;//this variable is for line traversing in case of white nodes
int yes=0;//this variable is for knowing whether any two of the detected points are on a straight line or not
int mark1,mark2;
int yes_temp=0;


//declaring l1,l2,r1,r2
int length1,length2,breadth1,breadth2,length3,breadth3;
int c1=0,c2=0;

/*defining GRID
int a={1,10,11,20,21};//vertical straight line 1 
int b={2,9,12,19,22};//vertical straight line 2
int c={3,8,13,18,23};//vertical straight line 3
int d={4,9,14,19,24};//vertical straight line 4
int e={5,6,15,16,25};//vertical straight line 5*/

//initializing leds & buzzers
int red_led = A0;//red for square
int blue_led= A2 ;//blue for triangle
int green_led=A4;//green for rectangle
int buzzer = A1;// buzzer for node points


void setup() {
  // put your setup code here, to run once:
  pinMode(lm1, OUTPUT);
  pinMode(lm2, OUTPUT);
  pinMode(rm1, OUTPUT);
  pinMode(rm2, OUTPUT);

  pinMode(ss1, INPUT);
  pinMode(ss2, INPUT);
  pinMode(ss3, INPUT);
  pinMode(ss4, INPUT);
  pinMode(ss5, INPUT);
  pinMode(ss6, INPUT);
  pinMode(ss7, INPUT);
  pinMode(ss8, INPUT);

  pinMode(red_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void readsensors()
{
  a = digitalRead(ss1);
  b = digitalRead(ss2);
  c = digitalRead(ss3);
  d = digitalRead(ss4);
  e = digitalRead(ss5);
  f = digitalRead(ss6);
  g = digitalRead(ss7);
  h = digitalRead(ss8);
}


void loop() 
{
  // put your main code here, to run repeatedly:
    WELCOME :
  readsensors();
  if (a == HIGH && h == HIGH && ( d == LOW || e == LOW ))
  {
    straight();
    Serial.println("ENtering B1");
    Serial.print("flag=");
    Serial.println(flag);
    Serial.println("   ");
    //delay(2000);
  }
  
  else if ((a == LOW || b == LOW) && (d == LOW || e == LOW) && (g == LOW || h == LOW))
  { //base:ALL LOW
    just_check();
    if ( (digitalRead(ss1) == LOW && digitalRead(ss2) == LOW) && ( digitalRead(ss4) == LOW && digitalRead(ss5) == LOW ) && ( digitalRead(ss7) == LOW && digitalRead(ss8) == LOW ) )
    {
      Serial.println("ENtering B2");
     Serial.print("flag=");
    Serial.println(flag);
    Serial.println("   ");

      if(flag<=25)//25 because flag=25 indicates the end of the grid
      { 
        flag++;
        buzz();//indicating node point detection
        delay(65);//delay to be set
      }
      //delay(100);
      //halt();
      node_check();
      delay(20);
      white_node_check();
      delay(50);
      line_traverse();
    }
    else
    {
      goto WELCOME;
    }
  }

  else if ((a == LOW || b == LOW) && (e == LOW || d == LOW) && (h == HIGH || g == HIGH))
  { //BASE: STRAIGHT & LEFT PATHS AVAILABLE
    just_check();
    if ( (digitalRead(ss1) == LOW && digitalRead(ss2) == LOW) && ( digitalRead(ss4) == LOW || digitalRead(ss5) == LOW ) && ( digitalRead(ss7) == HIGH && digitalRead(ss8) == HIGH ) )
    {
      Serial.println("ENtering B3");
      Serial.print("flag=");
    Serial.println(flag);
    Serial.println("   ");
      if(flag<=25)
      {
        flag++;
        buzz();//indication of node detection
        delay(10);//delay to be set
      }
      
      node_check();
      delay(50);
      line_traverse();
    }
    else
    {
      goto WELCOME;
    }
  }//base condition ends
  else if ( a == HIGH && (g == LOW || h == LOW) && (e == LOW || d == LOW))
  { //BASE: STRAIGHT & RIGHT PATHS AVAILABLE
    just_check();
    if ( (digitalRead(ss1) == HIGH && digitalRead(ss2) == HIGH) && ( digitalRead(ss4) == LOW || digitalRead(ss5) == LOW ) && ( digitalRead(ss7) == LOW || digitalRead(ss8) == LOW ) )
    {
      Serial.println("Entering B4");
      Serial.print("flag=");
    Serial.println(flag);
    Serial.println("   ");
      if(flag<=25)
      {
        flag++;
        buzz();
        delay(10);//delay to be set

      }
      
      node_check();
      delay(50);
      line_traverse();
    }
    else
    {
      goto WELCOME;
    }
  }//base condition ends
    else if ((a == LOW || b == LOW) && (d == HIGH || e == HIGH) && (g == LOW || h == LOW))
    {//added base condition for detecting white node points
      just_check();
       if( ( (digitalRead(ss1)==LOW) || (digitalRead(ss2)==LOW)) && ( (digitalRead(ss4)==HIGH) || (digitalRead(ss5)==HIGH) ||  ) && ( (digitalRead(ss7)==LOW) || (digitalRead(ss8)==LOW) ) )
     {
              
          white_node_check();  
               
     }
    }//base condition ends
}//void loop ends

void buzz()
{
  digitalWrite(buzzer, HIGH);
  delay(25);
  digitalWrite(buzzer, LOW);
}

void line_traverse()
{
  if ( (digitalRead(ss4) == LOW) || (digitalRead(ss5) == LOW) )
  {
    straight();
    delay(1);  
  }
  if( (digitalRead(ss1)==LOW) && (digitalRead(ss2)==LOW) && (digitalRead(ss4)==HIGH) && (digitalRead(ss5)==HIGH) && (digitalRead(ss7)==LOW) && (digitalRead(ss8)==LOW) )
  {
    if(temporary==1)
    {
      half_distance();
      /*if ( (digitalRead(ss4) == LOW) || (digitalRead(ss5) == LOW) )
  {
    straight();
    delay(1);  
  }// small if ends*/
      
  }//temporary if ends
  }//white node checking if ends
  
}//line_traverse ends





void node_check()
{
  if (flag == 1)
  {
    half_distance();
    rightturn();
    delay(1);
  }
  else if(flag==25)
  {
    stop1();
    
  }
  else if ( (flag % 5 == 0) || ( (flag - 1) % 5 == 0) )
  {
    //x = 1;
    if (flag % 5 == 0)
    {

      if (temp1 == 0)
      {
        half_distance();
        leftturn();
        temp1 = 1;
        delay(1);
      }
      else
      {
        half_distance();
        rightturn();
        temp1 = 0;
        delay(1);
      }
    }//end of flag%5 if
    else
    {
      if (temp2 == 0)
      {
        half_distance();
        leftturn();
        temp2 = 1;
        delay(1);
      }
      else
      {
        half_distance();
        rightturn();
        temp2 = 0;
        delay(1);
      }//else ends
    }//main else ends
  }//if condition ends
  //white_node_check();
}//node_check ends

void half_distance()
{
  digitalWrite(lm1, HIGH);
  digitalWrite(lm2, LOW);
  digitalWrite(rm1, HIGH);
  digitalWrite(rm2, LOW);
  delay(155);//voltage=12.3
}

void stop1()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(1);
  
  digitalWrite(buzzer,HIGH);
  //digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  delay(500);

   main_check();
  stop1();
}

void main_check()
{
  straight_line_check_a();
  delay(1);
  straight_line_check_b();
  delay(1);
  straight_line_check_c();
  delay(1);
  straight_line_check_d();
  delay(1);
  straight_line_check_e();
  delay(1);
  /*Serial.print("yes=");
  Serial.println(yes);*/
  if( yes==1 )
  {
    /*Serial.print("i=");
    Serial.println(i);*/
    if(i==4)
    {//no. of node points=4 -->i=4 
    check_sq_rect();
    delay(1);
    }
    else if(i==3)
    {
    check_triangle();
    delay(1);
    }
    stop1();
    
  }
  
}
void check_sq_rect()
{
  //Serial.println("Entered this condition");
 print_nodes();
 delay(10);
  
  length1=node[0]-node[1];
 length1=abs(length1);
  length2=node[3]-node[2];
 length2=abs(length2);
   breadth1=node[3]-node[0];
  breadth1=abs(breadth1);
   breadth2=node[2]-node[1];
  breadth2=abs(breadth2);
  /*length3=node[1]-node[3];
 length3=abs(length3);
 breadth3=node[2]-node[0];
  breadth3=abs(breadth3);*/
 
  
  print_distance();
  delay(10);
    
  if( (length1==length2) && (breadth1==breadth2) && (length1==breadth2) && (length2==breadth1) )
  {//if this is true implies the geometric shape is a square
    Serial.println("Square identified");
    digitalWrite(red_led,HIGH);
    buzz1();
    delay(7500);
    digitalWrite(red_led,LOW);
  }
  else if( (length1==length2) && (breadth1==breadth2) && ( length1!=breadth2) && (length2!=breadth1) )
  {// length not equal to breadth implies a rectangle
    Serial.println("Rectangle identified");
    digitalWrite(green_led,HIGH);
    buzz1();
    delay(7500);
    digitalWrite(green_led,LOW);
  }
 
}

void check_triangle()
{
  digitalWrite(blue_led,HIGH);
  delay(7500);
  digitalWrite(blue_led,LOW);
}




void straight()
{
  if( digitalRead(ss5)==HIGH || digitalRead(ss3)==LOW ){
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
  if(digitalRead(ss4)==HIGH || digitalRead(ss6)==LOW ){
    digitalWrite(lm1, HIGH);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    digitalWrite(lm1, HIGH);;//changing from 230 to HIGH
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
    delay(1);
    
  }


  void leftturn(){
  while(digitalRead(ss1)==HIGH){
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
    while(digitalRead(ss4)==HIGH || digitalRead(ss3)==HIGH){
    digitalWrite(lm1, LOW);
    digitalWrite(lm2, HIGH); 
    digitalWrite(rm1, HIGH);
    digitalWrite(rm2, LOW);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(2);*/
    }
    if(digitalRead(ss5)==LOW){
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(2);
      }
      
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

    while(digitalRead(ss5)==HIGH || digitalRead(ss6)==HIGH){
    analogWrite(lm1, 255);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    analogWrite(rm2, 255);
    delay(1);
    /*digitalWrite(lm1, LOW);
    digitalWrite(lm2, LOW);
    digitalWrite(rm1, LOW);
    digitalWrite(rm2, LOW);
    delay(3);*/
    }
    if(digitalRead(ss4)==LOW){
      /*digitalWrite(lm1, LOW);
      analogWrite(lm2, 150);
      analogWrite(rm1, 150);
      digitalWrite(rm2, LOW);
      delay(1);*/
      digitalWrite(lm1, LOW);
      digitalWrite(lm2, LOW);
      digitalWrite(rm1, LOW);
      digitalWrite(rm2, LOW);
      delay(1);//5
      }
  }

  void just_check()
{
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(25);
}

void buzz1()
{
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
}

void white_node_check()
{
  //Serial.println("Entered white_node_check()");
  /*if( (digitalRead(ss1)==LOW) && (digitalRead(ss2)==LOW) && ((digitalRead(ss4)==HIGH) || (digitalRead(ss5)==HIGH)) && (digitalRead(ss7)==LOW) && (digitalRead(ss8)==LOW) )
  {*/
    just_check();
    
    //delay(100);
      /*if( ( (digitalRead(ss1)==LOW) || (digitalRead(ss2)==LOW)) && ( (digitalRead(ss4)==HIGH) || (digitalRead(ss5)==HIGH) || (digitalRead(ss6)==HIGH) ) && ( (digitalRead(ss7)==LOW) || (digitalRead(ss8)==LOW) ) )
     {*/
      //Serial.println("White Node Detected");
    flag++;
    buzz1();
    Serial.print("Flag=");
    Serial.println(flag);
    node[i]=flag;
    Serial.print("Storing node point=");
    Serial.println(flag);
    i++;
    temporary=1;//to go forward when a white node is detected, following the normal path
     //}//just check if ends
  //}//if ends
}//function ends

void straight_line_check_a()
{
  for(j=0;j<4;j++)
  {
   if( (node[j]==1) || (node[j]==2) || (node[j]==3) || (node[j]==4) || (node[j]==5) )
   {
    mark1=node[j];
    k=j+1;
    if( (node[k]==1) || (node[k]==2) || (node[k]==3) || (node[k]==4) || (node[k]==5) )
    {
      mark2=node[k];
      yes=1;
    }//end of mark2 if
    
   }//end of mark1 if
  }//end of for loop
  }//end of st line check_a



void straight_line_check_b()
{
  for(j=0;j<4;j++)
  {
   if( (node[j]==6) || (node[j]==7) || (node[j]==8) || (node[j]==9) || (node[j]==10) )
   {
    mark1=node[j];
    k=j+1;
    if( (node[k]==6) || (node[k]==7) || (node[k]==8) || (node[k]==9) || (node[k]==10) )
    {
      mark2=node[k];
      yes=1;
    }//end of mark2 if
    }//end of mark1 if
  }//end of for loop
}//end of st line check_a

void swap()
{
 int temp_11=node[2];
 node[2]=node[3];
 node[3]=temp_11;
 
}

  
void straight_line_check_c()
{
  for(j=0;j<4;j++)
  {
   if( (node[j]==11) || (node[j]==12) || (node[j]==13) || (node[j]==14) || (node[j]==15) )
   {
    mark1=node[j];
    k=j+1;
    if( (node[k]==11) || (node[k]==12) || (node[k]==13) || (node[k]==14) || (node[k]==15) )
    {
      mark2=node[k];
      yes=1;
    }//end of mark2 if
    
   }//end of mark1 if
  }//end of for loop
  //straight_line_check_d();
  delay(1);
  yes_temp=mark2-mark1;
  yes_temp=abs(yes_temp);
  if(yes_temp>1)
  {
    swap();
  }
}//end of st line check_a


void straight_line_check_d()
{
  for(j=0;j<4;j++)
  {
   if( (node[j]==16) || (node[j]==17) || (node[j]==18) || (node[j]==19) || (node[j]==20) )
   {
    mark1=node[j];
    k=j+1;
    if( (node[k]==16) || (node[k]==17) || (node[k]==18) || (node[k]==19) || (node[k]==20) )
    {
      mark2=node[k];
      yes=1;
      //yes_temp=1;
    }//end of mark2 if
    
   }//end of mark1 if
  }//end of for loop
}//end of st line check_a



void straight_line_check_e()
{
  for(j=0;j<4;j++)
  {
   if( (node[j]==21) || (node[j]==22) || (node[j]==23) || (node[j]==24) || (node[j]==25) )
   {
    mark1=node[j];
    k=j+1;
    if( (node[k]==21) || (node[k]==22) || (node[k]==23) || (node[k]==24) || (node[k]==25) )
    {
      mark2=node[k];
      yes=1;
    }//end of mark2 if
    
   }//end of mark1 if
  }//end of for loop
}//end of st line check_a


void halt()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  delay(150);
}



void print_nodes()
{
  Serial.print("1st node=");
  Serial.println(node[0]);
  Serial.print("2nd node=");
  Serial.println(node[1]);
  Serial.print("3rd node=");
  Serial.println(node[2]);
  Serial.print("4th node=");
  Serial.println(node[3]);
}
 void print_distance()
 {
  Serial.print("length1=");
  Serial.println(length1);
  Serial.print("length2=");
  Serial.println(length2);
  Serial.print("breadth1=");
  Serial.println(breadth1);
  Serial.print("breadth2=");
  Serial.println(breadth2);
  
 }

