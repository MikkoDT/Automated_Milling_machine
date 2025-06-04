#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4); // set the LCD address to 0x27 for a 20 chars and 4 line display

void setup()
{
lcd.init(); // initialize lcd
lcd.backlight();
lcd.begin(20,4);
Serial.begin(9600);
}
void loop()
{

lcd.setCursor(0,0);
lcd.print("Temp: ");

lcd.print((char)223);//show degree symbol
lcd.print("F");
lcd.setCursor(0,1);
lcd.print("Humidity: ");

lcd.print("%");
delay(2000);
}