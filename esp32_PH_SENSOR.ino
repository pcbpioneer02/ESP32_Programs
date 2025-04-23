#define PH_SENSOR_PIN 34  // Use any ADC pin (GPIO34 is analog-only on ESP32)

float calibration_offset = 0.0;  // Adjust after calibration if needed

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("pH Sensor Initialization...");
}

void loop() {
  int analogValue = analogRead(PH_SENSOR_PIN);
  float voltage = analogValue * (3.3 / 4095.0); // Convert ADC to voltage

  // Formula to convert voltage to pH (may vary depending on your sensor)
  // Most sensors output ~0V (acidic) to ~3V (alkaline), 2.5V ≈ pH 7
  float pH = 7 + ((2.5 - voltage) / 0.18);  // 0.18V per pH (approx for many sensors)

  pH += calibration_offset;  // Apply offset if you've calibrated

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | pH: ");
  Serial.println(pH, 2);

  delay(2000);
}
