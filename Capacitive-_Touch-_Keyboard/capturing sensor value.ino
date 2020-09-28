#include <CapacitiveSensor.h>
CapacitiveSensor cs_2_4 = CapacitiveSensor(2,4); // any resistor value between 100 kilo ohm to 50mega ohm   resistor between pins 2 & 4,
                                                 //I recommend you to use a resistor from 1 mega ohm to 5 mega ohm 
                                                 //pin 4 is sensor pin, add wire, foil
void setup()
{
cs_2_4.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example Serial.begin(9600);
}
void loop(){
long start = millis();
long total1 = cs_2_4.capacitiveSensor(30);  //sensor resoultion. Default 30.
                                           // increase for higher resolution, but slower performance.
Serial.print(millis() - start);           // check on performance in milliseconds
Serial.print("\t");                       //tab character for debug window spacing
Serial.println(total1);                   // print sensor output 1
delay(10);                                // arbitrary delay to limit data to serial port
}

