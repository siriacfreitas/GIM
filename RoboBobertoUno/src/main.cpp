#include <Arduino.h>
#include "Sensor_Cor_lib.hpp"
#include "robot.hpp"

#define DIGITAL_PIN_FD 3  // Pino digital para os LEDs NeoPixel
#define ANALOG_PIN_FD A0  // Pino analógico para o sensor de cor
ColorSensorAnalog colorSensorFD(DIGITAL_PIN_FD, ANALOG_PIN_FD);  // Inicializa o sensor de cor

//#define DIGITAL_PIN_FE 2  // Pino digital para os LEDs NeoPixel
//#define ANALOG_PIN_FE A1  // Pino analógico para o sensor de cor
//ColorSensorAnalog colorSensorFE(DIGITAL_PIN_FE, ANALOG_PIN_FE);  // Inicializa o sensor de cor


Robot boberto;
COLOR corFE, corFD;

void setup() {
    Serial.begin(9600);
    boberto.begin();
    colorSensorFD.changeColor(None);  // Inicializa com LEDs apagados
    //colorSensorFE.changeColor(None);  // Inicializa com LEDs apagados
    Serial.println(":: Oi, eu sou o Boberto ::");
}

void loop() {
  boberto.forward();
  delay(50);
  boberto.stop();
  colorSensorFD.readColor();
  corFD = colorSensorFD.getColor();


  //colorSensorFE.readColor();
  //corFE = colorSensorFE.getColor();
  //delay(20);

  if(corFD == Red ) {
    boberto.stop();
    delay(2000);
    }

}
