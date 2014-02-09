
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_temperature.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback function for temperature callback (parameter has unit °C/100)
void cb_temperature(int16_t temperature, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Temperature: %f °C.\n", temperature/100.0);
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

	// Set Period for temperature callback to 1s (1000ms)
	// Note: The callback is only called every second if the 
	//       temperature has changed since the last call!
	temperature_set_temperature_callback_period(&t, 1000);

	// Register temperature callback to function cb_temperature
	temperature_register_callback(&t,
	                              TEMPERATURE_CALLBACK_TEMPERATURE, 
	                              (void *)cb_temperature,
	                              NULL);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
