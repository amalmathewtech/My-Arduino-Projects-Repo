int ledPin=13;
int sensorPin=7;
boolean val =0;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin (9600);
}
  
void loop ()
{
  val =digitalRead(sensorPin);
  Serial.println (val);
  // when the sensor detects a signal above the threshold value, LED turns off based on delay
  if (val==HIGH) 
  { 
    digitalWrite(ledPin, LOW );
    delay(2000);   // turns off for 2 seconds  
  
  }
    else 
  {
    digitalWrite(ledPin, HIGH);
  }
}
