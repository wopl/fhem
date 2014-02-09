
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_industrial_dual_0_20ma.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	IndustrialDual020mA dual020;
	industrial_dual_0_20ma_create(&dual020, UID, &ipcon);

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Get current current from sensor 1 (unit is nA)
	int32_t current;
	if(industrial_dual_0_20ma_get_current(&dual020, 1, &current) < 0) {
		fprintf(stderr, "Could not get value, probably timeout\n");
		exit(1);
	}

	printf("Current: %f mA\n", current/(1000.0*1000.0));

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
