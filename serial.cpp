/*
 * File: serial.cpp
 * Fun: serial function
 * Date: 2024-04-06
 * Author: cz0807bin
 */

#include "Arduino.h"
#include "config.h"

void setup_serial(const long speed) {
  if(speed != 300 && speed != 1200 && speed != 2400 && \
    speed != 4800 && speed != 9600 && speed != 19200 && \
    speed != 38400 && speed != 57600 && speed != 115200){
      exit(1);
    }
  
  Serial.begin(speed);
  Serial.print("===> setup serial success...\n");
}

static void print_serial(const char *str) {
  if(str == NULL){
    exit(1);
  }
  
  Serial.print(str);
}

void DEBUG_INFO(const char *str) {
  print_serial(str);
}
