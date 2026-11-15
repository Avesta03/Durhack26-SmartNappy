
/*
  DRYSENSE - Moisture Monitoring System
  Arduino UNO Q + DFRobot Moisture Sensor V2

  Version 1: Continuous data collection
  - Takes multiple readings per measurement
  - Calculates average moisture reading
  - Records elapsed time
  - Outputs CSV data for later analysis
*/

const int moisturePin = A0;

const int numberOfSamples = 10;
const int sampleInterval = 20;
const int outputInterval = 250;

unsigned long lastOutput = 0;

void setup() {
  Serial.begin(115200);
  delay(1500);

  Serial.println("DRYSENSE - Moisture Monitoring");
  Serial.println("Time_ms,Raw_Reading,Average_Reading");
}

void loop() {

  long total = 0;
  int rawReading = 0;

  // Collect multiple sensor readings
  for (int i = 0; i < numberOfSamples; i++) {
    rawReading = analogRead(moisturePin);
    total += rawReading;
    delay(sampleInterval);
  }

  // Calculate average
  float averageReading = (float)total / numberOfSamples;

  // Output data at regular intervals
  if (millis() - lastOutput >= outputInterval) {

    Serial.print(millis());
    Serial.print(",");

    Serial.print(rawReading);
    Serial.print(",");

    Serial.println(averageReading, 2);

    lastOutput = millis();
  }
}
