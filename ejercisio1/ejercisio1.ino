const int buttonPin = 2; // Cambiar por el pin del botón
const int ledVerdePin = 3; // Cambiar por el pin del LED verde
const int ledRojoPin = 4; // Cambiar por el pin del LED rojo

int buttonPressCount = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledRojoPin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    buttonPressCount++;
    delay(200); // Para evitar la detección de pulsaciones falsas
  }

  if (buttonPressCount > 10 && buttonPressCount <= 15) {
    digitalWrite(ledVerdePin, LOW);
    digitalWrite(ledRojoPin, HIGH);
  } else if (buttonPressCount >= 5 && buttonPressCount <= 10) {
    digitalWrite(ledVerdePin, HIGH);
    digitalWrite(ledRojoPin, LOW);
  } else if (buttonPressCount > 15) {
    digitalWrite(ledVerdePin, HIGH);
    digitalWrite(ledRojoPin, HIGH);
    delay(1000);
    digitalWrite(ledVerdePin, LOW);
    digitalWrite(ledRojoPin, LOW);
    delay(1000);
  }
}