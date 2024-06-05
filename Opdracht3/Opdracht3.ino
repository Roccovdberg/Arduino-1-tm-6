// Start de counter op 0
int counter = 0;

void setup() {
  pinMode(11, OUTPUT); // Ledlamp 1
  pinMode(8, INPUT); // Knop
  pinMode(5, OUTPUT); // Ledlamp 2
}

void loop() {
  // Controleer of de knop is ingedrukt
  if (digitalRead(8) == HIGH) { // Als de knop is ingedrukt
    counter++; // Verhoog de teller bij elke knopdruk
    
    // Controleer de hoogte van de teller en schakel de lampjes om en om aan en uit
    if (counter % 2 == 0) { // Als delen door 2 geen rest oplevert
      digitalWrite(5, HIGH); // Zet pin 5 aan
      digitalWrite(11, LOW); // Zet pin 11 uit
    } else {
      digitalWrite(5, LOW); // Zet pin 5 uit
      digitalWrite(11, HIGH); // Zet pin 11 aan
    }
    
    delay(200); // Kleine vertraging
  } 
  // Controleer of beide lampjes uit staan
  else if (digitalRead(11) == LOW && digitalRead(5) == LOW) {
    digitalWrite(11, HIGH); // Zet pin 11 aan
    delay(200); // Kleine vertraging
  }
}
