const char* AP_NAME = "IOT5";
const char* AP_PWD = "12345678";
const char* MQTT_SERVER = "test.mosquitto.org";
const char* MQTT_CLIENT = "IOT5";
#define MQTT_PORT 1883
const char* MQTT_TOPIC_CONFIG = "/ACUARIO/CONFIG";
const char* MQTT_TOPIC_PUBLISH = "/ACUARIO/PALUDARIO";

class MQTT_ESP32 {
  
  public:
    void MQTT_subscribe ( void );
    void MQTT_publish ( String );
    void MQTT_setup_WIFI ( void );
    void MQTT_setserver ( void );   
    void MQTT_reconnect ( void ); 
  
};


void MQTT_ESP32 :: MQTT_subscribe ( void ){
  
   //client.subscribe ( MQTT_TOPIC_CONFIG  );
   
}

void MQTT_ESP32 :: MQTT_publish ( String message ){
  
   client.publish( MQTT_TOPIC_PUBLISH, message.c_str ( ) );
   
}

void MQTT_ESP32 :: MQTT_setserver  ( void ){
  
  client.setServer( MQTT_SERVER, MQTT_PORT );
  
}

void MQTT_ESP32 :: MQTT_setup_WIFI ( void ){

  delay ( 10 );  
  Serial.print( F ( "Conectando a " ) );
  Serial.print ( AP_NAME );
  Serial.print ( " " );
  WiFi.begin( AP_NAME, AP_PWD );
  while ( WiFi.status() != WL_CONNECTED ) {
  
    delay(500);
    Serial.print( F ( "." ) );
    
  }
  
  Serial.print( F ( "Se ha conectado de manera exitosa al APcon la dirección " ) );
  Serial.println ( WiFi.localIP ( ) );
}

void MQTT_ESP32 :: MQTT_reconnect ( ) {

  if ( !client.connected ( )) {
    while ( !client.connected ( ) ) {
    Serial.println ( F ( "Conectando al servidor MQTT " ) );
    Serial.print ( MQTT_SERVER );

    if ( client.connect ( "xxx" ) ) {
      
      Serial.println ( F ( "Se ha suscrito a " ) );
      Serial.println ( F ( "MQTT_TOPIC" ) );
      MQTT_subscribe ();
      
    } else {
      Serial.print( F ( "Revisar configuraciones, llama a un ingeniero" ) );
      Serial.print ( client.state ( ) );
      Serial.println( F( "Intentando nuevamente" ) );

      //delay(5000);
    }
  }
  }
  client.loop();
}
  
