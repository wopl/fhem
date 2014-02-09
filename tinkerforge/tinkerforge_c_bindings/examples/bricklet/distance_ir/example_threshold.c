
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_distance_ir.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback for distance smaller than 20cm
void cb_reached(uint16_t distance, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Distance is smaller than 20cm: %f cm\n", distance/10.0);
}

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	DistanceIR dist;
	distance_ir_create(&dist, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Get threshold callbacks with a debounce time of 1 second (1000ms)
	distance_ir_set_debounce_period(&dist, 1000);

	// Register threshold reached callback to function cb_reached
	distance_ir_register_callback(&dist,
	                              DISTANCE_IR_CALLBACK_DISTANCE_REACHED,
	                              (void *)cb_reached,
	                              NULL);

	// Configure threshold for "smaller than 20cm" (unit is mm)
	distance_ir_set_distance_callback_threshold(&dist, '<', 200, 0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
