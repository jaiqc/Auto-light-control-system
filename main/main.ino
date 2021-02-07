#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>
#include "config.h"

LIGHT_STATE lightState = RTCC_OPERATION;
unsigned long rtccScanInterval = RTCC_EVENT_INTERVAL_TIME_MIN;

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for serial
  pirInit();
  relayInit();
  rtccInit();
}

void loop() {
  switch(lightState) {
    case RTCC_OPERATION:
      if((unsigned long)(millis() - rtccScanInterval) >= RTCC_EVENT_INTERVAL_TIME_MIN) {
        if(LIGHT1_ENABLE == true) {
          rtccProcess();  
        }
        rtccScanInterval = millis();
      }      
      lightState = PIR_OPERATION;
      break;
    case PIR_OPERATION:
      if(LIGHT2_ENABLE == true) {
        pirProcess();
      }
      lightState = RTCC_OPERATION;
      break;
    default:
      break;
  }
}
