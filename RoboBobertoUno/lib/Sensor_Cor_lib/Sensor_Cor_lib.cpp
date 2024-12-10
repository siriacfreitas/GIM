#include "Sensor_Cor_lib.hpp"
#include <ArduinoSTL.h>  // Biblioteca que traz o STL para Arduino
#include <Arduino.h>
#include "Adafruit_NeoPixel.h"
using namespace std;


//Costrutor da classe 
ColorSensorAnalog::ColorSensorAnalog(uint8_t _digitalPin, uint8_t _analogPin) {
  ledPin = _digitalPin;
  ldrPin = _analogPin;

  //Inicializando os vetores com zero
  redValues.resize(NUM_SAMPLES + 1);
  fill(redValues.begin(), redValues.end(), 0);


  greenValues.resize(NUM_SAMPLES + 1);
  fill(greenValues.begin(), greenValues.end(), 0);


  blueValues.resize(NUM_SAMPLES + 1);
  fill(blueValues.begin(), blueValues.end(), 0);

  whiteValues.resize(NUM_SAMPLES + 1);
  fill(whiteValues.begin(), whiteValues.end(), 0);

    //Inicializando os vetores da calobração com zero
  redBegin.resize(4);
  redBegin[0]=725.00;
  redBegin[1]=725.00;
  redBegin[2]=725.00;
  redBegin[3]=725.00;

  greenBegin.resize(4);
  greenBegin[0]=0.00;
  greenBegin[1]=0.00;
  greenBegin[2]=0.00;
  greenBegin[3]=0.00;

  blueBegin.resize(4);
  blueBegin[0]=0.00;
  blueBegin[1]=0.00;
  blueBegin[2]=0.00;
  blueBegin[3]=0.00;

  yellowBegin.resize(4);
  yellowBegin[0]=0.00;
  yellowBegin[1]=0.00;
  yellowBegin[2]=0.00;
  yellowBegin[3]=0.00;
 

  brownBegin.resize(4);
  brownBegin[0]=0.00;
  brownBegin[1]=0.00;
  brownBegin[2]=0.00;
  brownBegin[3]=0.00;

  whiteBegin.resize(4);
  whiteBegin[0]=0.00;
  whiteBegin[1]=0.00;
  whiteBegin[2]=0.00;
  whiteBegin[3]=0.00;

  blackBegin.resize(4);
  blackBegin[0]=0.00;
  blackBegin[1]=0.00;
  blackBegin[2]=0.00;
  blackBegin[3]=0.00; 
  
  

  // Configuração dos LEDs NeoPixel
  pixels = Adafruit_NeoPixel(NUM_PIXELS, ledPin, NEO_GBR + NEO_KHZ800);
  pixels.begin();
}

//Destrutor da classe 
ColorSensorAnalog::~ColorSensorAnalog() {}



// Função para zerar as variáveis de cor
void ColorSensorAnalog::resetColors() {
  fill(redValues.begin(), redValues.end(), 0);
  fill(greenValues.begin(), greenValues.end(), 0);
  fill(blueValues.begin(), blueValues.end(), 0);
  fill(whiteValues.begin(), whiteValues.end(), 0);
}


// Função para mudar a cor dos LEDs
void ColorSensorAnalog::changeColor(COLOR color) {
  switch (color) {
    case Red:
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));  // Azul
      break;
    case Green:
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));  // Verde
      break;
    case Blue:
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Vermelho
      break;
    case White:
      pixels.setPixelColor(0, pixels.Color(255, 255, 255));  // Branco
      break;
    default:
      pixels.clear();  // Apaga os LEDs
      break;
  }

  pixels.show();  // Atualiza os LEDs
}



// Função para ler as cores e guardar em um vetor 
void ColorSensorAnalog::readColor() {
  
  changeColor(None);  // Apaga os LEDs
  resetColors();  // Zera as variáveis antes de iniciar novas leituras


  for (uint8_t i = 0; i <= NUM_SAMPLES; i++) {  

    //Lê a cor Vermelha;
    changeColor(Red);
    delay(COLOR_DELAY);
    redValues[i] = analogRead(ldrPin);  // Lê o valor do sensor para o vermelho
    /*cout << "Vermelho " << i << endl;
      cout << redValues[i] << endl;*/
    //delay(DELAY_TESTE);


    //Lê a cor Verde;
    changeColor(Green);
    delay(COLOR_DELAY);
    greenValues[i] = analogRead(ldrPin);  // Lê o valor do sensor para o verde
    /*cout << "Verde " << i << endl;
      cout << greenValues[i] << endl;*/
    //delay(DELAY_TESTE);

    //Lê a cor Azul;
    changeColor(Blue);
    delay(COLOR_DELAY);
    blueValues[i] = analogRead(ldrPin);  // Lê o valor do sensor para o azul
    /*cout << "Azul " << i << endl;
      cout << blueValues[i] << endl;*/
    //delay(DELAY_TESTE);


    //Lê a cor Branca;
    changeColor(White);
    delay(COLOR_DELAY);
    whiteValues[i] = analogRead(ldrPin);  // Lê o valor do sensor para o branco
    /*cout << ("Branco ")<<i << endl;
      cout << whiteValues[i] << endl;*/
    //delay(DELAY_TESTE);

    changeColor(None);  // Apaga os LEDs entre leituras
  }
}


// Métodos de consulta que retornam a mediana das leituras
double ColorSensorAnalog::getRed() const {
  vector<double> Red = redValues;
  sort(Red.begin(), Red.end());
  return Red[ NUM_SAMPLES / 2];
}

double ColorSensorAnalog::getGreen() const {
  vector<double> Green = greenValues;
  sort(Green.begin(), Green.end());
  return Green[ NUM_SAMPLES / 2];
}

double ColorSensorAnalog::getBlue() const {
  vector<double> Blue = blueValues;
  sort(Blue.begin(), Blue.end());
  return Blue[ NUM_SAMPLES / 2];
}

double ColorSensorAnalog::getWhite() const {
  vector<double> White = whiteValues;
  sort(White.begin(), White.end());
  return White[ NUM_SAMPLES / 2];
}



//Calibração das cores, a primeira leitura.
/*void ColorSensorAnalog::Sensor_Calibracao(COLOR cor){
  
  switch(cor) { 
    // Realiza a leitura das cores
    
    case Red:
      readColor();
      redBegin[0] = getRed();
      redBegin[1] = getGreen();
      redBegin[2] = getBlue();
      redBegin[3] = getWhite();
      cout << "Vermelho " << redBegin[0] << '\t' << redBegin[1] << '\t' << redBegin[2] << '\t' << redBegin[3] << endl;
      break;

     case Green:
      readColor();
      greenBegin[0] = getRed();
      greenBegin[1] = getGreen();
      greenBegin[2] = getBlue();
      greenBegin[3] = getWhite();
      cout << "Verde " << greenBegin[0] << '\t' << greenBegin[1] << '\t' << greenBegin[2] << '\t' << greenBegin[3] << endl;
      break;

     case Blue:
      readColor();
      blueBegin[0] = getRed();
      blueBegin[1] = getGreen();
      blueBegin[2] = getBlue();
      blueBegin[3] = getWhite();
      cout << "Azul " << blueBegin[0] << '\t' << blueBegin[1] << '\t' << blueBegin[2] << '\t' << blueBegin[3] << endl;
      break;

     case Yellow:
      readColor();
      yellowBegin[0] = getRed();
      yellowBegin[1] = getGreen();
      yellowBegin[2] = getBlue();
      yellowBegin[3] = getWhite();
      cout << "Amarelo " << yellowBegin[0] << '\t' << yellowBegin[1] << '\t' << yellowBegin[2] << '\t' << yellowBegin[3] << endl;
      break;


     case Brown:
      readColor();
      brownBegin[0] = getRed();
      brownBegin[1] = getGreen();
      brownBegin[2] = getBlue();
      brownBegin[3] = getWhite();
      cout << "Marrom " << brownBegin[0] << '\t' << brownBegin[1] << '\t' << brownBegin[2] << '\t' << brownBegin[3] << endl;
      break;

     case White:
      readColor();
      whiteBegin[0] = getRed();
      whiteBegin[1] = getGreen();
      whiteBegin[2] = getBlue();
      whiteBegin[3] = getWhite();
      cout << "Marrom " << whiteBegin[0] << '\t' << whiteBegin[1] << '\t' << whiteBegin[2] << '\t' << whiteBegin[3] << endl;
      break;

     case Black:
      readColor();
      blackBegin[0] = getRed();
      blackBegin[1] = getGreen();
      blackBegin[2] = getBlue();
      blackBegin[3] = getWhite();
      cout << "Marrom " << blackBegin[0] << '\t' << blackBegin[1] << '\t' << blackBegin[2] << '\t' << blackBegin[3] << endl;
      break; 


  } 
    
}*/

COLOR ColorSensorAnalog::getColor(){ 
  //Fazendo a Distância Euclidiana 
  double vermelho= sqrt(pow(redBegin[0]-getRed(),2)+ pow(redBegin[1]-getGreen(),2)+ pow(redBegin[2]-getBlue(),2));
  double verde = sqrt(pow(greenBegin[0]-getRed(),2)+ pow(greenBegin[1]-getGreen(),2)+ pow(greenBegin[2]-getBlue(),2));
  double azul = sqrt(pow(blueBegin[0]-getRed(),2)+ pow(blueBegin[1]-getGreen(),2)+ pow(blueBegin[2]-getBlue(),2));
  double amarelo = sqrt(pow(yellowBegin[0]-getRed(),2)+ pow(yellowBegin[1]-getGreen(),2)+ pow(yellowBegin[2]-getBlue(),2));
  double marrom = sqrt(pow(brownBegin[0]-getRed(),2)+ pow(brownBegin[1]-getGreen(),2)+ pow(brownBegin[2]-getBlue(),2));
  double branco = sqrt(pow(whiteBegin[0]-getRed(),2)+ pow(whiteBegin[1]-getGreen(),2)+ pow(whiteBegin[2]-getBlue(),2));
  double preto = sqrt(pow(blackBegin[0]-getRed(),2)+ pow(blackBegin[1]-getGreen(),2)+ pow(blackBegin[2]-getBlue(),2));

    // Determinando a cor com a menor distância
    double menor = vermelho;
    COLOR cor = Red;
    //cout << "Vermelho" << getRed() << getGreen() << getBlue() << endl;

    if (verde < menor) {
        menor = verde;
        cor = Green;
        //cout << "Verde" << getRed() << getGreen() << getBlue() << endl;
    }
    if (azul < menor) {
        menor = azul;
        cor = Blue;
        //cout << "Azul" << getRed() << getGreen() << getBlue() << endl;
    }
    if (amarelo < menor) {
        menor = amarelo;
        cor = Yellow;
        //cout << "Amarelo" << getRed() << getGreen() << getBlue() << endl;
    }
    if (marrom < menor) {
        menor = marrom;
        cor = Brown;
        //cout << "Marrom" << getRed() << getGreen() << getBlue() << endl;
    }

    if (branco < menor) {
        menor = branco;
        cor = White;
        //cout << "Branco" << getRed() << getGreen() << getBlue() << endl;
    }
    if (preto < menor) {
        menor = preto;
        cor = Black;
        //cout << "Preto" << getRed() << getGreen() << getBlue() << endl;
    } 

    return cor;

  }