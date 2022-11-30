byte customCharFoco[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B01110,
  B01110
};

byte customCharAgua[] = {
  B00100,
  B01110,
  B01010,
  B10101,
  B10011,
  B10001,
  B10001,
  B01110
};

byte customCharCentigrados[] = {
  B10000,
  B00111,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B00111
};

class LCD_ESP32 {
   public:
    void LCD32 (int humedad, int luz, int temperatura);
   
  };

void LCD_ESP32 :: LCD32 (int humedad, int luz, int temperatura){
   lcd.backlight();
   lcd.init();                      // initialize the lcd 
   lcd.setCursor(0,1);
   lcd.print(RTC._hour);
   lcd.print(":");
   lcd.print(RTC._minute);
   lcd.print(":");
   lcd.print(RTC._second);
   lcd.setCursor(0,2);
    lcd.createChar(0, customCharFoco);
    lcd.home();
    lcd.write(0);
   lcd.print(" ");
   lcd.print(luz);
   lcd.print("% ");
    /*lcd.createChar(1, customCharFoco);
    lcd.print("-");
   lcd.createChar(0, customCharAgua);
   lcd.home();
   if (luz <= 9) {
   lcd.write(6); 
    } else {
   lcd.write(7);   
    }*/
   lcd.print(humedad);
   lcd.print("% ");
   lcd.print(temperatura);
   lcd.print("C");

    /*
    
    lcd.setCursor(0,0);
    lcd.print(now.year(), DEC);
    lcd.print('/');
    lcd.print(now.month(), DEC);
    lcd.print('/');
    lcd.print(now.day(), DEC);
    lcd.setCursor(0,1);
    lcd.print(now.hour(), DEC);
    lcd.print(':');
    lcd.print(now.minute(), DEC);
    lcd.print(':');
    lcd.print(now.second(), DEC);
*/
}
