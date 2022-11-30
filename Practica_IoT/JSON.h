#include <ArduinoJson.h>
class mi_json {
  public: 
    
    
  public:
    
    String CreateJson (  );
};

String mi_json :: CreateJson ( ) {
  
  String TempJson;
  DynamicJsonDocument obj(1024);  // Creamos una instancia de un documento JSON.
  // Aquí colocarían las variables de sus sensores.
  obj["temperatura"] = Sensores.temp;        
  obj["humedad"] = Sensores.humidityPor;
  obj["luz"] = Sensores.lightPor;
  
  // Aquí colocarían las variables del tiempo global.   
  obj["fecha"] = "27/11/2022";
  obj["tiempo"]= "03:41:25"; 
  
  // Aquí colocarían las variables de sus actuadores, es preferible almacenar la fecha y hora del momento en que se activó.
  obj["buzzer"]= "..."; 
  
  serializeJson(obj, TempJson); // Transformamos el objeto en un string.
  
  return  TempJson;
  
}
