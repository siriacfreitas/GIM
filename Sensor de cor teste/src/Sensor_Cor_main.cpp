#include <ArduinoSTL.h>  // Biblioteca que traz o STL para Arduino
#include <Arduino.h>
#include "Sensor_Cor_lib.hpp"

using namespace std;

//Savar no csv
//Distância euclidiana

#define DIGITAL_PIN 6  // Pino digital para os LEDs NeoPixel
#define ANALOG_PIN A0  // Pino analógico para o sensor de cor


ColorSensorAnalog colorSensor(DIGITAL_PIN, ANALOG_PIN);  // Inicializa o sensor de cor

//Variáveis 
COLOR cor;
string cor_digitada;
string resposta;



void setup() {
  Serial.begin(9600);  // Inicia a comunicação serial com o monitor
  colorSensor.changeColor(None);  // Inicializa com LEDs apagados

 
}

void loop() {

  cout << "Nova leitura?";
  cin >> resposta;
  cout << endl;
  
  while (resposta=="sim"){
  //Calibrando o sensor 
  cout << "Digite uma cor \n";
  cin >> cor_digitada;
  cout << "Nome da cor: ";
  cout << cor_digitada << endl;
  if(cor_digitada=="vermelho") colorSensor.Sensor_Calibracao(Red);
  else if(cor_digitada=="verde") colorSensor.Sensor_Calibracao(Green);
  else if(cor_digitada=="azul") colorSensor.Sensor_Calibracao(Blue);
  else if(cor_digitada=="amarelo") colorSensor.Sensor_Calibracao(Yellow);
  else if(cor_digitada=="marrom") colorSensor.Sensor_Calibracao(Brown);
  else if(cor_digitada=="branco") colorSensor.Sensor_Calibracao(White);
  else if(cor_digitada=="preto") colorSensor.Sensor_Calibracao(Black);
  cout << "Nova leitura?";
  cin >> resposta;
  cout << endl;
  }

  do{
    cout << "Testar cor?";
    cin >> resposta;
    cout << endl;
    colorSensor.readColor();
    cor = colorSensor.getColor();
    // Exibindo a cor detectada pela menor distância euclidiana
    
    switch (cor) {
        case Red:
            Serial.println("Cor mais próxima: Vermelho");
            break;
        case Green:
            Serial.println("Cor mais próxima: Verde");
            break;
        case Blue:
            Serial.println("Cor mais próxima: Azul");
            break;
        case Yellow:
            Serial.println("Cor mais próxima: Amarelo");
            break;
        case Brown:
            Serial.println("Cor mais próxima: Marrom");
            break;
        case White:
            Serial.println("Cor mais próxima: Branco");
            break;
        case Black:
            Serial.println("Cor mais próxima: Preto");
            break; 
        default:
            Serial.println("Nenhuma cor detectada");
            break;
    } 
   }while(resposta=="testar");
     
  
  delay(2000);  // Aguarda 2 segundos antes de repetir a leitura
}