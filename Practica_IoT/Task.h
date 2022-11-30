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
    void task_1s (void);
    void task_2s (void);
    void task_5s (void);
    void task_10s (void);
};

void Task :: task_1s (void) {
  if(currentMillis - time_1s >= _1){
    LCD.LCD32(Sensores.humidityPor, Sensores.lightPor, Sensores.temp);

    time_1s = currentMillis;

    
  }}

void Task :: task_2s (void) {

  if(currentMillis - time_2s >= _2){
    
    
    //Serial.println("Esta es la tarea de 2 segundos");
    time_2s = currentMillis;

  }
}

void Task :: task_5s (void) {
    if(currentMillis - time_5s >= _5){

    if(Sensores.lightPor >= 95){
      Actuadores.Buzzer();
    }

    if(Sensores.temp >= 24){
      Actuadores.Ventilador(1);
    } else {
      Actuadores.Ventilador(0);
    }

    if(Sensores.humidityPor <= 25){
      Actuadores.Bomba(1);
      delay(2000);
      Actuadores.Bomba(0);
    }
    Sensores.Luz();
    // MQTT.MQTT_reconnect (  );
          
    //Serial.println("Esta es la tarea de 5 segundos");
    time_5s = currentMillis;
    
  }
}

void Task :: task_10s (void) {
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
