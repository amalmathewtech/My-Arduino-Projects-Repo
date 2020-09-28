 
#include <Servo.h>
Servo myservo; 
#define CTS1Pin 2 // Pin for capactitive touch sensor 1
#define CTS2Pin 3 // Pin for capactitive touch sensor 2
int pos;
void setup()                    
{
  
   myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()                    
{
int CTSValue1 = digitalRead(CTS1Pin);
int CTSValue2 = digitalRead(CTS2Pin);

if (CTSValue1 == HIGH)
 
 {
    for (pos = 0; pos <= 180; pos += 1)
    myservo.write(pos);
     delay(15); 
     
   }
   if(CTSValue2==HIGH)
   {  
    for (pos = 180; pos >= 0; pos -= 1)
    myservo.write(pos); 
    delay(15);
     
   }
   
}
