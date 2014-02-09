
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_industrial_digital_in_4.h"

#define HOST "localhost"
#define PORT 4223
#define UID "xyz" // Change to your UID

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	IndustrialDigitalIn4 idi4;
	industrial_digital_in_4_create(&idi4, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Read out values as bitmask
	uint16_t value;
	industrial_digital_in_4_get_value(&idi4, &value);
	printf("Value: %d\n", value);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
