/*
 * File: config.h
 * Fun: supply config funtion
 * Date: 2024-04-06
 * Author: cz0807bin
 */

//#include "Arduino.h"

////////////////////////////
//       Serial Fun       //
////////////////////////////
void setup_serial(const long speed);
//void print_serial(char *str);
void DEBUG_INFO(const char *str);

////////////////////////////
//         Led Fun        //
////////////////////////////
void setup_led_for_test();
void turnon_led_for_test();
void turnoff_led_for_test();

////////////////////////////
//        Wave Fun        //
////////////////////////////
void setup_wave();
void runWave();
