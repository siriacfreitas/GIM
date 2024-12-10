#include "Adafruit_NeoPixel.h"
#include "Arduino_FreeRTOS.h"
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define NUM_PIXELS 1
#define LED_PIN 2
#define LDR_PIN A5
//#define TEMPO 1000
#define TEMPO_INTER_LEITURA 10
#define TEMPO_ESTABILIZACAO 60
#define TEMPO_ENTRE_PRINTS 500

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int leitura_r = 0, leitura_g = 0, leitura_b = 0;
int vermelho_branco = 1023, verde_branco = 1023, azul_branco = 1023;
int vermelho_preto = 0, verde_preto = 0, azul_preto = 0;

// Prototipação das Tarefas
void updateRetornoRGB(void *pvParameters);
void printRetornoRGB(void *pvParameters);
void processaComandoSerial(void *pvParameters);

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Aguarda a inicialização da serial
  pixels.begin();

  // Cria as tarefas
  xTaskCreate(updateRetornoRGB, "Update RGB", 256, NULL, 1, NULL);
  xTaskCreate(printRetornoRGB, "Print RGB", 128, NULL, 1, NULL);
  xTaskCreate(processaComandoSerial, "Process Serial", 256, NULL, 1, NULL);

  Serial.println("FreeRTOS iniciado!");
}

void loop() {
  // Está vazio pois o FreeRTOS gerencia as tarefas
}

// Tarefa 1: Atualiza leituras RGB
void updateRetornoRGB(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Liga vermelho
    pixels.show();
    vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
    leitura_r = map(analogRead(LDR_PIN),vermelho_preto, vermelho_branco, 0, 1023);

    pixels.setPixelColor(0, pixels.Color(0, 255, 0));  // Liga verde
    pixels.show();
    vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
    leitura_g = map(analogRead(LDR_PIN),verde_preto, verde_branco, 0, 1023);

    pixels.setPixelColor(0, pixels.Color(0, 0, 255));  // Liga azul
    pixels.show();
    vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
    leitura_b = map(analogRead(LDR_PIN),azul_preto, azul_branco, 0, 1023);

    vTaskDelay(pdMS_TO_TICKS(TEMPO_INTER_LEITURA));
  }
}

// Tarefa 2: Imprime os valores RGB
void printRetornoRGB(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    Serial.print("R: ");
    Serial.print(leitura_r);
    Serial.print(" G: ");
    Serial.print(leitura_g);
    Serial.print(" B: ");
    Serial.println(leitura_b);
    vTaskDelay(pdMS_TO_TICKS(TEMPO_ENTRE_PRINTS));
  }
}

// Tarefa 3: Processa comando serial
void processaComandoSerial(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    if (Serial.available() > 0) {
      char comando = Serial.read();

      if (comando == 'b') {  // Comando para branco
        Serial.println("Lendo valores para branco...");

        pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Liga vermelho
        pixels.show();
        vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
        vermelho_branco = analogRead(LDR_PIN);

        pixels.setPixelColor(0, pixels.Color(0, 255, 0));  // Liga verde
        pixels.show();
        vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
        verde_branco = analogRead(LDR_PIN);

        pixels.setPixelColor(0, pixels.Color(0, 0, 255));  // Liga azul
        pixels.show();
        vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
        azul_branco = analogRead(LDR_PIN);

        Serial.println("Leituras para branco concluídas!");
      } else if (comando == 'p') {  // Comando para preto
        Serial.println("Lendo valores para preto...");

        pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Liga vermelho
        pixels.show();
        vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
        vermelho_preto = analogRead(LDR_PIN);

        pixels.setPixelColor(0, pixels.Color(0, 255, 0));  // Liga verde
        pixels.show();
        vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
        verde_preto = analogRead(LDR_PIN);

        pixels.setPixelColor(0, pixels.Color(0, 0, 255));  // Liga azul
        pixels.show();
        vTaskDelay(pdMS_TO_TICKS(TEMPO_ESTABILIZACAO));
        azul_preto = analogRead(LDR_PIN);

        Serial.println("Leituras para preto concluídas!");
      } else if (comando == 's') {
        Serial.print("Leituras para branco: ");
        Serial.print(vermelho_branco);
        Serial.print(" ");
        Serial.print(verde_branco);
        Serial.print(" ");
        Serial.print(azul_branco);
        Serial.print("\n");

        Serial.print("Leituras para preto: ");
        Serial.print(vermelho_preto);
        Serial.print(" ");
        Serial.print(verde_preto);
        Serial.print(" ");
        Serial.print(azul_preto);
        Serial.print("\n");
      }
    }
    vTaskDelay(pdMS_TO_TICKS(100));  // Pequeno delay para evitar sobrecarga
  }
}
