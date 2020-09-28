#include <Keyboard.h>

const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value 


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin


void setup() 
{
  
   Keyboard.begin();
}

void loop() 
{
  // read the sensor and store it in the variable sensorReading:
  

sensorReading = analogRead(knockSensor);

  // if the sensor reading is greater than the threshold:
 
 if (sensorReading >= threshold) 
{
   
// to customize key function change ASCII values below  , refer  https://www.arduino.cc/en/Reference/ASCIIchart

    Keyboard.write(32);      //ASCII value of Space bar is 32 ,
    delay(150);
    Keyboard.releaseAll();
    
  }

}
