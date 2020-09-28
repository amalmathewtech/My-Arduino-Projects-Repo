#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

// For stats that happen every 5 seconds
unsigned long last = 0UL;


int ledPin = 13;


void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);

pinMode(ledPin, OUTPUT);
}

void loop()
{
  // Dispatch incoming characters
  while (ss.available() > 0)
    gps.encode(ss.read());

  if (gps.location.isUpdated())
  {
    
    Serial.print(F("  Lat="));
    Serial.print(gps.location.lat(), 6);
    Serial.print(F(" Long="));
    Serial.println(gps.location.lng(), 6);
  }



  else if (millis() - last > 5000)
  {
    Serial.println();
    if (gps.location.isValid())
    {

      // replace 'Dest_LAT' and 'Dest_LON' values basedon your location  
      // you can find Latitude and Longitude from Read_Lat_Lng.ino  
      static const double Dest_LAT = 18.786254, Dest_LON = 73.880798;
      double distanceToDest =
        TinyGPSPlus::distanceBetween(
          gps.location.lat(),
          gps.location.lng(),
          Dest_LAT, 
          Dest_LON);
      

      Serial.print(F("Distance to Destination ="));
      Serial.print(distanceToDest/1000, 6);       // *Prints distance to destination 
      
      if(distanceToDest/1000 < 0.050000)   //Here when distanceToDest/1000 is less than  0.050000  LED turns on . So change *distance to destination as per your requirement. 
      {
        digitalWrite(ledPin, HIGH);
      }
      else
      {
        digitalWrite(ledPin, LOW);
      }
    }

   

    if (gps.charsProcessed() < 10)
      Serial.println(F("WARNING: No GPS data.  Check wiring."));

    last = millis();
    Serial.println();
  }
}
