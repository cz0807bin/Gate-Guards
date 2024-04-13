/*
 * File: led.cpp
 * Fun: led function for test
 * Date: 2024-04-06
 * Author: cz0807bin
 */

#include "Arduino.h"
#include "config.h"

const int Led=13;

void setup_led_for_test() {
  pinMode(Led, OUTPUT);
  DEBUG_INFO("===> setup led success...\n");
}

void turnon_led_for_test() {
  digitalWrite(Led, HIGH);
}

void turnoff_led_for_test() {
  digitalWrite(Led, LOW);
}
