#include <Arduino.h>

#define VRx A2
#define VRy A1
#define SW  14

int prevX, prevY;

bool approx(int val1, int val2);

void setup() {
    // Set the sensor input pins
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(SW, INPUT);

    // Turn on the serial monitor
    Serial.begin(9600);
}

void loop() {
    // Read values from the joystick
    int xVal = analogRead(VRx);
    int yVal = analogRead(VRy);
    bool button = !digitalRead(SW);

    // Detect change in joystick position
    if (!approx(prevX, xVal) || !approx(prevY, yVal)) {
        prevX = xVal;
        prevY = yVal;
        
        char coords[18];
        sprintf(coords, "Coords: %4d, %4d", xVal, yVal);
        Serial.println(coords);
    }

    // Detect if button was pressed
    if (button)
        Serial.println("Button Pressed");
    
    delay(10);
}

/**
 * Computes whether two values are approximately equal
 * @param val1 - first of two values to compare
 * @param val2 - second of two values to compare
 * @return Whether the two values are approximately equal
 */
bool approx(int val1, int val2) {
    return abs(val1 - val2) <= 1;
}