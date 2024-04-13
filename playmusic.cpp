/*
 * File: playmusic.cpp
 * Fun: play function
 * Date: 2024-04-10
 * Author: cz0807bin
 */

#include "Arduino.h"
#include "config.h"

const int Play_1=4;
const int Play_2=5;
//const int Pause=6; // reserve
const int Status=7;

int isStartComplete=1;
int isPlay=0;

static int is_not_playing();

void setup_play() {
  pinMode(Play_1, OUTPUT);
  digitalWrite(Play_1, HIGH);
  pinMode(Play_2, OUTPUT);
  digitalWrite(Play_2, HIGH);
  //pinMode(Pause, OUTPUT);
  //digitalWrite(Pause, HIGH);
  pinMode(Status, INPUT);

  DEBUG_INFO("===> setup play success...\n");
}

void startup_complete() {
  if(isStartComplete){
    isStartComplete=0;
    delay(2000); // set delay in order to start music finish play, at least 1.5ms.
    digitalWrite(Play_1, LOW);
    delay(60);
    digitalWrite(Play_1, HIGH);
    DEBUG_INFO("===> start complete success...\n");
  }
}

void start_play() {
  if(isPlay){
    isPlay=0;
    if(is_not_playing()){
      digitalWrite(Play_2, LOW);
      delay(60);
      digitalWrite(Play_2, HIGH);
      DEBUG_INFO("===> start play success...\n");
    }
  }
}

// void pause_play() {
//   digitalWrite(Pause, LOW);
//   delay(60);
//   digitalWrite(Pause, HIGH);

//   DEBUG_INFO("===> pause play success...\n");
// }

static int is_not_playing() {
  return digitalRead(Status)?1:0;
}