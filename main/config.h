typedef enum {
  RTCC_OPERATION,
  PIR_OPERATION
} LIGHT_STATE;

typedef enum {
  RTCC_MONITOR_STATE,
  RTCC_EVENT_ON_STAGE,
  RTCC_EVENT_OFF_STAGE
} RTCC_STATE;

typedef enum {
  PIR_MONITOR_STAGE,
  PIR_EVENT_ON_STAGE,
  PIR_EVENT_OFF_STAGE
} PIR_STATE;

#define OUTSIDE_LIGHT_ON_TIME_HOUR 17
#define OUTSIDE_LIGHT_ON_TIME_MIN 40
#define OUTSIDE_LIGHT_0FF_TIME_HOUR 6
#define OUTSIDE_LIGHT_OFF_TIME_MIN 15
#define PIR_EVENT_INTERVAL_TIME_MIN 500000 //ms
#define RTCC_EVENT_INTERVAL_TIME_MIN 100000 //ms

#define PIR_PIN_NUMBER 2
#define LIGHT_1 3
#define LIGHT_2 4

#define LIGHT1_ENABLE true
#define LIGHT2_ENABLE true
