


#include "color_sensor.h"
String dominantColor;

ColorSensor::ColorSensor() :
    tcs(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X),
    redCount(0), greenCount(0), blueCount(0), startTime(0) {}

void ColorSensor::setup() {
    if (tcs.begin()) {
        Serial.println("Found sensor");
    } else {
        Serial.println("No TCS34725 found, check connections");
        while (1);
    }
}

void ColorSensor::loop() {
    do {
        uint16_t r, g, b, c;
        tcs.getRawData(&r, &g, &b, &c);

        // Subtract from the red value
        r -= 55;

        if (millis() - startTime < 5000) { // Collect samples for 5 seconds
            if (r > g && r > b) {
                redCount++;
            } else if (g > r && g > b) {
                greenCount++;
            } else if (b > r && b > g) {
                blueCount++;
            }
            // delay(10); // delay between each sample
        } else { // After 5 seconds, determine the dominant color
            Serial.print("Red Count: "); Serial.print(redCount); Serial.print("\t");
            Serial.print("Green Count: "); Serial.print(greenCount); Serial.print("\t");
            Serial.print("Blue Count: "); Serial.println(blueCount);

            if (redCount > greenCount && redCount > blueCount) {
                dominantColor = "Red";
            } else if (greenCount > redCount && greenCount > blueCount) {
                dominantColor = "Green";
            } else if (blueCount > redCount && blueCount > greenCount) {
                dominantColor = "Blue";
            } 
            else {
                dominantColor = "Unknown";
            }

            // Print the dominant color
            Serial.print("Dominant Color: "); Serial.println(dominantColor);

            // Reset counts for the next iteration
            redCount = 0;
            greenCount = 0;
            blueCount = 0;

            // Reset the timer for the next 5 seconds
            startTime = millis();
        }
    } while (!(dominantColor == "Blue" || dominantColor == "Green" || dominantColor == "Red"));
}
