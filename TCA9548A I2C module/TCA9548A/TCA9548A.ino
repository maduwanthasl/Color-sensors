//==============================
//I2C Multiplexing using TCA9548A
//==============================
#include "Wire.h"
extern "C" { 
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}
#include "messure_distance_tof.h"
#include "color_sensor.h"

ColorSensor colorSensor; // Create an instance of the ColorSensor class


#define TCAADDR 0x70


void TCA9548A(uint8_t i) 
{
  if (i > 7) return;
 
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();  
}


//=============================================================================
void setup()
{
  Serial.begin(9600);

  while (!Serial);
  delay(1000);
  Wire.begin();

  Serial.print("Start.");

  TCA9548A(2);
  messure_distance_tof_setup(); // Call the setup function of the MeasureDistanceTOF object
  TCA9548A(3);
  colorSensor.setup(); // Call the setup function of the ColorSensor instance

  TCA9548A(7);
  colorSensor.setup(); // Call the setup function of the ColorSensor instance

}

//============================================================================= 


void TCA9548A_tof_sensor(int a, int b){
  TCA9548A(a);
  messure_distance_tof_loop(b);
}

void TCA9548A_color_sensor(int a){
  TCA9548A(a);
  colorSensor.loop();

}



void loop()
{
  TCA9548A_color_sensor(7);
  delay(5000);
  TCA9548A_color_sensor(3);
  delay(5000);
  TCA9548A_tof_sensor(2,1);

}
