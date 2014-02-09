
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_temperature.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback for temperature greater than 30 °C
void cb_reached(int16_t temperature, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("We have %f °C.\n", temperature/100.0);
	printf("It is too hot, we need air conditioning!\n");
}

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Temperature t;
	temperature_create(&t, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected
	//
	// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
	temperature_set_debounce_period(&t, 10000);

	// Register threshold reached callback to function cb_reached
	temperature_register_callback(&t,
	                              TEMPERATURE_CALLBACK_TEMPERATURE_REACHED,
	                              (void *)cb_reached,
	                              NULL);

	// Configure threshold for "greater than 30 °C" (unit is °C/100)
	temperature_set_temperature_callback_threshold(&t, '>', 30*100, 0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
