#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <Wire.h>
#include "Adafruit_TCS34725.h"

extern String dominantColor;

class ColorSensor {
public:
    ColorSensor();
    void setup();
    void loop();

private:
    Adafruit_TCS34725 tcs;
    int redCount;
    int greenCount;
    int blueCount;
    unsigned long startTime;
};

#endif