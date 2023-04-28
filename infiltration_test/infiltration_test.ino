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

static struct pt flow_control_th;
static struct pt read_sensor_th;
const int PIN_SENSOR_LEVEL_TOP = 4;
const int PIN_SENSOR_LEVEL_BTM = 0;
const int PIN_SWITCH_MODE_LSB = 2;
const int PIN_SWITCH_MODE_MSB = 3;
const int PIN_BTN_ENABLE = 1;
const int PIN_SENSOR_FLOW = 5;
const int PIN_VALVE_BALL = 6;
//TODO: PIN_LED_WRITE_STATUS (Timestamp)
//TODO: PIN_LED_FLOW_SENSOR_PULSE

bool isEnabled;
int mode;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_SENSOR_LEVEL_TOP, INPUT);
  pinMode(PIN_SENSOR_LEVEL_BTM, INPUT);
  pinMode(PIN_SWITCH_MODE_LSB, INPUT);
  pinMode(PIN_SWITCH_MODE_MSB, INPUT);
  pinMode(PIN_BTN_ENABLE, INPUT);
  pinMode(PIN_SENSOR_FLOW, INPUT);
  pinMode(PIN_VALVE_BALL, OUTPUT);

  PT_INIT(&flow_control_th);
  PT_INIT(&read_sensor_th);

  //init global

}

void loop() {
  Serial.print("Main loop count: ");
  Serial.println(main_count); main_count++;
  protothreadFlowControl(&flow_control_th);
  protothreadFlowSensor(&read_sensor_th);
}

static int getMode(){
  return 2 * digitalRead(PIN_SWITCH_MODE_MSB) + digitalRead(PIN_SWITCH_MODE_LSB)
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
  // Serial.println("[DEBUG] Waiting for 'isEnabled' to be True");
  PT_YIELD_UNTIL(pt, digitalRead(PIN_BTN_ENABLE) == HIGH);
  switch(getMode()){
    case 0: // Override
      digitalWrite(PIN_VALVE_BALL, HIGH);
      PT_YIELD_UNTIL(pt, getMode() != 0 || digitalRead(PTN_BTN_ENABLE) == LOW);
      PT_EXIT();
      break;
    case 1: // Falling Head
      
      break;
    case 2: // Constant Head

      break;
  }


  PT_END(pt);
}

static int protothreadFlowSensor (struct pt *pt){
  PT_BEGIN(pt);
  // Serial.println("TODO: implement protothreadFlowSensor()");
  // delay(1500);
  PT_END(pt);
}
