/*
 Name: Blinkenlights
 Author: Lukas Epple, 24th Decembre 2013
 Description: Blinking LED ftw
*/

const int LED = 2;

void setup() {
   pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
}
