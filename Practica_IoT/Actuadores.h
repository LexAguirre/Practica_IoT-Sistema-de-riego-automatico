int pinReleVen = 17;
int pinReleBom = 27;
//#include "BuzzerSong.h"

class Actuadores_ESP32 {
   public:
    //venti pin 17
    //bomba pin 26
    void Buzzer ( void );
    void Bomba (int);
    void Ventilador (int);
};

void Actuadores_ESP32 :: Buzzer (void) {
  //buzzer_ESP32.SongBuz();
  Serial.println("Me active");
  }

void Actuadores_ESP32 :: Bomba (int estado) {

  pinMode(pinReleBom, OUTPUT);

  if (estado == 1){
    digitalWrite(pinReleBom,HIGH); // Por defecto dejaremos el relevador activado.
  } else if (estado == 0){
    digitalWrite(pinReleBom,LOW);
  }                                

  }

void Actuadores_ESP32 :: Ventilador (int estado) {

  pinMode(pinReleVen, OUTPUT);

  if (estado == 1){
    digitalWrite(pinReleVen,HIGH); // Por defecto dejaremos el relevador activado.
    Serial.println();
  } else if (estado == 0){
    digitalWrite(pinReleVen,LOW);
  } 

  }
/*void Actuadores_ESP32 :: BombaActiva () {
    pinMode(pinRelevadorBom, OUTPUT);
    digitalWrite(pinRelevadorBom,LOW); // Por defecto dejaremos el relevador activado.                    
  }

void Actuadores_ESP32 :: BombaDesact () {
  pinMode(pinRelevadorBom, OUTPUT);
  digitalWrite(pinRelevadorBom,LOW); // Por defecto dejaremos el relevador activado.                    
}

void Actuadores_ESP32 :: VentiladorActiva () {
    pinMode(pinRelevadorVen, OUTPUT);
    digitalWrite(pinRelevadorVen,LOW);
    Serial.println("me deberia activar");
}

void Actuadores_ESP32 :: VentiladorDesact () {
    pinMode(pinRelevadorVen, OUTPUT);
    digitalWrite(pinRelevadorVen,HIGH);
    Serial.println("me deberia desactivar");
}*/
