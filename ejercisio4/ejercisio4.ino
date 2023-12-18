#define BUTTON_PIN 8
#define POT_PIN A0
#define LED_PINS {2, 3, 4, 5, 6}

int ledPins[] = LED_PINS;
int numLeds = 1;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(POT_PIN, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    numLeds = (numLeds % 5) + 1;
    delay(200); // Debounce
  }

  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[random(5)], HIGH);
  }

  delay(map(analogRead(POT_PIN), 0, 1023, 1000, 100)); // Ajusta la velocidad de cambio basado en el potenciómetro
}