class Sensores_ESP32 {
   public:

    int humidity = 0;
    int humidityPor = 0;
    int light = 0;
    int lightPor = 0;
    float temp = 0;


   public:
    
    void Temperatura ( void );
    void Humedad (void);
    void Luz (void);
};

void Sensores_ESP32 :: Humedad (void) {

    humidity = analogRead(15) / 4;
    
    if (humidity >= 512){
      humidityPor = 50 - ((((humidity - 511.5) * 100) / 511.5) / 2);
    } else if (humidity <= 511) {
      humidityPor = 50 + 50 - (((humidity * 100) / 511.5) / 2);
    }
  }

void Sensores_ESP32 :: Luz (void) {

    light = analogRead(4) / 4;
    
    if (light >= 512){
      lightPor = 50 - ((((light - 511.5) * 100) / 511.5) / 2);
    } else if (humidity <= 511) {
      lightPor = 50 + 50 - (((light * 100) / 511.5) / 2);
    }
  }

void Sensores_ESP32 :: Temperatura (void) {
      dht.begin();
      temp = dht.readTemperature();
  }
