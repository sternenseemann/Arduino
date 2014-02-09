const int LED = 2;
const int knopp = 7;
int state = 0;
int val = 0;

void toggleLED(){
  switch(state){
    case 0:
      digitalWrite(LED,HIGH);
      state = 1;
      break;
    case 1:
      digitalWrite(LED, LOW);
      state = 0;
      break;
  }
}
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(knopp, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(knopp);
  if(val == HIGH){
    digitalWrite(LED, HIGH);
  }
  Serial.println(val, DEC);
  delay(1);
}
