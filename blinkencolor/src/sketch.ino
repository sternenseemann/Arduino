int LED[] = { 2,3,5 };
void setup()
{
	for(int i=0; i <= 2; i++){
		pinMode(LED[i], OUTPUT);
	}
}

void loop()
{
	for(int i=0; i <= 2; i++){
		digitalWrite(LED[i], HIGH);
		delay(1000);
		digitalWrite(LED[i], LOW);
	}
}
