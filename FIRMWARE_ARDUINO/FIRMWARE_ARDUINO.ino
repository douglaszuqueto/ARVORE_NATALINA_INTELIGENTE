#include <SoftwareSerial.h>
#include <EEPROM.h>
#define PINO_RELE 11
#define MINUTO 30000
#define ESP8266_RX 2
#define ESP8266_TX 3

//
int felicitacoes = 1;
int felicitacoesTime = 0;
unsigned long ultimo = 0;
unsigned long ultimoMinuto = 0;
unsigned long ultimoTime = 0;
unsigned long ultimoT = 0;


unsigned long ultimoEeprom = 0;
int intervalo = 1000;
int addr = 0;

//

SoftwareSerial serialESP(ESP8266_RX, ESP8266_TX);
void setup() {
  Serial.begin(115200);
  serialESP.begin(115200);
  pinMode(PINO_RELE, 1);
  digitalWrite(PINO_RELE, 1);
  //  EEPROM.write(addr, 0);
}
String temp = "";
boolean stringCompleta = false;
void loop() {
  if (serialESP.available() > 0) {
    while (serialESP.available() > 0) {
      char c = (char)serialESP.read();
      temp += c;
      if (c == '\n') Serial.println("quebra");
      delay(20);
    }
    Serial.println(temp);
    if (temp.toInt()) {
      felicitacoes += temp.toInt();
    }

    temp = "";
  }
  if (millis() - ultimo >= 1000) {
    Serial.println(felicitacoes);
    ultimo = millis();
  }



  if (millis() - ultimoMinuto >= (MINUTO / felicitacoesTime)) {
    digitalWrite(PINO_RELE, !digitalRead(PINO_RELE));
    ultimoMinuto = millis();
  }


  if (millis() - ultimoTime >= MINUTO) {
    felicitacoesTime = felicitacoes;
    Serial.print("Felicitacoes; ");
    Serial.println(felicitacoesTime);
    ultimoTime = millis();
  }

  //    if (millis() - ultimoEeprom >= 5000) {
  //      EEPROM.update(addr, felicitacoes);
  //      Serial.print("EEPROM: ");
  //      Serial.println(EEPROM.read(addr));
  //      ultimoEeprom = millis();
  //
  //    }
  //
//  delay(100);
}
int calculaTempo() {
  return MINUTO / felicitacoes;
}

