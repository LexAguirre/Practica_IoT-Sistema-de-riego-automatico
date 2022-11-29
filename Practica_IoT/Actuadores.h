int pinRelevadorVen = 17;
int pinRelevadorBom = 25;
//#include "BuzzerSong.h"

class Actuadores_ESP32 {
   public:
    //venti pin 17
    //bomba pin 25
    void Buzzer ( void );
    void Bomba (int);
    void Ventilador (int);
};

void Actuadores_ESP32 :: Buzzer (void) {
  //buzzer_ESP32.buzzer();
  }

void Actuadores_ESP32 :: Bomba (int estado) {
  
  pinMode(pinRelevadorBom, OUTPUT);
  
  if (estado = 1){
    digitalWrite(pinRelevadorBom,HIGH); // Por defecto dejaremos el relevador activado.
  } else if (estado = 0){
    digitalWrite(pinRelevadorBom,LOW);
  }                                

  }

void Actuadores_ESP32 :: Ventilador (int estado) {
    
  pinMode(pinRelevadorVen, OUTPUT);
  
  if (estado = 1){
    digitalWrite(pinRelevadorVen,HIGH); // Por defecto dejaremos el relevador activado.
  } else if (estado = 0){
    digitalWrite(pinRelevadorVen,LOW);
  } 
  
  }
