//
//    FILE: AD524X_sawtooth.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: AD524X demo program
//     URL: https://github.com/RobTillaart/AD524X
//


#include "AD524X.h"

AD524X AD01(0x2C);  // AD0 & AD1 == GND


void setup()
{
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.println();
  Serial.println(AD524X_LIB_VERSION);

  Wire.begin();
  Wire.setClock(400000);
  
  bool b = AD01.begin();
  Serial.println(b ? "true" : "false");
  Serial.println(AD01.isConnected());
}


void loop()
{
  for (int val = 0; val < 255; val++)
  {
    AD01.write(1, val);
    Serial.println(val);
    delay(20);
  }
}


// -- END OF FILE --

