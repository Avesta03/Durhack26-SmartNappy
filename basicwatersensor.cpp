// Simple moisture sensor test
// Reads an analogue moisture sensor and sends the value to Serial Monitor

const int moisturePin = A0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Moisture sensor test started");
}

void loop() {
  int moistureValue = analogRead(moisturePin);

  Serial.print("Moisture reading: ");
  Serial.println(moistureValue);

  delay(500);
}