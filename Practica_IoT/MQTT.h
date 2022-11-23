const char* AP_NAME = "IOT5";
const char* AP_PWD = "12345678";
const char* MQTT_SERVER = "test.mosquitto.org";
const char* MQTT_CLIENT = "IOT5";
#define MQTT_PORT 1883
const char* MQTT_TOPIC_CONFIG = "/ACUARIO/CONFIG";
const char* MQTT_TOPIC_PUBLISH = "/ACUARIO/PALUDARIO";

class MQTT_ESP32 {
  public:
    void MQTT_subscribe (void);
    void MQTT_publish (void);
    void MQTT_setup_WIFI (void);
    void MQTT_setserver (void);
    void MQTT_reconnect(void);
    
  };

    void MQTT_ESP32 :: MQTT_subscribe (void){
      client.subscribe(MQTT_TOPIC_CONFIG);
      }
    void MQTT_ESP32 :: MQTT_publish (void){
      client.publish(MQTT_TOPIC_PUBLISH, "Hola caracola");
      }
    void MQTT_ESP32 :: MQTT_setserver (void){
      client.setServer (MQTT_SERVER, MQTT_PORT);
      }
    void MQTT_ESP32 :: MQTT_setup_WIFI (void){
      
      delay(10);
      Serial.print(F("Conectado a"));
      Serial.print(AP_NAME);
      Serial.print("");
      WiFi.begin(AP_NAME, AP_PWD);
      
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(F(".")); //hasta que se conecte se estaran imprimiendo puntos
            
      }
      Serial.print(F("Se ha conectado de manera exitosa al APcon la direccion"));
      Serial.println(WiFi.localIP()); //Dice la dirrecion ip a la que se conecto
  }
      
      void MQTT_ESP32 :: MQTT_reconnect (){
        // Loop until we're reconnected
        if(!client.connected()){
          while (!client.connected()) {
            Serial.print(F("Conectando al servidor MQTT ")); 
            Serial.println(MQTT_SERVER);
        
            if (client.connect("xxx")) {
              
              Serial.println(F("Suscrito a"));
              Serial.println(F("MQTT_TOPIC"));
              MQTT_subscribe();
              
            } else {
              Serial.print(F("Revisar configuraciones, llama a un ingeniero"));
              Serial.print(client.state());
              Serial.println(F("Intentando nuevamente"));
              // Wait 5 seconds before retrying
              //delay(5000);
            }
  }
        }
        client.loop();
      }
