int g[12]={50,47,27,28,31,35,A7,39,A5,A1,11,A11};
int q[5];
int l[12];
int i;
int check1;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  random_generate();
digitalWrite(g[q[i]],HIGH);
i++;
}

void random_generate()
{
  if ( check1==0) 
  {
  l[0]=l[1]=l[2]=l[3]=l[4]=l[5]=l[6]=l[7]=l[8]=l[9]=l[10]=l[11]=0;
  q[0]=random(0,6);
  q[1]=random(6,11);
  q[3]=random(2,9);
  q[2]=random(0,5);
  }
}

