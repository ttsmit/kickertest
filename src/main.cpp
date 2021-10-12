/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
//#include "Serial.h" 

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define Charge_pin 5  
#define Kick_pin 3
#define Chip_pin 4
#define Charge_done_pin 2

void setup()
{
  // initialize LED digital pin as an output.
  pinMode(Charge_pin, OUTPUT);
  pinMode(Kick_pin, OUTPUT);
  pinMode(Chip_pin, OUTPUT);
  pinMode(Charge_done_pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(9600);
  Serial.println("Beginning.");
}

void loop()
{
  delay(2000); // Wait for two seconds
  // Make sure pins are set to right configuration
  digitalWrite(Kick_pin, LOW);
  digitalWrite(Chip_pin, LOW);
  Serial.print("Starting Charge");
  digitalWrite(Charge_pin, HIGH);
  
  unsigned int now = millis();
  // Charge for half a second (5 times 10Hz)
  digitalWrite(LED_BUILTIN, HIGH);
  while(millis() < now + 500){
	  int charge_time = millis() - now;
	  bool done = digitalRead(Charge_done_pin);
	  Serial.print("Charging \t");
	  Serial.print(charge_time);
	  Serial.print("\t");
	  Serial.println(done);
  }
  digitalWrite(Charge_pin, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("Done Charging, shooting in one second.");

  // wait for a second
  delay(1000);

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("Shoot Kicker!");
  digitalWrite(Kick_pin, HIGH);
  delay(10);
  digitalWrite(Kick_pin, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  // wait indefinately
  while(true);
}
