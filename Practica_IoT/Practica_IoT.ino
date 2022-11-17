#include "Practica_IoT.h"

void setup() {
  // put your setup code here, to run once:
  MSD.MicroSD_init();
  Serial.begin(115200);
  }

void loop() {
/*
  
  MSD.MicroSD_save();
 */ delay( 2000 );
  tsk.currentMillis = millis (); //actualizacion del tiempo desde 
  tsk.task_2s ();//Poner los tres sensores en estos
  tsk.task_5s ();
  tsk.task_10s ();
  
  
  }
