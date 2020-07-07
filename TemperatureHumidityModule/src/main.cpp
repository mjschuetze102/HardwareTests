#include <Arduino.h>
#include <dht.h>

#define sensor A0

dht DHT;

float celsiusToFahrenheit(float);

void setup() {
    Serial.begin(9600);
    delay(1000);
}

void loop() {
    // Sensor can only read values every 2 seconds
    delay(2000);

    DHT.read11(sensor);

    Serial.print("Temperature: ");
    Serial.print(celsiusToFahrenheit(DHT.temperature));
    Serial.println("°F");

    Serial.print("Humidity: ");
    Serial.print(DHT.humidity);
    Serial.println("%");
}

/**
 * Converts celsius to fahrenheit
 * @param celsius - temperature in celsius
 * @return temperature in fahrenheit
 */
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}