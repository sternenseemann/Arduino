/*
LEDMatrix
Animating Code for a 6x2 LED Matrix
by Lukas Epple
*/

#define COUNT_OF( arr) (sizeof(arr)/sizeof(0[arr]))

#define UP_LEFT 2
#define UP_MIDDLE 3
#define UP_RIGHT 5

#define DOWN_LEFT 6
#define DOWN_MIDDLE 7
#define DOWN_RIGHT 8

int Matrix[] = { UP_LEFT, UP_MIDDLE,UP_RIGHT,DOWN_LEFT,DOWN_MIDDLE,DOWN_RIGHT };


int animation[][6] = { {UP_LEFT}, {UP_MIDDLE},{UP_RIGHT},{DOWN_RIGHT},{DOWN_MIDDLE},{DOWN_LEFT} };

void setup()
{
	for(int i = 0; i < COUNT_OF(Matrix); i++){
		pinMode(Matrix[i], OUTPUT);
	}
	Serial.begin(9600);
	Serial.println(COUNT_OF(Matrix), DEC);
}

void loop()
{
	for(int i = 0; i < COUNT_OF(animation); i++){
		for(int j = 0; j < COUNT_OF(animation[i]); j++){
			digitalWrite(animation[i][j], HIGH);
		}
		delay(400);
		for(int k = 0; k < COUNT_OF(animation[i]); k++){
			digitalWrite(animation[i][k], LOW);
		}
	}
}
