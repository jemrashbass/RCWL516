#include <Arduino.h>
#define movement_signal 19 // RCWL-0516 connected to this pin
#define LedPin 5 // LED connected to this pin
int Sensor_State = 1; // initial RCWL-0516 output value as seen by Nano
//int led_fire_duration = 5000;

void setup() {

Serial.begin (115200); // initialize serial communication:

pinMode (movement_signal, INPUT);                               // RCWL-0516 output is input for Nano
pinMode (LedPin, OUTPUT);                                  // LED as OUTPUT
//digitalWrite (ledPin, LOW);                                     // LED off at start
}

void loop(){

int Sensor_State = digitalRead(movement_signal);
  if (Sensor_State == HIGH) {
    digitalWrite (LedPin, HIGH);
  }
  else { 
    digitalWrite (LedPin, LOW);
    }

   Serial.print("Motion sensor: ");
  Sensor_State = digitalRead(movement_signal);
  if (Sensor_State == 1) {
    Serial.println("Motion detected");
    //Serial.printf("vibration value = %.0f \n", Sensor_State);
  }
  else {
    Serial.println("All quiet");
  }

}
