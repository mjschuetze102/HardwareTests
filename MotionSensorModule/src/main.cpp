#include <Arduino.h>

#define sensor 14
 
void setup() {
  pinMode(sensor, INPUT);

  Serial.begin(9600);
}
 
void loop(){
  bool motion = digitalRead(sensor);
  
  if (motion) {
    Serial.println("~~~~~~ Motion detected ~~~~~~");
  } else {
    Serial.println("No motion detected");
  }
}