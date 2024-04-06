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
  setup_led_for_test();
  setup_wave();
}

// put your main code here, to run repeatedly:
void loop() {
  DEBUG_INFO("start detecting...\n");
  
  startup_wave();
  
  float distance_1=get_first_wave_distance();
  if(distance_1 < FIRST_WAVE_STANDARD_DISTANCE){
    turnon_led_for_test();
  } else {
    turnoff_led_for_test();
  }
  
  #if 0
  float distance_2=get_second_wave_distance();
  if(distance_2 < SECOND_WAVE_STANDARD_DISTANCE){
    
  }

  float distance_3=get_third_wave_distance();
  if(distance_3 < THIRD_WAVE_STANDARD_DISTANCE){
    
  }
  #endif
  
  delay(500);
}
