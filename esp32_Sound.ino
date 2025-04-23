#define SOUND_DIGITAL_PIN 26  // Digital pin for detecting sound peaks

void setup() {
  Serial.begin(115200);
  pinMode(SOUND_DIGITAL_PIN, INPUT);
  Serial.println("Voice Sensor Initialized");
}

void loop() {
  int soundDetected = digitalRead(SOUND_DIGITAL_PIN);

  if (soundDetected == LOW) {
    Serial.println("🔊 Sound Detected!");
  } else {
    Serial.println("...quiet...");
  }

  delay(300);
}
