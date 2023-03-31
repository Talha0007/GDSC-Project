int vib_pin = 32;
int led_pin = 2;
const int BUZZER_PIN = 14;

void setup() {
  Serial.begin(9600);
  pinMode(vib_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);  // Set the buzzer pin as an output
}

void loop() {
  int val = digitalRead(vib_pin);

  if (val == HIGH) {  // If vibration is detected
    digitalWrite(led_pin, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);  // Activate the buzzer
    delay(100);
    digitalWrite(led_pin, LOW);
    digitalWrite(BUZZER_PIN, LOW);  // Deactivate the buzzer
    delay(100);
  } else {
    digitalWrite(led_pin, LOW);
    digitalWrite(BUZZER_PIN, LOW);  // Deactivate the buzzer
  }
}
