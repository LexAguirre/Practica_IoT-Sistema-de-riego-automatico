#define _2 2000
#define _5 5000
#define _10 10000

class Task {

  public:
  unsigned long currentMillis = 0,
                time_2s = 0,
                time_5s = 0,
                time_10s = 0;
  
  public:
    void task_2s (void);
    void task_5s (void);
    void task_10s (void);    
};

void Task :: task_2s (void) {

  if(currentMillis - time_2s >= _2){
    //Serial.println("Esta es la tarea de 2 segundos");
    //Aqui se deberia pegar un sensor
    time_2s = currentMillis;

    int humESP = analogRead(2);
    int humidity = humESP / 4;
    int humidityPor = 0;
    if (humidity >= 512){
      humidityPor = 50 - ((((humidity - 511.5) * 100) / 511.5) / 2);
    } else if (humidity <= 511) {
      humidityPor = 50 + 50 - (((humidity * 100) / 511.5) / 2);
    }
        Serial.print("Lectura:");
    Serial.println(humidity);
    Serial.print("Lectura:");
    Serial.print(humidityPor);
    Serial.println(" %");
    //Paso 3
    if(humidityPor <= 100 & humidityPor >= 71){
        Serial.println("Sensor en agua");  
    } else if(humidityPor <= 70 & humidityPor >= 31){
        Serial.println("Sensor en suelo húmedo");
    }else if(humidityPor <= 30){
        Serial.println("Sensor en suelo seco");
    }
  }
}

void Task :: task_5s (void) {
    if(currentMillis - time_5s >= _5){
    //Serial.println("Esta es la tarea de 5 segundos");
    //Aqui se deberia pegar un sensor
    time_5s = currentMillis;

    int light = analogRead(4) / 4;

    Serial.print("Reading = ");
    Serial.print(light); //lecturas analogicas

    if (light < 100){
      Serial.println(" - Very bright");
    } else if (light < 200){
      Serial.println(" - Bright");
    } else if (light < 500){
      Serial.println(" - Light");
    } else if (light < 800){
      Serial.println(" - Dim");
    } else {
      Serial.println(" - Dark");
    }
  }
}

void Task :: task_10s (void) {
  
    dht.begin();
    
    float t = dht.readTemperature();

      Serial.print(F("Temperature: "));
      Serial.print(t);
      Serial.println(F("°C "));
}
