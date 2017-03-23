#include <Wire.h>
#include "RTClib.h" //Include the RTC and Wire Library

RTC_DS1307 rtc;
int LEDpin1 = 11; //Red
int LEDpin2 = 10; //Green
int LEDpin3 = 9; //Blue
int SensorPin = A0; //LDR

void setup () {
  Serial.begin(9600); //Begin Serial Monitor at 9600 BAUD
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1); // If the RTC cannot be found while turned on, print "Couldn't find RTC" on serial monitor
  } else {
    Serial.println("Found RTC"); //Otherwise, print "Found RTC" to serial monitor
  }

  if (! rtc.isrunning()) {
    Serial.print("RTC is NOT running");
    //following lines sets the RTC to date and time this sketch was made
    rtc.adjust (DateTime(F(__DATE__), F(__TIME__)));
  }  else {
    Serial.println("RTC is running");
  }
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT); // Turn on the RGB LED
}

void loop () {
  DateTime n = rtc.now(); // Gather time and date from RTC module

  /*Serial.print(n.year(), DEC);
    Serial.print("/");
    Serial.print(n.month(), DEC);
    Serial.print("/");
    Serial.print(n.day(), DEC);
    //Serial.print(" ");*/
  Serial.print(n.hour(), DEC);
  /*Serial.print(":");
    Serial.print(n.minute(), DEC);
    Serial.println();*/ //Seperates the given information to print in a user-friendly way

  int Lightvalue = analogRead(SensorPin); //Read the Light Dependant Resistor (LDR)
  float lightMulti = map(Lightvalue, 0, 1023, 100, 1000) / 1000; // To give a light value between 0 and 1, simulating an analogue result
  int Timevalue = (n.hour(), DEC);

  switch (Timevalue) {
    case 1:
      analogWrite (LEDpin1, 255 * lightMulti); //Red
      analogWrite (LEDpin2, 0 * lightMulti);
      analogWrite (LEDpin3, 0 * lightMulti);
      break;
    case 2:
      analogWrite (LEDpin1, 255 * lightMulti) ; //Orange
      analogWrite (LEDpin2, 127 * lightMulti);
      analogWrite (LEDpin3, 0 * lightMulti);
      break;
    case 3:
      analogWrite (LEDpin1, 255 * lightMulti); //Mango
      analogWrite (LEDpin2, 196 * lightMulti);
      analogWrite (LEDpin3, 0 * lightMulti);
      break;
    case 4:
      analogWrite (LEDpin1, 255 * lightMulti); //Yellow
      analogWrite (LEDpin2, 255 * lightMulti);
      analogWrite (LEDpin3, 0 * lightMulti);
      break;
    case 5:
      analogWrite (LEDpin1, 190 * lightMulti); //Lime
      analogWrite (LEDpin2, 255 * lightMulti);
      analogWrite (LEDpin3, 0 * lightMulti);
      break;
    case 6:
      analogWrite (LEDpin1, 0 * lightMulti);  //Green
      analogWrite (LEDpin2, 255 * lightMulti);
      analogWrite (LEDpin3, 0 * lightMulti);
      break;
    case 7:
      analogWrite (LEDpin1, 0 * lightMulti); //Cyan
      analogWrite (LEDpin2, 255 * lightMulti);
      analogWrite (LEDpin3, 255 * lightMulti);
      break;
    case 8:
      analogWrite (LEDpin1, 0 * lightMulti);  //Sky Blue
      analogWrite (LEDpin2, 125 * lightMulti);
      analogWrite (LEDpin3, 255 * lightMulti);
      break;
    case 9:
      analogWrite (LEDpin1, 0 * lightMulti); // Dark BLue
      analogWrite (LEDpin2, 0 * lightMulti);
      analogWrite (LEDpin3, 255 * lightMulti);
      break;
    case 10:
      analogWrite (LEDpin1, 183 * lightMulti); //Purple
      analogWrite (LEDpin2, 0 * lightMulti);
      analogWrite (LEDpin3, 255 * lightMulti);
      break;
    case 11:
      analogWrite (LEDpin1, 255 * lightMulti); //Magenta
      analogWrite (LEDpin2, 0 * lightMulti);
      analogWrite (LEDpin3, 255 * lightMulti);
      break;
    case 12:
      analogWrite (LEDpin1, 255 * lightMulti); //White
      analogWrite (LEDpin2, 255 * lightMulti);
      analogWrite (LEDpin3, 255 * lightMulti);
      break;
  }

}



