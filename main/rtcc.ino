RTCC_STATE rtccState = RTCC_MONITOR_STATE;
bool outSideLightState = false;

void rtccInit() {
  
}

void rtccProcess()
{
  tmElements_t tm = rtccGet();
  switch(rtccState) {
    case RTCC_MONITOR_STATE:
      rtccPrint(tm);
      //20 > 17 && 20 > 6
      if(tm.Hour >= OUTSIDE_LIGHT_ON_TIME_HOUR) {
        Serial.println("rtccProcess -> RTCC_EVENT_ON_STAGE");
        rtccPrint(tm);
        if(isOutsideLightAlreadyOn() == false) {
          Serial.println("rtccProcess <==> Outside light ON");
          outsideLightOn();
        }
      } else if(tm.Hour <= OUTSIDE_LIGHT_0FF_TIME_HOUR) {
        Serial.println("rtccProcess -> RTCC_EVENT_ON_STAGE");
        rtccPrint(tm);
        if(isOutsideLightAlreadyOn() == false) {
          Serial.println("rtccProcess <==> Outside light ON");
          outsideLightOn();
        }
      } else {
        Serial.println("rtccProcess -> RTCC_EVENT_OFF_STAGE");
        rtccPrint(tm);
        Serial.println("rtccProcess <==> Outside light OFF");
        outsideLightOff();
      }      
      break;
    default:
      break;
  }  
}

bool isOutsideLightAlreadyOn() {
  return outSideLightState;
}

bool outsideLightOn() {
  outsideLightRelayOn();
  outSideLightState = true;
}

bool outsideLightOff() {
  outsideLightRelayOff();
  outSideLightState = false;
}

tmElements_t rtccGet()
{
  tmElements_t tm;
  RTC.read(tm);
  return tm;
}

void rtccPrint(tmElements_t tm) 
{
  Serial.print("Ok, Time = ");
  print2digits(tm.Hour);
  Serial.write(':');
  print2digits(tm.Minute);
  Serial.write(':');
  print2digits(tm.Second);
  Serial.print(", Date (D/M/Y) = ");
  Serial.print(tm.Day);
  Serial.write('/');
  Serial.print(tm.Month);
  Serial.write('/');
  Serial.print(tmYearToCalendar(tm.Year));
  Serial.println();
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.write('0');
  }
  Serial.print(number);
}
