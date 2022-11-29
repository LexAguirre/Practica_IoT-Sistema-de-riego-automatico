byte customChar[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B01110,
  B01110
};

class LCD_ESP32 {
   public:
    void LCD32 (int humedad, int luz, int temperatura);
   
  };

void LCD_ESP32 :: LCD32 (int humedad, int luz, int temperatura){
   lcd.backlight();
   lcd.init();                      // initialize the lcd 
   lcd.setCursor(0,0);
   lcd.print("Prueba ");
   lcd.setCursor(0,1);
    lcd.createChar(0, customChar);
    lcd.home();
    lcd.write(0);
   lcd.print("-");
   lcd.print(luz);
   lcd.print("% ");   
   lcd.print(humedad);
   lcd.print("% ");
   lcd.print(temperatura);
   lcd.print("°C");

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
