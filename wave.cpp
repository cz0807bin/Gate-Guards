/*
 * File: wave.cpp
 * Fun: wave function
 * Date: 2024-04-06
 * Author: cz0807bin
 */

#include "Arduino.h"
#include "config.h"
#include <NewPing.h>

const int Trig=2;
const int Echo=3;

#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define WAVE_WARNING_DISTANCE (15.00) // cm

NewPing sonar(Trig, Echo, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

unsigned int pingSpeed = 50; // How frequently are we going to send out a ping (in milliseconds). 50ms would be 20 times a second.
unsigned long pingTimer;     // Holds the next ping time.

int lastDistance, curDistance, offsetDistance;
int isRecordfirst = 1;

static void echoCheck();

void setup_wave() {
  pingTimer = millis(); // Start now.
}
 
void runWave() {
  // Notice how there's no delays in this sketch to allow you to do other processing in-line while doing distance pings.
  if (millis() >= pingTimer) {   // pingSpeed milliseconds since last ping, do another ping.
    pingTimer += pingSpeed;      // Set the next ping time.
    sonar.ping_timer(echoCheck); // Send out the ping, calls "echoCheck" function every 24uS where you can check the ping status.
  }
  // Do other stuff here, really. Think of it as multi-tasking.
}

static void echoCheck() { // Timer2 interrupt calls this function every 24uS where you can check the ping status.
  // Don't do anything here!
  if (sonar.check_timer()) { // This is how you check to see if the ping was received.
    // Here's where you can add code.
    curDistance=sonar.ping_result / US_ROUNDTRIP_CM;
    Serial.print(curDistance); // Ping returned, uS result in ping_result, convert to cm with US_ROUNDTRIP_CM.
    DEBUG_INFO("cm\n");

    if(isRecordfirst){
      isRecordfirst=0;
      lastDistance=curDistance;
    } else {
      offsetDistance=lastDistance - curDistance;
      if(offsetDistance > WAVE_WARNING_DISTANCE){
        isPlay=1;
      }
      lastDistance=curDistance;
    }
  }
  // Don't do anything here!
}