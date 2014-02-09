
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_voltage.h"

#define HOST "localhost"
#define PORT 4223
#define UID "ABC" // Change to your UID

// Callback function for voltage callback (parameter has unit mV)
void cb_voltage(uint16_t voltage, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Voltage: %f V\n", voltage/1000.0);
}

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Voltage v;
	voltage_create(&v, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Set Period for voltage callback to 1s (1000ms)
	// Note: The callback is only called every second if the 
	//       voltage has changed since the last call!
	voltage_set_voltage_callback_period(&v, 1000);

	// Register voltage callback to function cb_voltage
	voltage_register_callback(&v,
	                          VOLTAGE_CALLBACK_VOLTAGE,
	                          (void *)cb_voltage,
	                          NULL);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
