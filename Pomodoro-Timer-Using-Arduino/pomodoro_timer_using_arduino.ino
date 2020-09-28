/* Pomodoro Timer using Arduino
 * ---------------------------
 *
 * There are 3 modes of operation  
 * 1.Work mode(duration of 25 minutes)
 * 2.Short Break mode(duration of 5 minutes)
 * 3.Long break mode(duration of 20 minutes)
 * There are 4 LEDs to represent number of pomodoros completed (one pomodoro = 1 complete work mode)
 * There are 3 LEDs to represent mode(work mode (or) short break mode (or) long break mode)
 * after 4 pomodoro there will be a long break
 * one push button for start the pomodoro or to restart(after long break mode)  
 * Buzzer for indicating start and end of short break mode and long break mode 
 * As each mode works based on delay function  use inbuilt reset button on arduino  to restart the pomodoro(if required) 
 *
 *  The circuit:
  - pushbutton is attached to pin 2,push button's other leg is connected to ground. 
  - 10K resistor attached to pin 2 from +5v(externally pulled up)
  - buzzer is connected to pin 3 
  - workPeriodLED is connected to pin 4 
  - shortBreakLED is connected to pin 5 
  - longBreakLED is connected to pin 6 
  - pom1LED is connected to pin 7 
  - pom2LED is connected to pin 8 
  - pom3LED is connected to pin 9 
  - pom4LED is connected to pin 10 
 *
 *
 *
 * Created 14 July  2020
 * by Febin Joseph and Amal Mathew
 */

#define work 0
#define shortBreak 1
#define longBreak 2

int state = work;
int counter = 0;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;               // the number of the pushbutton pin

const int buzzer = 3;                  // buzzer to arduino pin 3
const int workPeriodLED = 4;           // Work Period indication LED to arduino pin 4
const int shortBreakLED = 5;           // Short Break period indication LED to arduino pin 5
const int longBreakLED  =  6;          // Long Break Period indication LED to arduino pin 6

//Indication for  number of Pomodoros completed
const int pom1LED =   7;                 
const int pom2LED =   8;
const int pom3LED =   9;
const int pom4LED =   10;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  // initialize following pins as  outputs:
  pinMode(buzzer, OUTPUT);              // Set buzzer - pin 3 as an output
  pinMode(workPeriodLED, OUTPUT);       // pin 4 as an output
  pinMode(shortBreakLED, OUTPUT);       // pin 5 as an output
  pinMode(longBreakLED, OUTPUT);        // pin 6 as an output
  pinMode(pom1LED, OUTPUT);             // pin 7 as an output
  pinMode(pom2LED, OUTPUT);             // Pin 8 as an output
  pinMode(pom3LED, OUTPUT);             // pin 9 as an output
  pinMode(pom4LED, OUTPUT);             // pin 10 as an output
  
  while(digitalRead(buttonPin) == 1);    //Wait until Push button is pressed to start pomodoro timer 
}

void loop() {
  if(state == work){
    workMode(); 
  }
  if(state == shortBreak){
    shortBreakMode();
  }
  if(state == longBreak){
    longBreakMode();
  }
}

void workMode(void){
  pomodoroStatus();
  digitalWrite(workPeriodLED, HIGH);
  digitalWrite(shortBreakLED, LOW);
  digitalWrite(longBreakLED, LOW);
  delay(1500000);          //25 minutes delay ,  25*60 seconds *1000   , 1 second = 1000 millisecond 
  counter++;
  if(counter <= 3){
    state = shortBreak;      //once workmode is completed move to short break
  }
   
  if(counter == 4){
    state = longBreak;
  }
}

void shortBreakMode(void){
  pomodoroStatus();
  digitalWrite(workPeriodLED, LOW);
  digitalWrite(shortBreakLED, HIGH);
  digitalWrite(longBreakLED, LOW);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);        
  delay(298000);   //around 5 minutes  
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  if(counter<=3){
    state = work;
  }

}

void longBreakMode(void){
  pomodoroStatus();
  digitalWrite(workPeriodLED, LOW);
  digitalWrite(shortBreakLED, LOW);
  digitalWrite(longBreakLED, HIGH);
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1198000);     //around 20 minutes    ‬
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  //Turn on all LEDs to represent 4 pomodoros has completed  completed   
  digitalWrite(workPeriodLED, HIGH);
  digitalWrite(shortBreakLED, HIGH);
  digitalWrite(longBreakLED, HIGH);
  while(digitalRead(buttonPin) == 1);  //once  4 pomodoro is over , restart pomodoro timer  by pressing push button
  //reset all variables and move to workmode 
  counter = 0;
  state = work;  
  
}

//This function is used to represent number of pomodoros 
void pomodoroStatus(void){
  if(counter == 0){
    digitalWrite(pom1LED, LOW);
    digitalWrite(pom2LED, LOW);
    digitalWrite(pom3LED, LOW);
    digitalWrite(pom4LED, LOW);
    
  }
  if(counter == 1){
    digitalWrite(pom1LED, HIGH); 
  }
  if(counter == 2){
    digitalWrite(pom1LED, HIGH);
    digitalWrite(pom2LED, HIGH);
  }
  if(counter == 3){
    digitalWrite(pom1LED, HIGH);
    digitalWrite(pom2LED, HIGH);
    digitalWrite(pom3LED, HIGH);
  }
  if(counter ==4){
    digitalWrite(pom1LED, HIGH);
    digitalWrite(pom2LED, HIGH);
    digitalWrite(pom3LED, HIGH);
    digitalWrite(pom4LED, HIGH);
  }

}
