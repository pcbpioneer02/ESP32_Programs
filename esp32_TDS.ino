#define TDS_PIN 34  // ADC pin on ESP32

float calibrationFactor = 0.5; // Adjust based on your sensor

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("TDS Sensor Initialized");
}

void loop() {
  int analogValue = analogRead(TDS_PIN);
  float voltage = analogValue * (3.3 / 4095.0); // Convert ADC reading to voltage

  // Gravity TDS formula (approx):
  float tdsValue = (133.42 * voltage * voltage * voltage
                   - 255.86 * voltage * voltage
                   + 857.39 * voltage) * calibrationFactor;

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | TDS: ");
  Serial.print(tdsValue, 2);
  Serial.println(" ppm");

  delay(2000);
}
