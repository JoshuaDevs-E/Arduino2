#define LEFT_BUTTON_PIN 8
#define RIGHT_BUTTON_PIN 9
#define LED_PINS {2, 3, 4, 5, 6}

int ledPins[] = LED_PINS;
int currentLed = 2; // Inicia con el LED #3 encendido

void setup() {
  pinMode(LEFT_BUTTON_PIN, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON_PIN, INPUT_PULLUP);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  digitalWrite(ledPins[currentLed], HIGH);
}

void blink(int pin, int times, int interval) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);
    delay(interval);
    digitalWrite(pin, LOW);
    delay(interval);
  }
  digitalWrite(pin, HIGH); // Deja el LED encendido
}

void loop() {
  if (digitalRead(LEFT_BUTTON_PIN) == LOW) {
    digitalWrite(ledPins[currentLed], LOW);
    currentLed = (currentLed - 1 + 5) % 5;
    if (currentLed == 4) {
      for (int i = 0; i < 5; i++) {
        blink(ledPins[i], 4, 500);
      }
    } else {
      blink(ledPins[currentLed], 3, 1000);
    }
  }

  if (digitalRead(RIGHT_BUTTON_PIN) == LOW) {
    digitalWrite(ledPins[currentLed], LOW);
    currentLed = (currentLed + 1) % 5;
    if (currentLed == 0) {
      for (int i = 0; i < 5; i++) {
        blink(ledPins[i], 4, 500);
      }
    } else {
      blink(ledPins[currentLed], 3, 1000);
    }
  }
}