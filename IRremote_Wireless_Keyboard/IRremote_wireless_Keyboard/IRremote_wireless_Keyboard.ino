//this is sample code that shows some example keyboard operaions
#include <IRremote.h>
#include <Keyboard.h>

int RECV_PIN = 16;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Keyboard.begin();
}

void loop() {
  if (irrecv.decode(&results)) 
  {
   
                  
      switch(results.value)
      {
        //The power button is used to unlock your PC
        case 0x1FE48B7:  Keyboard.print("P@@sW0rD"); // add your PC's Password here
                         Keyboard.press(KEY_RETURN); //Enter Key
                         delay(100);
                         Keyboard.releaseAll();
                         break;
        //Backward key is used for left key operation                 
        case 0x1FE40BF:  Keyboard.press(KEY_LEFT_ARROW); //left key
                         delay(100);
                         Keyboard.releaseAll();
                         break;
        //Forward Key is used for right key operation
        case 0x1FEC03F:  Keyboard.press(KEY_RIGHT_ARROW); //right  key
                         delay(100);
                         Keyboard.releaseAll();
                         break;  
        //Space bar operaion , It can be used for pause/play -0th key
        case 0x1FEE01F:  Keyboard.write(32);//space bar operation
                         delay(100);
                         Keyboard.releaseAll();
                         break; 
       //Select all operation(Ctrl+a)-1st key
        case 0x1FE50AF:  Keyboard.press(KEY_LEFT_CTRL);//Ctrl key
                         Keyboard.write(97);// ascii value of 'a' is 97
                         delay(100);
                         Keyboard.releaseAll();
                         break;
         //Copy Operation(Ctrl+c) -4th key              
        case 0x1FE30CF:  Keyboard.press(KEY_LEFT_CTRL);//Ctrl key
                         Keyboard.write(99);//ascii value of 'c' is 99
                         delay(100);
                         Keyboard.releaseAll();
                         break;
        //Paste Operation(Ctrl+v)-7th key
        case 0x1FE00FF:  Keyboard.press(KEY_LEFT_CTRL);//Ctrl key
                         Keyboard.write(118);//ascii value of 'v' is 118
                         delay(100);
                         Keyboard.releaseAll();
                         break;
        //closes  opened tab
        case 0x1FE9867:  Keyboard.press(KEY_LEFT_ALT);//Alt Key
                         Keyboard.press(KEY_F4);//F4 Key
                         delay(100);
                         Keyboard.releaseAll();
                         break;
                 
      }  
    irrecv.resume(); // Receive the next value
  }
}
