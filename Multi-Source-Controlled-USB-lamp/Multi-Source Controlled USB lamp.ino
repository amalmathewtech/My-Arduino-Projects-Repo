int led =0;
int sensor=1;
int state1=HIGH;
boolean value=0;
int state2=LOW;



void setup()
{
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
}
void loop()
{
value=digitalRead(sensor);
if(value==HIGH && state2==LOW)
{
  if(state1==HIGH)
    state1=LOW;
  else
    state1=HIGH;
}
digitalWrite(0,state1);
state2=value;
}
