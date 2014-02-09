
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_distance_ir.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback function for distance callback (parameter has unit mm)
void cb_distance(uint16_t distance, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Distance: %f cm\n", distance/10.0);
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

	// Set Period for distance callback to 0.2s (200ms)
	// Note: The callback is only called every 200ms if the 
	//       distance has changed since the last call!
	distance_ir_set_distance_callback_period(&dist, 200);

	// Register distance callback to function cb_distance
	distance_ir_register_callback(&dist,
	                              DISTANCE_IR_CALLBACK_DISTANCE, 
	                              (void *)cb_distance,
	                              NULL);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
