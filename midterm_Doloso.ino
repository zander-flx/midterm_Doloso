/*======================================================
    INFRARED SENSOR COUNTER WITH 7-SEGMENT DISPLAY
========================================================
Description:
  This program takes two IR Sensor and programs it to 
  ESP32 and outputs it to two 7-Segment Common-Cathode 
  Display. One IR Sensor increments the count by 1 and 
  the other IR Sensor decrements the count by 1.

Programmer: 
  Felixander B. Doloso

Date: 
  28 October 2026
------------------------------------------------------*/

//GPIO Pins
const byte IR_IN1 = 36; //IR UP
const byte IR_IN2 = 34; //IR DOWN
const byte RST = 13;
const uint8_t LED_1[] = {32, 33, 25, 26, 27, 14, 12};
const uint8_t NUM0 = sizeof(LED_1) / sizeof(LED_1[0]);

const uint8_t LED_2[] = {19, 18, 5, 17, 16, 4, 0};
const uint8_t NUM1 = sizeof(LED_2) / sizeof(LED_2[0]);

//Variables
int adc_val_up = 0;
int adc_val_dn = 0;
int rst = 0;
int previousStateUp = 0;
int previousStateDn = 0;
uint8_t count = 0;

#include "Decoder.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(IR_IN1, INPUT);
  pinMode(RST, INPUT);
  pinMode(IR_IN2, INPUT);
  for (int i = 0; i < NUM0; i++) {
    pinMode(LED_1[i], OUTPUT);
  }

  for (int i = 0; i < NUM1; i++) {
    pinMode(LED_2[i], OUTPUT);
  }

  decoder(count);
}

void loop() {
  // put your main code here, to run repeatedly:
  adc_val_up = digitalRead(IR_IN1);
  adc_val_dn = digitalRead(IR_IN2);
  rst = digitalRead(RST);

  if(rst == 1){
    count = 8;
    decoder(count);
  }else if(adc_val_up == 1 && previousStateUp == 0){
    count = (count + 1) % 100;
    decoder(count);
  }else if(adc_val_dn == 1 && int previousStateDn == 0){
    if(count == 0){
      count = 99;
      decoder(count);
    }else{
      count = (count - 1) % 100;
      decoder(count);
    }
  }
  previousStateUp = adc_val_up;
  previousStateDn = adc_val_dn;
  delay(50);
}
