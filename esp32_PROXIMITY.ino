#define PROXIMITY_PIN 27  // Digital pin connected to sensor OUT

void setup() {
  Serial.begin(115200);
  pinMode(PROXIMITY_PIN, INPUT);
  Serial.println("Proximity Sensor Initialized");
}

void loop() {
  int sensorValue = digitalRead(PROXIMITY_PIN);

  if (sensorValue == LOW) {
    Serial.println("🚨 Object Detected!");
  } else {
    Serial.println("✅ No Object");
  }

  delay(500);
}
