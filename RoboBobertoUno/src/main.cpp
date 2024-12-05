#include <Arduino.h>
#include "Sensor_Cor_lib.hpp"
#include "robot.hpp"

#define DIGITAL_PIN_FD 2 // Pino digital para os LEDs NeoPixel
#define ANALOG_PIN_FD A4  // Pino analógico para o sensor de cor
ColorSensorAnalog colorSensorFD(DIGITAL_PIN_FD, ANALOG_PIN_FD);  // Inicializa o sensor de cor 

#define DIGITAL_PIN_FE 3  // Pino digital para os LEDs NeoPixel
#define ANALOG_PIN_FE A5  // Pino analógico para o sensor de cor
ColorSensorAnalog colorSensorFE(DIGITAL_PIN_FE, ANALOG_PIN_FE);  // Inicializa o sensor de cor


Robot boberto;
COLOR corFE, corFD;
long tempoAnterior=0;

void setup() {
    Serial.begin(9600);
    boberto.begin();
    colorSensorFD.changeColor(None);  // Inicializa com LEDs apagados
    colorSensorFE.changeColor(None);  // Inicializa com LEDs apagados
    Serial.println(":: Oi, eu sou o Boberto ::");
}

void loop() {
  boberto.backward();

  if((millis()-tempoAnterior)>=150){
    tempoAnterior = millis();
    colorSensorFD.readColor();
    corFD = colorSensorFD.getColor();
    colorSensorFE.readColor();
    corFE = colorSensorFE.getColor();
}

if(corFD==Red && corFE==Red) {
  boberto.stop();
  delay(5000);
}
//cout << "D2A4 "<<colorSensorFD.getRed() << colorSensorFD.getGreen() << colorSensorFD.getBlue() << endl;
//cout << "D3A5 "<< colorSensorFE.getRed() << colorSensorFE.getGreen() << colorSensorFE.getBlue() << endl;

}
