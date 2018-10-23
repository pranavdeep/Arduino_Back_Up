char initial[3]={};
char stack[3]={};
void sort()
{
  if(initial[2]==stack[0]
  {
    if(initial[1]==stack[1])
    {
      endMotion();
    }
    else if(initial[1]==stack[0])
    {
      obstacle();
      linefollow();//keep priority left in this function
       delay(100);
      drop();
      delay(100);
      turnover();
      linefollow1();//keep priority right in this function
      obstacle();
      linefollow1();
      delay(100);
      drop();
      delay(100);
      turnover();
      linefollow2();
      obstacle();
      linefollow1();
      //straight();
       if ( ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
       {
        while(flag==1)
        {
          digitalWrite(lm1,HIGH);
           digitalWrite(lm2,LOW);
          digitalWrite(rm1,HIGH);
           digitalWrite(rm2,LOW);
          if ( ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
          {
         flag++;
          }
        }
       }
       drop();
       delay(100);
       turnover();
       linefollow1();
       obstacle();
       linefollow();
    if ( ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
    {
      drop();
      delay(100);
    }
    turnover();
    delay(100);
   if ( ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
   {
    endMotion();
   }
    }
    }
  //second base condition in sorting
  else if(initial[2]==stack[1]
  {
    //linefollow2();
    obstacle();
      linefollow();
      if ( ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
       {
        while(flag1==1)
        {
          digitalWrite(lm1,HIGH);
           digitalWrite(lm2,LOW);
          digitalWrite(rm1,HIGH);
           digitalWrite(rm2,LOW);
          if ( ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
          {
         flag1++;
          }
        }
       }
       drop();
       delay(100);
       turnover();
      delay(100);
      linefollow1();
      obstacle();
     linefollow1();
if  ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
       {
        while(flag2==1)
        {
          digitalWrite(lm1,HIGH);
           digitalWrite(lm2,LOW);
          digitalWrite(rm1,HIGH);
           digitalWrite(rm2,LOW);
          if ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
          {
         flag2++;
          }
        }
       }
       drop();
       delay(100);
       turnover();
      delay(100);
      linefollow1();
      obstacle();
      linefollow();
      if(initial[1]==stack[0])
      {
    if ((digitalRead(ss1)==HIGH || digitalRead(ss2)==HIGH) && ( digitalRead(ss4)==HIGH || digitalRead(ss5)==HIGH ) && ( digitalRead(ss7)==HIGH || digitalRead(ss8)==HIGH ) )
    {
      drop();
      delay(100);
      turnover();
      
    }

      
        }
        
}

void obstacle()
{
  ultrasonic();
      while(distance<=2)
      {
        straight();
      }
      pickup();
      delay(100);
      turnover();
      delay(100);
}

