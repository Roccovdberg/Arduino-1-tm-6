#include <Servo.h>

const int trigPin = 12; // Trig pin van de ultrasone sensor
const int echoPin = 11; // Echo pin van de ultrasone sensor
const int servoPin = 9; // Pin waarop de servo is aangesloten

Servo servoMotor; // Van de servomotor een object maken

void setup() {
  pinMode(trigPin, OUTPUT); // Trigpin als output instellen omdat het data stuurt
  pinMode(echoPin, INPUT); // Echopin als input instellen omdat het data ontvangt
  
  servoMotor.attach(servoPin); // Servopin verbinden met de pin die staat bij servopin
  servoMotor.write(0); // Startpositie van de servo op 0 graden
  delay(100); // Kleine vertraging om servo te identificeren
}

//Loopen van functie doorgedraaid
void loop() {
  doorgedraaid();
}

// Functie om de servomotor aan te roepen met de ultrasoonsensor
void doorgedraaid() {
  long duration, distance; // 2 variabelen aanmaken
  
  // Stuur ultrasone puls
  digitalWrite(trigPin, LOW); // trigpin laagzetten om te zorgen dat er geen puls is van een eerdere meting
  delayMicroseconds(10); // Kleine vertraging
  digitalWrite(trigPin, HIGH); // Starten van de puls
  delayMicroseconds(10); // Kleine vertraging
  digitalWrite(trigPin, LOW); // Puls eindigen
  
  // Lees de echo-tijd van de ultrasone sensor
  duration = pulseIn(echoPin, HIGH);
  
  // Bereken de afstand in centimeters
  distance = duration * 0.034 / 2; // Formule betekent: Afstand = de tijd die het duurt voor de echo om de puls te ontvangen, keer,
  // snelheid van geluid(34 microseconden per centimeter) delen door 2 vanwege heen en terug

  // If statement bij een afstand van minder dan 4 centimeter
  if (distance < 4) {
    servoMotor.write(180); // Draai 180 graden
    delay(1000); // Vertraging om te bewegen
  } else if (distance >= 4 && distance < 10) { // If statement van tussen de 4 en 10 centimeter
    // Bereken de hoek van de servo op basis van de afstand
    int angle = map(distance, 10, 4, 180, 0); // Bekijk de distance van tussen 4 en 10 en bereken daarbij het goede punt tussen 180 en 0 graden
    servoMotor.write(angle); //Breng de servomotor naar de berekende hoek
    delay(100); // Kleine vertraging om te bewegen
  } else {
    servoMotor.write(0); // Zet de servomotor op 0 graden bij meer dan 10 centimeter of een niet gevonden afstand
  }
  
  delay(100); // Kleine vertraging voor het opnieuw uitvoeren van de loop
}
