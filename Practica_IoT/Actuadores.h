int pinRelevadorVen = 17;
int pinRelevadorBom = 26;
#include "BuzzerSong.h"

class Actuadores_ESP32 {
   public:
    //venti pin 17
    //bomba pin 26
    void Buzzer ( void );
    void Bomba (int);
    void Ventilador (int);
};

void Actuadores_ESP32 :: Buzzer (void) {
  buzzer_ESP32.SongBuz();
  Serial.println("Me active");
  }

void Actuadores_ESP32 :: Bomba (int estado) {
  Serial.println("Ejecutandose");
  Serial.println(estado);
  pinMode(pinRelevadorBom, OUTPUT);
  
  if (estado == 1){
    Serial.println("Estado 1");
    digitalWrite(pinRelevadorBom,LOW); // Por defecto dejaremos el relevador activado.
  } else if (estado == 0){
    Serial.println("Estado 0");
    digitalWrite(pinRelevadorBom,HIGH);
  }                                

  }

void Actuadores_ESP32 :: Ventilador (int estado) {

  Serial.println(estado);
  
  pinMode(pinRelevadorVen, OUTPUT);
  
  if (estado == 0){
    Serial.println("Estado 1");
    digitalWrite(pinRelevadorVen,HIGH); // Por defecto dejaremos el relevador activado.
  } else if (estado == 1){
    Serial.println("Estado 0");
    digitalWrite(pinRelevadorVen,LOW);
  } 
  
  }
