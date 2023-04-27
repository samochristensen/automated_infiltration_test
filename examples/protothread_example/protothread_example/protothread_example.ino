/*
    Protothread Example

    the purpose of this program is to test the protothread library
    and to become familiar with how to use it's functions

    The circuit:
    * no circuit

    Created day month year
    By author's name
    Modified day month year
    By author's name

    http://url/of/online/tutorial.cc

*/

#include <pt.h>
#define LED_1_PIN 9

static struct pt pt1;

static int protothreadBlinkLED1(struct pt *pt)
{
  static unsigned long lastTimeBlink = 0;
  PT_BEGIN(pt);
  while(1) {
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 1000);
    digitalWrite(LED_BUILTIN, HIGH);
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 1000);
    digitalWrite(LED_BUILTIN, LOW);
  }
  PT_END(pt);
}

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  PT_INIT(&pt1);
}

void loop() {
  protothreadBlinkLED1(&pt1);
}
