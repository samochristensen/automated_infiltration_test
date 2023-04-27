/* Automated Infilatration Tester

General Descrition:
    Describe what it does in layman's terms. Refer to the components
    attached to the various pins.

Circuit Discription:
    Inputs:
    Outputs:

Software Record:
    Created April 26, 2023 By Sam Christensen
    Modified [Date] By [Name]

https://github.com/samochristensen/automated_infiltration_test
*/

#include <pt.h>
#include <ser

static struct pt flow_control_th;
static struct pt read_sensor_th;
const int PIN_TOP_LEVEL_SENSOR = 0;
const int PIN_BTM_LEVEL_SENSOR = 1;
const int PIN_MODE_SWITCH_LSB = 2;
const int PIN_MODE_SWITCH_MSB = 3;
const int PIN_START_BTN = 4;
const int PIN_FLOW_SENSOR = 5;
const int PIN_BALL_VALVE = 6;
//TODO: PIN_LED_WRITE_STATUS (Timestamp)
//TODO: PIN_LED_FLOW_SENSOR_PULSE


void setup() {
  Serial.begin(9600);

  pinMode(PIN_TOP_LEVEL_SENSOR, INPUT);
  pinMode(PIN_BTM_LEVEL_SENSOR, INPUT);
  pinMode(PIN_MODE_SWITCH_LSB, INPUT);
  pinMode(PIN_MODE_SWITCH_MSB, INPUT);
  pinMode(PIN_START_BTN, INPUT);
  pinMode(PIN_FLOW_SENSOR, INPUT);
  pinMode(PIN_BALL_VALVE, OUTPUT);

  PT_INIT(&flow_control_th);
  PT_INIT(&read_sensor_th);
}

void loop() {
  protothreadFlowControl(&flow_control_th);
  protothreadFlowSensor(&read_sensor_th);
}

/**
  * Control Flow
  * 
  * Reads in state information from water level sensors and user controls
  * (ie buttons and switches).
  * Opens and shuts valves in accordance with user specified behavior.
  *    
  * 
  * @param pt pointer to protothread
  * @return 
*/
static int protothreadFlowControl (struct pt *pt){
  // check if "start" enabled
  PT_BEGIN(pt);
  PT_WAIT_UNTIL(pt, )
}

static int protothreadFlowSensor (struct pt *pt){

}