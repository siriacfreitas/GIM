#include <Arduino.h>

#include "robot.hpp"


Robot boberto;

void setup() {
    Serial.begin(9600);
    boberto.begin();
    Serial.println(":: Oi, eu sou o Boberto ::");
}

void loop() {
  boberto.forward();
  Serial.println("Boberto aqui 2");
  delay(100);
}
