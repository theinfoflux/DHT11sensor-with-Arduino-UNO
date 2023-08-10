#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "DHT.h"
int DHTPIN= 2;
int buzzer=6;
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
float temp; //to store the temperature value
float hum; // to store the humidity value

void setup() {
Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  dht.begin();          //Begins to receive Temperature and humidity values.  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
  delay(10);
 
}
void loop() {
 temp = dht.readTemperature();
 hum = dht.readHumidity();
 Serial.print("temperature = ");
 Serial.println(temp);
 Serial.print("humidity = ");
 Serial.println(hum);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 10);
  display.print("T:"+String(temp));
   display.print((char)247);
  display.print("C");
    display.setTextSize(2);
  display.setCursor(0, 40);
 display.print("H:"+String(hum)+"%"); 
  display.display();
if(temp>42)
{
  digitalWrite(buzzer,HIGH);
  delay(2000);
  digitalWrite(buzzer,LOW);
  }
  else
  {
      digitalWrite(buzzer,LOW);
   }
   delay(1000);
}
