#define _1 1000
#define _2 2000
#define _5 5000
#define _10 10000

class Task {
  public:
  unsigned long currentMillis = 0,
                time_1s = 0,
                time_2s = 0,
                time_5s = 0,
                time_10s = 0;
  
  public:
    void PruebaValores (void);
    void task_2s (void);
    void Actu (void);
    void HumTemp (void);
};

void Task :: PruebaValores (void) {
  if(currentMillis - time_1s >= _1){
    //RTC.get_time();
    LCD.LCD32(Sensores.humidityPor, Sensores.lightPor, Sensores.temp);

    Serial.print("hum ");
    Serial.println(Sensores.humidity);
    Serial.print("luz ");
    Serial.println(Sensores.light);
    Serial.print("Temp ");
    Serial.println(Sensores.temp);
    time_1s = currentMillis;

    
  }}

void Task :: task_2s (void) {

  if(currentMillis - time_2s >= _2){
    
    
    //Serial.println("Esta es la tarea de 2 segundos");
    time_2s = currentMillis;

  }
}

void Task :: Actu (void) {
    if(currentMillis - time_5s >= _5){

    if(Sensores.lightPor >= 95){
      Actuadores.Buzzer();
    }

    if(Sensores.temp >= 20){
      Serial.println(Sensores.temp >= 20);
       Actuadores.Ventilador(0);
       Serial.print("Activando papu");
    } else {
      Actuadores.Ventilador(1);
      Serial.print("Desactivando defensa");
    }

    if(Sensores.humidityPor <= 25){
      Actuadores.Bomba(1);
      delay(2000);
      Actuadores.Bomba(0);
    }
    
    Sensores.Luz();
    //MQTT.MQTT_reconnect (  );
          
    time_5s = currentMillis;
    
  }
}

void Task :: HumTemp (void) {
  if(currentMillis - time_10s >= _10){
    Sensores.Humedad();
    Sensores.Temperatura();
    time_10s = currentMillis;
    }
    /*
    Serial.println( JSON.CreateJson ( ) );
    MQTT.MQTT_publish ( JSON.CreateJson ( ) );
    Serial.println ( F ( "Se ha publicado un mensaje" ) );*/
}
