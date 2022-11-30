#include "Practica_IoT.h"

void setup() {
  
  MSD.MicroSD_init();
  RTC.init_ds1307();
  MQTT.MQTT_setup_WIFI();
  MQTT.MQTT_setserver();
  Serial.begin(115200);
  }

void loop() {
  tsk.currentMillis = millis (); //actualizacion del tiempo desde 
  tsk.task_1s ();
  tsk.task_2s ();//Poner los tres sensores en estos
  tsk.task_5s ();
  tsk.task_10s ();
  delay( 2000 );
  MSD.MicroSD_save(); 
  }
