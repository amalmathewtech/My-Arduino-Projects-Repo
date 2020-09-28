

#include <CapacitiveSensor.h>

CapacitiveSensor   cs_2_4 = CapacitiveSensor(2,4); // 10M ohm  resistor between pins 2 & 4, pin 4 is sensor pin, add a wire and or foil

int in = 2; 
int out = 4;  
         

void setup()
{
  Serial.begin(9600);  // // initialize serial communication at 9600 bits per second:
  pinMode(4, INPUT);
  pinMode(9, OUTPUT);
}
void loop()                    
{
  long start = millis();
long total1 = cs_2_4.capacitiveSensor(30);  //sensor resoultion. Default 30.
                                           // increase for higher resolution, but slower performance.
Serial.print(millis() - start);           // check on performance in milliseconds
Serial.print("\t");                       //tab character for debug window spacing
Serial.println(total1);                   // print sensor output 1
delay(10);                                // arbitrary delay to limit data to serial port

 
 if(total1>=140)        // change this based on serial Monitor's output 
 {
 analogWrite(9, total1); 
 
}
else
{
  digitalWrite(9,LOW);
}

}