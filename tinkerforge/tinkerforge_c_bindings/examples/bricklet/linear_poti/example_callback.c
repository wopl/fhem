
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_linear_poti.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abc" // Change to your UID

// Callback function for position callback (parameter has range 0-100)
void cb_position(uint16_t position, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Position: %d\n", position);
}

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

	// Set Period for position callback to 0.05s (50ms)
	// Note: The position callback is only called every 50ms if the 
	//       position has changed since the last call!
	linear_poti_set_position_callback_period(&poti, 50);

	// Register position callback to function cb_position
	linear_poti_register_callback(&poti,
	                              LINEAR_POTI_CALLBACK_POSITION,
	                              (void *)cb_position,
	                              NULL);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
