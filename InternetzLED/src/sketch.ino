/*
LED via Internetz
by Lukas Epple
based on exampleEthernet
inpired by <https://github.com/sodaflo/LEDperInternet/blob/master/Arduino/LEDperInternet/LEDperInternet.ino>
*/

#include <Ethernet.h>

const int LED = 2;


byte mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0xBC, 0xA8 };
//byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

char server[] = "lukasepple.de";

IPAddress ip(192,168,0,42); // static IP if DHCP fails

EthernetClient client; // intialize Ethernetclient


void connectToServer(){
	if (client.connect(server, 80)) { // connect!
		client.println("GET /LED/status HTTP/1.1");
		client.println("Host: lukasepple.de");
		client.println("Connection: close");
		client.println();
	}else{
		Serial.println("connection failed");
	}
}


void setup()
{
	pinMode(LED, OUTPUT);
	Serial.begin(9600); // For Debugging info
	if (Ethernet.begin(mac) == 0) {
		Serial.println("Failed to configure Ethernet using DHCP");
		
		Ethernet.begin(mac, ip); // try with static IP
	}
	delay(1000); // Let's give him some time
	Serial.println("Now starting loop of connections");

}
	
void loop()
{
	connectToServer();
	if(client.connected()){
		Serial.println("connected");
		if(client.available()){
			char c;
			while((c = client.read())!=124){
       				Serial.print(c);
      			}
			c = client.read();
			Serial.print(c);
			Serial.println();
			switch(c){
				case 48:
					digitalWrite(LED, LOW);
					Serial.println("turned off");
					break;
				case 49:
					digitalWrite(LED, HIGH);
					Serial.println("turned on");
					break;
			}
			client.stop();
			delay(5);
		}
	}else{
		Serial.println("Not connected!");
	}
}
