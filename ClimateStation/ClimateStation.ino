#include <DHT.h>

// DHT defines
#define DHTPIN 2
#define DHTTYPE DHT22

// Dht initialize
DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(9600);
	dht.begin();
}

void loop() {
	// Vars for DHT
	float hum = dht.readHumidity();
	float temp = dht.readTemperature();

	if (isnan(hum) || isnan(temp)) {
		char errorDHT22[] = "error reading data";
	}

	Serial.print("Humidity: ");
	Serial.print(hum);
	Serial.print(" %\t");
	Serial.print("Temperature: ");
	Serial.print(temp);
	Serial.println(" *C ");
	delay(2000);
}
