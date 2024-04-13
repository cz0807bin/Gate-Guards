/*
 * File: Gate-Guards.ino
 * Fun: main entry
 * Date: 2024-04-06
 * Author: cz0807bin
 */

//#include "Arduino.h"
#include "config.h"

// put your setup code here, to run once:
void setup() {
  setup_serial(9600);
  setup_wave();
  setup_play();
  startup_complete();
}

// put your main code here, to run repeatedly:
void loop() {
  DEBUG_INFO("start detecting...\n");
  runWave();
  start_play();

  delay(100);
}
