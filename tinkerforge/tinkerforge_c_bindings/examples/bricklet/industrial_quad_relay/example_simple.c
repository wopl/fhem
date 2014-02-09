
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_industrial_quad_relay.h"

#define HOST "localhost"
#define PORT 4223
#define UID "xyz" // Change to your UID

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	IndustrialQuadRelay iqr;
	industrial_quad_relay_create(&iqr, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Turn relay 0, 3 on and relay 1, 2 off.
	industrial_quad_relay_set_value(&iqr, 1 | 8);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
