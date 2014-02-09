
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_current25.h"

#define HOST "localhost"
#define PORT 4223
#define UID "ABCD" // Change to your UID

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Current25 c;
	current25_create(&c, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Get current current (unit is mA)
	int16_t current;
	if(current25_get_current(&c, &current) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Current: %f A\n", current/1000.0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
