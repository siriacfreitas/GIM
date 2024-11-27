#include <Arduino.h>

#include "robot.hpp"


Robot boberto;

void setup() {
    Serial.begin(115200);
    boberto.begin();
    Serial.println(":: Oi, eu sou o Boberto ::");
}

void loop() {
  boberto.forward();
}
