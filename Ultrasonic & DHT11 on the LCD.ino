// Ultrasonic & DHT 11 on the LCD

//hook up HC-SR04 with trig to arduino pin 10 and echo to arduino pin 13.
#define trigPin 13
#define echoPin 10
float duration, distance;

// --Library-- / Bibliotheken
  #include <LiquidCrystal.h>
  #include <DHT.h>
  #include <DHT_U.h>
  
// Sensor DHT-11 (DHT-11 Temperature and Humidity Sensor)
  #define DHTPIN 8
  #define DHTTYPE DHT11

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
// Serial Monitor
  Serial.begin(9600);

// LCD Display
  lcd.begin(16, 2);
  lcd.setCursor(7,1);
  
  dht.begin();
  
// LCD Display (Temp and Humidity)
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(8,0);
  lcd.print("Humid:");
  delay(1500);

// Ultrasonic pins
pinMode(trigPin, OUTPUT);
pinMode (echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 lcd.setCursor(12,1);
  lcd.print("%");


// ...
  lcd.setCursor(12,0);
  lcd.print(" ");
  
// -- Temp and Humidity --
// Temp = Temperature and Humid = Humidity
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
  lcd.setCursor(14,0);
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

  // write a pulse to the HC-SR04 Trigger Pin
digitalWrite (trigPin, LOW);
delayMicroseconds (2);
digitalWrite (trigPin, HIGH);
delayMicroseconds (10);
digitalWrite (trigPin, LOW);
// Measure the responce  from he HC-SR04 Echo Pin
duration = pulseIn (echoPin, HIGH);
// determine distance from duration
// use 343 meters per second as speed of sound
distance = (duration/2)*0.0343;
// send results to serial monitor
Serial.print ("Distance = ");
if (distance >= 400 || distance <= 2){
  Serial.println ("Out of range");
}
else { 
  Serial.print (distance);
  Serial.println (" cm");
  delay (500);
}
//send results to lcd
lcd.setCursor (0,1);
lcd.print ("Dist = ");
if (distance >= 400 || distance <= 2){
  lcd.println ("Out of range");
}
else { 
  lcd.print (distance);
  lcd.println (" cm  ");
  delay (500);
}
delay (500);

}
