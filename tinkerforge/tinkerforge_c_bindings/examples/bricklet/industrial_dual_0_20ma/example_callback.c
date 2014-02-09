
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_industrial_dual_0_20ma.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback function for current callback (parameter has unit mA)
void cb_current(uint8_t sensor, int32_t current, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Current (sensor %d): %f mA\n", sensor, current/(1000.0*1000.0));
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

	// Set Period for current callback for sensor 1 to 1s (1000ms)
	// Note: The callback is only called every second if the 
	//       current has changed since the last call!
	industrial_dual_0_20ma_set_current_callback_period(&dual020, 1, 1000);

	// Register current callback to function cb_current
	industrial_dual_0_20ma_register_callback(&dual020,
	                                         INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT,
	                                         (void *)cb_current,
	                                         NULL);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon);
}
