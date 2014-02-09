
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_industrial_dual_0_20ma.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback for current greater than 10mA
void cb_reached(uint8_t sensor, int32_t current, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Current (sensor %d) is greater than 10mA: %f\n", sensor, current/(1000.0*1000.0));
}

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

	// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
	industrial_dual_0_20ma_set_debounce_period(&dual020, 10000);

	// Register threshold reached callback to function cb_reached
	industrial_dual_0_20ma_register_callback(&dual020,
	                                          INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT_REACHED,
	                                          (void *)cb_reached,
	                                          NULL);

	// Configure threshold (sensor 1) for "greater than 10mA" (unit is nA)
	industrial_dual_0_20ma_set_current_callback_threshold(&dual020, 1, '>', 10*1000*1000, 0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
