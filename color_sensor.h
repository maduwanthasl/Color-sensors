

// #ifndef COLOR_SENSOR_H
// #define COLOR_SENSOR_H

// #include <Wire.h>
// #include "Adafruit_TCS34725.h"

// extern int redCount;
// extern int greenCount;
// extern int blueCount;

// extern unsigned long startTime;

// void setup_color_sensor();
// void loop_color_sensor();

// #endif

#ifndef COLOR_SENSOR_H
#define COLOR_SENSOR_H

#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "variables.h"

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
