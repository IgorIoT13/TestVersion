#pragma once

#ifndef DLS_H
#define DLS_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <max6675.h>
#include <PIDController.h>
#include "pins.h"

PIDController pid;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

const float BETA = 3950;
int set_temperature = 1;
float temperature_value_c = 0.0;
int HEAT = false;
int COLD = false;

OneWire oneWire(10);
DallasTemperature sensor(&oneWire);

void change_temperature(){
  if(HEAT){
    switch(HEAT){
      case 0x03:
        setTemp();
        set_temperature = set_temperature - 3;
      break;

      case 0x04:
        setTemp();
        set_temperature = set_temperature + 3;
      break;
    }
  }

  if(COLD){
    switch(COLD){
      case 0x03:
        setTemp();
        set_temperature = set_temperature - 3;
      break;

      case 0x04:
        setTemp();
        set_temperature = set_temperature + 3;
      break;
    }
  }
}

void setTemp(){
  if (encoder_btn_count == 2)
  {
    lcd.clear();
    lcd.setCursor(16, 0);
    lcd.print("Set Temp.");
    lcd.print(set_temperature);
  }
}

float readNTC()
{ 
  int analogValue = analogRead(NTC_PIN);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  return celsius;
}

void dallas_setup(){
  pid.begin();
  pid.setpoint(150);
  pid.tune(__Kp, __Ki,__Kd);
  pid.limit(0, 255);
}

void dallas_loop(){
  change_temperature();
  temperature_value_c = thermocouple.getTemperature();
  int output = pid.compute(temperature_value_c);
  analogWrite(mosfet_pin, output);
  pid.setpoint(set_temperature);
}

#endif

