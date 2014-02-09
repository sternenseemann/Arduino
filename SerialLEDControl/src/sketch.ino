/*
 Name: LEDControl
 Author: Lukas Epple
 Description: Control LED using Serial Communication
*/

int incomingByte = 0;
const int LED = 2;

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop(){
if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial.read();

                /* debugging info
                Serial.print("got  ");
                Serial.println(incomingByte, DEC);*/
                switch(incomingByte){
                    case 48:
                        //Serial.print("turning off\n");
                        digitalWrite(LED, LOW);
                        Serial.println("0");
                        break;
                    case 49:
                        //Serial.print("turning on\n");
                        digitalWrite(LED, HIGH);
                        Serial.println("1");
                        break;
                    default:
                        //Serial.print("expecting 0 or 1\n");
                        break;
                        
                }
  }
  delay(1);
}
