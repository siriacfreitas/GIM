#ifndef SENSOR_COR_LIB_HPP
#define SENSOR_COR_LIB_HPP

#include <Arduino.h>
#include <ArduinoSTL.h>  // Biblioteca que traz o STL para Arduino
#include "Adafruit_NeoPixel.h"

using namespace std;

//Variáveis estáticas
#define NUM_SAMPLES 10
#define NUM_PIXELS 1
#define COLOR_DELAY 20
#define DELAY_TESTE 20

//const string Aquivo ="cores_teste.txt";

//Possíveis cores
enum COLOR {
  Red ,Green, Blue, Yellow, Brown, White, Black, None  //SALVAR A COR ESCRITA PELO USUÁRIO 
};


class ColorSensorAnalog {

  private:
    uint8_t ledPin;
    uint8_t ldrPin;

    vector<double> redValues;
    vector<double> greenValues;
    vector<double> blueValues;
    vector<double> whiteValues;

    vector<double>redBegin;
    vector<double>greenBegin;
    vector<double>blueBegin;
    vector<double>yellowBegin;
    vector<double>brownBegin;
    //vector<double>whiteBegin;
    //vector<double>blackBegin;
    

    vector<double>dist_euclidiana;

    Adafruit_NeoPixel pixels;

  public:

    ColorSensorAnalog(uint8_t _digitalPin, uint8_t _analogPin);
    ~ColorSensorAnalog();
    void resetColors();
    void changeColor(COLOR color);
    void readColor();

    // Métodos de consulta que retornam a média das leituras
    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    double getWhite() const;

    void Sensor_Calibracao(COLOR cor);
    COLOR getColor();
};




#endif //SENSOR_COR_LIB_HPP