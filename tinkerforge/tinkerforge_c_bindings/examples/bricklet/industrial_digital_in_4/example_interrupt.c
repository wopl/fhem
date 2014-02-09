
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_industrial_digital_in_4.h"

#define HOST "localhost"
#define PORT 4223
#define UID "xyz" // Change to your UID

// Callback function for interrupts
void cb_interrupt(uint8_t interrupt_mask, uint8_t value_mask, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Interrupt by: %d\n", interrupt_mask);
	printf("Value: %d\n", value_mask);
}

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	IndustrialDigitalIn4 idi4;
	industrial_digital_in_4_create(&idi4, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Register callback for interrupts
	industrial_digital_in_4_register_callback(&idi4,
	                                          INDUSTRIAL_DIGITAL_IN_4_CALLBACK_INTERRUPT,
	                                          (void *)cb_interrupt,
	                                          NULL);

	// Enable interrupt on pin 0
	industrial_digital_in_4_set_interrupt(&idi4, 1 << 0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
