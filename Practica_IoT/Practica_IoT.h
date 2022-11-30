/***************************
*                                                                            *
*      NOMBRE:      Datalogger.                                              *
*      FECHA:       24 de abril de 2022.                                     *
*      VERSIÓN:     1.0.                                                     *
*                                                                            *
*      AUTOR:       Esli Castellanos Berján.                                 *
*      E-MAIL:      esli_castellanos@ucol.mx.                                *
*      FACULTAD:    Telemática.                                              *      
*      CARRERA:     Ingeniería en Software.                   *
*      MATERIA:     Sistemas embebidos para el Internet de las cosas.        *
*                                                                            *
*      MICROCONTROLADOR:          Xtensa® dual­core 32­bit LX7.              *
*      MARCA COMERCIAL:           ESP32.                                     *
*                                                                            *
*                                                                            *
**************************
*                                                                            *
*      DESCRIPCIÓN DEL PROGRAMA:                                             *
*      Arquitectura de software para implementar un datalogger mediante el   *       
*      uso del módulo de lectura MicroSD y un reloj en tiempo real.          *
*                                                                            *
*      DETALLES:                                                             *
*      RTC:        DS1307.                                                   *
*      MicroSD:    Genérico.                                                 *
*                                                                            *
**************************/
//Reloj--------------------------------------------
#include "RTC.h"
RTCDS RTC;

//Buzzer------------------------------------------
//buzzer_ESP32.SongBuz()

//LCD---------------------------------------------
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
#include "LCD.h"
LCD_ESP32 LCD;

//Sensores DHT11-----------------------------------
#include "DHT.h"

#define DHTPIN 16   
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

//Ejecutador de los sensores-----------------------
#include "Sensores.h"
Sensores_ESP32 Sensores;

//Ejecutador de los actuadores---------------------
#include "Actuadores.h"
Actuadores_ESP32 Actuadores;

//Componentes de la microSD------------------------
#define MICROSD_PIN 5 //Pin de control de la SD

#include <SPI.h> //Protocolo de cominicacion SPI
#include <SD.h> //Libreria de gestion de la MICRO SD

File MICROSD_FILE;
#define EXTENSION ".json"

#include "JSON.h"
 mi_json JSON;
 
#include "MicroSD.h"
MicroSD MSD; //Instancia de la clase microSD

//MQTT--------------------------------------------

#include <WiFi.h>
  WiFiClient ESP32_WIFI;
 
#include <PubSubClient.h>
PubSubClient client (ESP32_WIFI);

#include "MQTT.h"
MQTT_ESP32 MQTT;

//Tareas--------------------------------------------
#include "Task.h"
Task tsk;
