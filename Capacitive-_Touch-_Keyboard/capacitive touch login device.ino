#include <CapacitiveSensor.h>
#include <Keyboard.h>

CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4); // 1M resistor between pins 2 & 4, pin 4 is sensor pin, add any metallic object such as foil ,coin etc..


void setup()                    
{
   cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF);// turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
    Keyboard.begin();
   
}

void loop()                    
  {
 long sensor1 =  cs_2_4.capacitiveSensor(50);
 
   if(sensor1 >= 1000)
   {
  
  Keyboard.print("p@ssW0rD");      //Enter your password here
    Keyboard.press(KEY_RETURN); //Enter key
    delay(150);
    Keyboard.releaseAll();
    }
  }
