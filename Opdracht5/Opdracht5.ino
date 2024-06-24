// C++ code
//
void setup()
{
  pinMode(13, OUTPUT); //Verbinding identificeren
  pinMode(10, OUTPUT);
}

void loop()
{
  digitalWrite(10, HIGH); //Stroom aan
  delay(2000); // wacht 2000 milliseconds
  digitalWrite(10, LOW); //Stroom uit
  
    digitalWrite(13, HIGH);// Stroom aan
  delay(2000); // wacht 2000 milliseconds
  digitalWrite(13, LOW); //Stroom uit
}
