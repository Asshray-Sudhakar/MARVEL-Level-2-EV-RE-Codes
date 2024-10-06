// Define the analog pin, the LM35's Vout pin is connected to
#define sensorPin A1
#define ledControlPin 9 // Pin to control the base of BJT

const float temperatureThreshold = 40.0; // Set threshold at 40°C

void setup() {
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);

  // Initialize the ledControlPin as an output
  pinMode(ledControlPin, OUTPUT);
  digitalWrite(ledControlPin, LOW); // Ensure the LED is initially off

  // Inform the user about the temperature threshold
  Serial.print("LED will turn on when temperature exceeds ");
  Serial.print(temperatureThreshold);
  Serial.println("°C");
}

void loop() {
  // Get the voltage reading from the LM35
  int reading = analogRead(sensorPin);

  // Convert the reading into voltage
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = voltage * 100;

  // Print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); // Degree symbol
  Serial.print("C  |  ");
  
  // Print the temperature in Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0"); // Degree symbol
  Serial.println("F");

  // Turn the LED on if the temperature exceeds the threshold
  if (temperatureC > temperatureThreshold) {
    digitalWrite(ledControlPin, HIGH); // Turn on the BJT, hence the LED
    Serial.println("LED ON");
  } else {
    digitalWrite(ledControlPin, LOW); // Turn off the BJT, hence the LED
    Serial.println("LED OFF");
  }

  delay(1000); // wait for 1 second before the next reading
}
