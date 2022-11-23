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

#include "RTC.h"

RTCDS RTC;

/*Componentes de la microSD*/
#include "DHT.h"

#define DHTPIN 16   
#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

#define MICROSD_PIN 5 //Pin de control de la SD

#include <SPI.h> //Protocolo de cominicacion SPI
#include <SD.h> //Libreria de gestion de la MICRO SD

File MICROSD_FILE;
#define EXTENCION ".json"
#include "MicroSD.h"
MicroSD MSD; //Instancia de la clase microSD

#include "Task.h"
Task tsk;
