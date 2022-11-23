#include "Practica_IoT.h"

void setup() {
  // put your setup code here, to run once:
  //MSD.MicroSD_init();
  //RTC.init_ds1307();
  MQTT.MQTT_setup_WIFI();
  MQTT.MQTT_setserver();
  Serial.begin(115200);
  }

void loop() {

   delay( 2000 );
  MSD.MicroSD_save();
 
 
 /*
  tsk.currentMillis = millis (); //actualizacion del tiempo desde 
  tsk.task_2s ();//Poner los tres sensores en estos
  tsk.task_5s ();
  tsk.task_10s ();
  */ 
  
  }
