int Matrix[] = { 2,3,5 , 6,7,8,0 };

void setup()
{
for(int i = 0; Matrix[i] != 0; i++){
	pinMode(Matrix[i], OUTPUT);
}
}

void onoff(int pina,int pinb){
	digitalWrite(pina,HIGH);
	digitalWrite(pinb, HIGH);
	delay(1000);
	digitalWrite(pina, LOW);
	digitalWrite(pinb, LOW);
}
void loop()
{
	onoff(2,6);
	onoff(3,7);
	onoff(5,8);
}
