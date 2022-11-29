#include "RTClib.h"

RTC_DS1307 rtc;

class RTCDS {
  public:
    String _date = "", _time = "";
    uint8_t _day = 0, _month = 0, _second = 0, _minute = 0, _hour = 0;
    uint16_t _year = 0;
    
  public:
    void init_ds1307 (void);
    void get_time (void);
    void format_time (void);
    void format_date (char);
    
};

void RTCDS :: init_ds1307 (void) {
   while (! rtc.begin()) {
    
    Serial.println(F("revisa la conexión del reloj"));//guarda en la memoria flash
    delay(500);
    
  }
}

void RTCDS :: get_time (void){
    DateTime now = rtc.now();  
    _year = now.year();
    _month = now.month ();
    _day = now.day();
    _hour = now.hour ();
    _minute = now.minute ();
    _second = now.second ();
}

void RTCDS :: format_time (void){
  
  _time = "";
  if (_hour < 10)_time += '0';
  _time += _hour;
  _time += ":";
  
  if (_minute < 10)_time += '0';
  _time += _minute;
  _time += ":";
  
  if (_second < 10)_time += '0';
  _time += _second;

}

void RTCDS :: format_date (char character){

  _date = "";
  if (_day < 10)_date += '0';
  _date += _day;
  _date += character;
  if (_month < 10)_date += '0';
  _date += _month;
  _date += character;
  //if (_year < 10)_date += '0';
  _date += _year;
  //_date = character;
}
