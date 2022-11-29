#define _1 1000
#define _2 2000
#define _5 5000
#define _10 10000
#define _12 12000

class Task {
  public:
  unsigned long currentMillis = 0,
                time_1s = 0,
                time_2s = 0,
                time_5s = 0,
                time_10s = 0,
                time_12s = 0;
  
  public:
    void task_1s (void);
    void task_2s (void);
    void task_5s (void);
    void task_10s (void);
    void task_12s (void);    
};

void Task :: task_1s (void) {
  if(currentMillis - time_1s >= _1){
    LCD.LCD32(Sensores.humidityPor, Sensores.lightPor, Sensores.temp);
    Sensores.Humedad();
    Sensores.Temperatura();
    Sensores.Luz();
    Serial.print("Hum ");
    Serial.println(Sensores.humidity);
    Serial.print("Luz ");
    Serial.println(Sensores.light);
    Serial.print("Temp ");
    Serial.println(Sensores.temp);
    time_1s = currentMillis;
  }}

void Task :: task_2s (void) {

  if(currentMillis - time_2s >= _2){
    
    
    //Serial.println("Esta es la tarea de 2 segundos");
    //Aqui se deberia pegar un sensor
    time_2s = currentMillis;

  }
}

void Task :: task_5s (void) {
    if(currentMillis - time_5s >= _5){

   // MQTT.MQTT_reconnect (  );
          
    //Serial.println("Esta es la tarea de 5 segundos");
    //Aqui se deberia pegar un sensor
    time_5s = currentMillis;
    
  }
}

void Task :: task_10s (void) {
  if(currentMillis - time_10s >= _10){
    
    time_10s = currentMillis;
    }
    /*
    Serial.println( JSON.CreateJson ( ) );
    MQTT.MQTT_publish ( JSON.CreateJson ( ) );
    Serial.println ( F ( "Se ha publicado un mensaje" ) );*/
}


void Task :: task_12s (void) {
  if(currentMillis - time_12s >= _12){
    //LCD.LCD32(Sensores.humidityPor, Sensores.lightPor, Sensores.temp);
    time_12s = currentMillis;
    }
}
