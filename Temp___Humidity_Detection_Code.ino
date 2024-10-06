#include "DHT.h"

#define DHTPIN 7        // Try using pin 7 for the DATA pin
#define DHTTYPE DHT11   // Define DHT11 sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);  // Start Serial communication
  Serial.println("DHT11 sensor reading...");

  dht.begin();  // Initialize the DHT sensor
}

void loop() {
  delay(2000);  // Wait a few seconds between measurements

  float temperature = dht.readTemperature();  // Read temperature
  float humidity = dht.readHumidity();        // Read humidity

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print readings to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
