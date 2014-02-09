
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_temperature_ir.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abcde" // Change to your UID

// Callback functions for object/ambient temperature callbacks
// (parameters have unit °C/10)
void cb_object(uint16_t temperature, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Object Temperature: %f °C.\n", temperature/10.0);
}

void cb_ambient(uint16_t temperature, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Ambient Temperature: %f °C.\n", temperature/10.0);
}

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	TemperatureIR tir;
	temperature_ir_create(&tir, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Set Period for temperature callbacks to 1s (1000ms)
	// Note: The callbacks are only called every second if the 
	//       value has changed since the last call!
	temperature_ir_set_object_temperature_callback_period(&tir, 1000);
	temperature_ir_set_ambient_temperature_callback_period(&tir, 1000);

	// Register object temperature callback to function cb_object
	temperature_ir_register_callback(&tir,
	                                 TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE, 
	                                 (void *)cb_object,
	                                 NULL);

	// Register ambient temperature callback to function cb_ambient
	temperature_ir_register_callback(&tir,
	                                 TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE, 
	                                 (void *)cb_ambient,
	                                 NULL);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
