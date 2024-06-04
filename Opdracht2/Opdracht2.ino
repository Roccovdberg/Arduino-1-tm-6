// C++ code
//
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop()
{
  //Loop van links naar rechts
  digitalWrite(13, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  
  digitalWrite(12, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  
  digitalWrite(11, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(13, LOW);
  
  digitalWrite(10, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(12, LOW);
  
  digitalWrite(9, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(11, LOW);
  
  digitalWrite(8, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(10, LOW);
  
  digitalWrite(7, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(9, LOW);
  
  digitalWrite(6, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(8, LOW);
  
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(7, LOW);
  
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(6, LOW);
  delay(100); // Wait for 100 millisecond(s)

  
  
  //Loop van rechts naar links
  
  digitalWrite(6, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  
  digitalWrite(7, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  
  digitalWrite(8, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(6, LOW);
  
  digitalWrite(9, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(7, LOW);
  
  digitalWrite(10, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(8, LOW);
  
  digitalWrite(11, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(9, LOW);
  
  digitalWrite(12, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(10, LOW);
  
  digitalWrite(13, HIGH);
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(11, LOW);
  
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(12, LOW);
  
  delay(100); // Wait for 100 millisecond(s)
  digitalWrite(13, LOW);
  delay(100); // Wait for 100 millisecond(s)
  
  
}