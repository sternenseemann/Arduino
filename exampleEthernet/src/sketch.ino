/*
Example Ethernet Project
by Lukas Epple (sternenseemann)
based on http://arduino.cc/en/Tutorial/WebClient
*/

#include <Ethernet.h>

//char mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0xBC, 0xA8 };
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

char server[] = "lukasepple.de";

IPAddress ip(192,168,0,42); // static IP if DHCP fails

EthernetClient client; // intialize Ethernetclient



void setup()
{
	Serial.begin(9600); // For Debugging info
	if (Ethernet.begin(mac) == 0) {
		Serial.println("Failed to configure Ethernet using DHCP");
		
		Ethernet.begin(mac, ip); // try with static IP
	}
	delay(1000); // Let's give him some time
	Serial.println("connecting...");
	
	if (client.connect(server, 80)) { // connect!
		Serial.println("connected");;
		client.println("GET / HTTP/1.1");
		client.println("Host: lukasepple.de");
		client.println("Connection: close");
		client.println();
	}else{
		Serial.println("connection failed");
		exit(1);
	}
}

void loop()
{
	// print every incoming byte
	if (client.available()) {
		char c = client.read();
		Serial.print(c);
	}
	
	// are we disconnected?
	if (!client.connected()) {
		Serial.println();
		Serial.println("disconnecting.");
		client.stop();
		// do nothing forevermore:
		while(true);
  }
}

