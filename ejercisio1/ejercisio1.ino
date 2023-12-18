const int botonPin = 3;
const int ledVerdePin = 9;
const int ledRojoPin = 10;

int contadorBoton = 0;

void setup() {
  pinMode(botonPin, INPUT);
  pinMode(ledVerdePin, OUTPUT);
  pinMode(ledRojoPin, OUTPUT);
  digitalWrite(botonPin, HIGH);
}

void loop() {
  if (digitalRead(botonPin) == LOW) {
    delay(500);
    contadorBoton++;
  }
  if (contadorBoton >= 15) {
    parpadearLEDs();
  } else if (contadorBoton >= 10) {
    secuenciasLedsBtnPresionados(0, 1);
  } else if (contadorBoton >= 5) {
    secuenciasLedsBtnPresionados(1, 0);
  } else {
    apagarLEDs();
  }
}

void parpadearLEDs() {
  digitalWrite(ledVerdePin, HIGH);
  digitalWrite(ledRojoPin, HIGH);
  delay(500);

  digitalWrite(ledVerdePin, LOW);
  digitalWrite(ledRojoPin, LOW);
  delay(500);
}

void secuenciasLedsBtnPresionados(int ledVerde, int LedRojo) {
  digitalWrite(ledVerdePin, ledVerde);
  digitalWrite(ledRojoPin, LedRojo);
}

void apagarLEDs() {
  digitalWrite(ledVerdePin, LOW);
  digitalWrite(ledRojoPin, LOW);
}