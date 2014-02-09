
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_humidity.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Humidity h;
	humidity_create(&h, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Get current humidity (unit is %RH/10)
	uint16_t humidity;
	if(humidity_get_humidity(&h, &humidity) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Relative Humidity: %f %%RH\n", humidity/10.0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
