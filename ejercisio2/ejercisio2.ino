#define POT_PIN A0
#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4

void setup() {
  pinMode(POT_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
}

void sequence1() {
  digitalWrite(LED1_PIN, HIGH);
  delay(1000);
  digitalWrite(LED2_PIN, HIGH);
  delay(1000);
  digitalWrite(LED3_PIN, HIGH);
  delay(1000);
}

void sequence2() {
  digitalWrite(LED3_PIN, HIGH);
  delay(1000);
  digitalWrite(LED2_PIN, HIGH);
  delay(1000);
  digitalWrite(LED1_PIN, HIGH);
  delay(1000);
}

void loop() {
  int potValue = analogRead(POT_PIN);

  if (potValue <= 500) {
    sequence1();
  } else if (potValue <= 1000) {
    sequence2();
  }

  // Apaga todos los LEDs antes de la próxima lectura
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  delay(1000);
}