
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_temperature_ir.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abcde" // Change to your UID

// Callback for object temperature greater than 100 °C
// (parameter has unit °C/10)
void cb_reached(uint16_t temperature, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("The surface has a temperature of %f °C\n", temperature/10.0);
	printf("The water is boiling!\n");
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

	// Set emissivity to 0.98 (emissivity of water)
	temperature_ir_set_emissivity(&tir, (int)0xFFFF*0.98);

	// Get threshold callbacks with a debounce time of 10 seconds (10000ms)
	temperature_ir_set_debounce_period(&tir, 10000);

	// Register threshold reached callback to function cb_reached
	temperature_ir_register_callback(&tir,
	                                 TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED,
	                                 (void *)cb_reached,
	                                 NULL);

	// Configure threshold for "greater than 100 °C" (unit is °C/10)
	temperature_ir_set_object_temperature_callback_threshold(&tir,
	                                                         '>',
	                                                         100*10,
	                                                         0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
