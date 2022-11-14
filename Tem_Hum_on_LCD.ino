/*
-------------------------------------------------------------------------------------------
- Library required:                                                                       -
- "LiquidCrystal", "DHT_sensor_library" and "Adafruit_Sensor-master"                      -
- Download: Adafruit_Sensor-master on Github: https://github.com/adafruit/Adafruit_Sensor -
- Put it in your Arduiono dictory "libraries"                                             -
- License: GNU General Public License version 3 or later (GPL3+)                          -
- By HilfePlus                                                                            -
-------------------------------------------------------------------------------------------
*/

// --Library-- / Bibliotheken
  #include <LiquidCrystal.h>
  #include <DHT.h>
  #include <DHT_U.h>
  
// Sensor DHT-11 (DHT-11 Temperature and Humidity Sensor)
  #define DHTPIN 13
  #define DHTTYPE DHT11

// LCD Display (PIN)(LCD1602 Module)
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  DHT dht(DHTPIN, DHTTYPE);


void setup() {
// Serial Monitor
  Serial.begin(9600);

// LCD Display
  lcd.begin(16, 2);
  lcd.setCursor(7,1);
  
  dht.begin();
  
// LCD Display (Temp and Humidity)
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(0,1);
  lcd.print("Humid:");
  delay(1500);
  }


void loop() {
  lcd.setCursor(12,1);
  lcd.print("%");


// ...
  lcd.setCursor(12,0);
  lcd.print(" ");
  
// -- Temp and Humidity --
// Temp = Temperature in Fahrenheit and Humid = Humidity
    float f = dht.readHumidity();
    float c = dht.readTemperature();

  // Sensor Error (For Example No Sensor)
    if (isnan(f) && (c)) {
      lcd.clear();
      lcd.setCursor(4,1);
      lcd.print("|SENSOR|");
      lcd.setCursor(4,0);
      lcd.print("|ERROR |");  
      delay(1000);
      return;
      }
  
// LCD Display (values)
  lcd.setCursor(7,0);
  lcd.print(c);
  lcd.setCursor(7,1);
  lcd.print(f);

// Serial Monitor
  Serial.println("-  Result  -");
  Serial.print("Temp:  "); 
  Serial.println(c);
  Serial.print("Humid: ");
  Serial.println(f);
  Serial.println("- - -  - - -");
  Serial.println(" ");
  Serial.println(" ");

}
