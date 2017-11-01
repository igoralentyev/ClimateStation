// Lib for DHT22
#include <DHT_U.h>
#include <DHT.h>

// Libs for BMP
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// DHT defines
#define DHTPIN 2
#define DHTTYPE DHT22

// BMP defines
#define BMP_SCK 13
#define BMP_MISO 12
#define BMP_MOSI 11 
#define BMP_CS 10

// Dht initialize
DHT dht(DHTPIN, DHTTYPE);
// BMP initialize
Adafruit_BMP280 bmp;

void setup() {
	Serial.begin(9600);
	dht.begin();
	bmp.begin();
}

void loop() {
	// Vars for DHT
	float hum = dht.readHumidity();
	float temp = dht.readTemperature();
	float heatIndex = dht.computeHeatIndex(temp, hum, false);
	// Vars for BMP
	float tempBMP = bmp.readTemperature();
	float pressurePa = bmp.readPressure();
	float pressure = pressurePa / 133.3224;
	float altitude = bmp.readAltitude(pressurePa); // It's not working correct now, maybe error with pressurePa variable type.

	// Print for DHT
	Serial.println(hum);
	Serial.println(temp);
	Serial.println(heatIndex);

	// Print for BMP
	Serial.println(tempBMP);
	Serial.println(pressure);


	// Delay for 2 sec
	delay(2000);
}
