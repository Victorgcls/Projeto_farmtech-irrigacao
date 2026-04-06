#include "DHT.h"

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// pinos
int pinN = 12;
int pinP = 13;
int pinK = 14;
int pinLDR = 34;
int pinRele = 2;

void setup() {
  Serial.begin(115200);

  pinMode(pinN, INPUT_PULLUP);
  pinMode(pinP, INPUT_PULLUP);
  pinMode(pinK, INPUT_PULLUP);

  pinMode(pinRele, OUTPUT);

  dht.begin();
}

void loop() {
  // leitura dos botões
  int N = !digitalRead(pinN);
  int P = !digitalRead(pinP);
  int K = !digitalRead(pinK);

  int nutrientes = N + P + K;

  // leitura do LDR
  int ph = analogRead(pinLDR);

  // leitura do DHT22
  float umidade = dht.readHumidity();

  // mostrar valores
  Serial.print("Umidade: ");
  Serial.println(umidade);

  Serial.print("pH: ");
  Serial.println(ph);

  Serial.print("N = ");
  Serial.println(N);

  Serial.print("P = ");
  Serial.println(P);

  Serial.print("K = ");
  Serial.println(K);

  Serial.print("Nutrientes: ");
  Serial.println(nutrientes);

  
  if (umidade < 90 && nutrientes >= 1 && ph > 0) {
    digitalWrite(pinRele, HIGH);
    Serial.println("IRRIGANDO...");
  } else {
    digitalWrite(pinRele, LOW);
    Serial.println("PARADO");
  }

  Serial.println("-------------------");

  delay(2000);
}
