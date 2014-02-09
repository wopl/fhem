
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_linear_poti.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abc" // Change to your UID

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	LinearPoti poti;
	linear_poti_create(&poti, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Get current position (value has range 0-100)
	uint16_t position;
	if(linear_poti_get_position(&poti, &position) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Position: %d\n", position);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
