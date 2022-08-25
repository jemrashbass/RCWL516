#include <Arduino.h>
#define sensorPin 2 // RCWL-0516 connected to this pin
#define ledPin 5 // LED connected to this pin
int sensorVal = 0; // initial RCWL-0516 output value as seen by Nano
int led_fire_duration = 5000;

void setup() {

Serial.begin (115200); // initialize serial communication:

pinMode (sensorPin, INPUT);                               // RCWL-0516 output is input for Nano
pinMode (ledPin, OUTPUT);                                  // LED as OUTPUT
digitalWrite (ledPin, LOW);                                     // LED off at start
}

void loop(){

sensorVal = digitalRead (sensorPin);                     // read sensor value

if (sensorVal == LOW)
  {
   digitalWrite(ledPin, LOW);
   Serial.println("LED OFF");
   }

else
   {
   digitalWrite(ledPin, HIGH);
  Serial.println("LED OFF");
   delay (led_fire_duration);                                        // during this period the led will be ON
}
}
