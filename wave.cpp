/*
 * File: wave.cpp
 * Fun: wave function
 * Date: 2024-04-06
 * Author: cz0807bin
 */

#include "Arduino.h"
#include "config.h"

const float FIRST_WAVE_STANDARD_DISTANCE=50.00; // cm
const float SECOND_WAVE_STANDARD_DISTANCE=50.00; // cm
const float THIRD_WAVE_STANDARD_DISTANCE=50.00; // cm

const int Trig_1=2; // The first wave
const int Echo_1=3;
//const int Trig_2=4; // The second wave
//const int Echo_2=5;
//const int Trig_3=6; // The third wave
//const int Echo_3=7;

static void setup_one_wave(const int Trig, const int Echo)
{
  if(Trig <= 0 || Echo <= 0){
    DEBUG_INFO("Trig or Echo pin num error.\n");
    exit(1);
  }
  
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}

void setup_wave()
{
  setup_one_wave(Trig_1, Echo_1);
  //setup_one_wave(Trig_2, Echo_2);
  //setup_one_wave(Trig_3, Echo_3);

  DEBUG_INFO("===> setup wave success...\n");
}

void startup_wave()
{
  digitalWrite(Trig_1, LOW);
  //digitalWrite(Trig_2, LOW);
  //digitalWrite(Trig_3, LOW);
  delayMicroseconds(2);
  
  digitalWrite(Trig_1, HIGH);
  //digitalWrite(Trig_2, HIGH);
  //digitalWrite(Trig_3, HIGH);
  delayMicroseconds(15); // pin trig just need 10us for high level, but used 15us for stable.
  
  digitalWrite(Trig_1, LOW);
  //digitalWrite(Trig_2, LOW);
  //digitalWrite(Trig_3, LOW);
  
  DEBUG_INFO("===> startup wave success...\n");
}

static float get_wave_distance(const int Echo, const int Level, const long Timeout)
{
  if(Echo <=0 || Timeout <=0){
    DEBUG_INFO("Echo or Timeout error.\n");
    exit(1);
  }
  
  if(Level != HIGH && Level != LOW){
    DEBUG_INFO("Level error.\n");
    exit(1);
  }
  
  long pulseTime=0;
  float distance=0;
  
  pulseTime=pulseIn(Echo, Level, Timeout);
  distance=pulseTime/58.00; // distance = (pulseTime / 2) * (340 * 100 / 1000000)
  DEBUG_INFO("distcance is : \r");
  Serial.println(distance);  DEBUG_INFO("cm");

  return distance;
}

float get_first_wave_distance()
{
  return get_wave_distance(Echo_1, HIGH, 1000000);
}

float get_second_wave_distance()
{
  //return get_wave_distance(Echo_2, HIGH, 1000000);
}

float get_third_wave_distance()
{
  //return get_wave_distance(Echo_3, HIGH, 1000000);
}
