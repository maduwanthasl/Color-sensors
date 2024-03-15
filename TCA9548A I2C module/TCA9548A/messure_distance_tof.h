#ifndef MESSURE_DISTANCE_TOF_H
#define MESSURE_DISTANCE_TOF_H

#include <Arduino.h>
#include "Adafruit_VL53L0X.h"

extern int distance_tof; // Declare distance_tof as a global variable

void messure_distance_tof_setup();
void messure_distance_tof_loop(int numSamples);

#endif
