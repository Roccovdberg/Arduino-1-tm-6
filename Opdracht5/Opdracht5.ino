#include <Servo.h>

const int buttonPin1 = 13;    // Pin van het linkse knopje
const int buttonPin2 = 12;    // Pin van het rechtse knopje
const int servoPin = 9;       // Pin voor de servomotor

Servo myServo;               // Object maken met als naam myServo

const int startAngle = 0; // Het beginpunt
const int endAngle = 120; // Het uiterste punt

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP); // Verbind met eerder meegegeven pin
  pinMode(buttonPin2, INPUT_PULLUP); // Verbind met eerder meegegeven pin
  myServo.attach(servoPin); // Verbind met eerder meegegeven pin
  myServo.write(startAngle);  // Zet de servo op de beginpositie
}

// Loop de delay en de functie controlServo()
void loop() {
  delay(50); // Kleine vertraging
  controlServo();
}

// Functie voor het draaien van de servomotor
void controlServo() {
  bool button1State = !digitalRead(buttonPin1); // Omgekeerde logica vanwege INPUT_PULLUP
  bool button2State = !digitalRead(buttonPin2); // Omgekeerde logica vanwege INPUT_PULLUP

  if (button1State && button2State) {
    // Als beide knoppen ingedrukt zijn
    moveServo(endAngle, 3000); // Draai naar endAngle in 3 seconden
    delay(5000);               // Vertraging van 5 seconden
    moveServo(startAngle, 500); // Draai terug naar startAngle in een halve seconde
  } else if (button1State) { // Alleen het linker knopje
    moveServo(endAngle, 3000); // Draai naar endAngle in 3 seconden
    moveServo(startAngle, 3000); // Draai terug naar startAngle in 3 seconden
  } else if (button2State) { // Alleen het rechter knopje
    moveServo(endAngle, 500); // Draai naar endAngle in 0.5 seconden
    moveServo(startAngle, 500); // Draai terug naar startAngle in 0.5 seconden
  }
}

// Functie om de servo naar een bepaalde hoek te bewegen met een bepaalde snelheid
void moveServo(int targetAngle, int duration) { // Functie uitvoeren met 2 variabelen, targetAngle is het punt waar het heen moet, duration is hoelang het daarover mag doen
  int currentAngle = myServo.read(); // Bekijk de plek waar de servomotor is
  int steps = abs(targetAngle - currentAngle); // Bereken het aantal stappen(in graden) dat nodig is om van de huidige positie naar de targetAngle te komen
  int stepDelay = duration / steps; // Bereken de vertraging tussen elke stap door de tijd te delen door het aantal stappen

  if (targetAngle > currentAngle) { // Kijk of de targetAngle groter is dan de currentAngle, 
    for (int pos = currentAngle; pos <= targetAngle; pos++) { // Loop om de servo geleidelijk naar de targetAngle te bewegen, zolang de currentAngle kleiner of gelijk is aan de targetAngle
      myServo.write(pos); // Schrijf de huidige positie naar de servo
      delay(stepDelay); // Vertraging bij elke stap
    }
  } else { // Als de doelhoek kleiner is dan de huidige positie
    for (int pos = currentAngle; pos >= targetAngle; pos--) { // Loop om de servo geleidelijk naar de targetAngle te bewegen, zolang de currentAngle groter of gelijk is aan de targetAngle
      myServo.write(pos); // Schrijf de huidige positie naar de servo
      delay(stepDelay); // Vertraging bij elke stap
    }
  }
}
