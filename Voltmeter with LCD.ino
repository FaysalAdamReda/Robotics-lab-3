//Voltmeter with LCD

//library code
#include <LiquidCrystal.h>

/*initialize the library by associating any needed LCD interferance pin 
with the arduino pin number it is connected to*/

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int snesorValue = 0;
int sensorPin = A0;


void setup() {
// set up the LCD's number of colums and rows:
lcd.begin(16, 2);
//print a mesage to the LCd.
lcd.print("DigitalVoltmeter");
Serial.begin(9600);

}

Void loop(){
// set the cursor to column 0, line 1
// line 1 is the second row, since counting begins with 0
lcd.setCursor(0,1);
sensorValue = analogRead(sensorPin);
float voltage = 5.0*(sensorValue)/1023;
Serial.print("Voltage = ");
Serial.prinln(voltage);
lcd.print("Voltage = ");
lcd.print(voltage);
delay(1);
  
}