const int potPin = A5; // Potmeter
const int ledPins[] = {13, 12, 11, 10, 9, 8}; // Pinnen van de ledjes in een array
const int numLEDs = 6; // Aantal ledjes weergeven als numLeds

void setup() {
  for (int i = 0; i < numLEDs; i++) { // For Lus loopt tot i kleiner is dan het aantal ledjes
    pinMode(ledPins[i], OUTPUT); // Ledjes zijn OUTPUT
  }
}

void loop() {
  int potValue = analogRead(potPin); // Kijk op hoeveel graden de potmeter is(tussen 0 en 1023)
  
  // Bereken het aantal LED's dat moet worden ingeschakeld
  // Map berekend de hoeveelheid ledjes die aanmoet doormiddel van de graden van de potmeter en de hoeveelheid ledjes
  // Het resultaat wordt laten zien als numLedsToLight
  // NumLEDs zijn het aantal ledjes die maximaal aanstaan
  // De 2e 0 is het aantal ledjes dat minimaal aanstaan
  int numLedsToLight = map(potValue, 0, 1023, numLEDs, 0);
  
  // Zorg dat goede aantal ledjes aanstaan
  for (int i = 0; i < numLEDs; i++) {
    if (i < numLedsToLight) { // Als het aantal ledjes meer dan 0 is kijk dan welke ledjes aangezet moeten worden
      digitalWrite(ledPins[i], HIGH); // Zet ledje aan
    } else { // Anders zet het ledje uit
      digitalWrite(ledPins[i], LOW); // Zet ledje uit
    }
  }
  
  delay(100); // Kleine vertraging
}
