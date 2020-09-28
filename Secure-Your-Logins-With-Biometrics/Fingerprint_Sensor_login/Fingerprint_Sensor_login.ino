
#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include <Keyboard.h>

int getFingerprintIDez();
//Connecting the Fingerprint Senosor to the  Micro :
//please refer internet  to find pinout of fingerprint sensor model ,if you find different color wire than specified below
//Pin #10/RX (Blue wire from sensor)
//Pin #16/TX (Yellow wire from sensor )

SoftwareSerial mySerial(16, 10);  // (TX,RX)

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor! Your computer is locked now!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    
  }
  Serial.println("Waiting for valid finger...");
}

void loop()                     
{
  getFingerprintIDez();
  delay(0);            
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }



  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 
}

int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  //Enter your passwords here
  // 
  if(finger.fingerID==0)      
  Keyboard.print("p@sSw0Rd");
  Keyboard.press(0xB0); //  refer https://www.arduino.cc/en/Reference/KeyboardModifiers
  Keyboard.releaseAll();
  //Here you can add more code 
  //for example see below code
  //if(finger.fingerID==1)
  //Keyboard.print("Em@1LpASSw0RD");  
  //Keyboard.press(0xB0); 
  //Keyboard.releaseAll();
return finger.fingerID; 
}

