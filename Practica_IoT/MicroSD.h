class MicroSD {
  public:
    String filename = "";
    
  public:
    void MicroSD_init(void);
    void MicroSD_save(void);
    void FileID(void);    
    
};
 
 void MicroSD :: MicroSD_init (void) {

  while(!SD.begin(MICROSD_PIN)){
    //Vierificar si ya esta funcionando
    Serial.println( F ("Error en la detección de la memoria, revisar conexion"));
    delay(2000);
  }
  Serial.println(F ("Se ha detectado exitosamente el modulo SD"));
  // see if the card is present and can be initialized:
 }

 void MicroSD :: MicroSD_save (void) {
  FileID();
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  MICROSD_FILE = SD.open(filename, FILE_APPEND);
  
  // if the file is available, write to it:
  if (MICROSD_FILE) {
    MICROSD_FILE.println("Nether Fortress");
    MICROSD_FILE.close();
    // print to the serial port too:
    Serial.println(F ("Se ha alamcenado correctamente la información"));//F por memoria flash
  }
  // if the file isn't open, pop up an error:
  else {
    
    Serial.println(F ("Error consigue un ingeniero"));
    
  }
 }

 void MicroSD :: FileID (void){
   filename = "/";
   RTC.get_time ();
   RTC.format_date('-');
   filename += RTC._date;
   filename += EXTENSION;
 }
