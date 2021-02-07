PIR_STATE pirState = PIR_MONITOR_STAGE;
bool pirOnIntervalReset = true;
bool insideLightState = false;
unsigned long resetIntervalDelay;

void pirInit() {
  // PIR sensor setup
  digitalRead(PIR_PIN_NUMBER);
}

void pirProcess()
{
  switch(pirState) {
      case PIR_MONITOR_STAGE:
        if(pirOnIntervalReset == true) {
          Serial.println("pirProcess -> PIR Detected");
          if (digitalRead(PIR_PIN_NUMBER) == HIGH) { // check if the sensor is HIGH
            pirState = PIR_EVENT_ON_STAGE;
            Serial.println("pirProcess -> PIR_EVENT_ON_STAGE");
          } else {
            pirState = PIR_EVENT_OFF_STAGE;     
            Serial.println("pirProcess -> PIR_EVENT_OFF_STAGE");
          }
        } else {
          if ((unsigned long)(millis() - resetIntervalDelay) >= PIR_EVENT_INTERVAL_TIME_MIN) {
            pirOnIntervalReset = true;
          }
        }

        break;
      case PIR_EVENT_ON_STAGE:
        insideLightRelayOn();
        resetIntervalDelay = millis();
        pirOnIntervalReset = false;
        pirState = PIR_MONITOR_STAGE;
        break;
      case PIR_EVENT_OFF_STAGE:
        insideLightRelayOff();
        pirOnIntervalReset = true;
        pirState = PIR_MONITOR_STAGE;
        break;
  }
}
