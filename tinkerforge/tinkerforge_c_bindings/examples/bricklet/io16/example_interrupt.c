
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_io16.h"

#define HOST "localhost"
#define PORT 4223
#define UID "XYZ" // Change to your UID

// Callback function for interrupts
void cb_interrupt(char port, uint8_t interrupt_mask, uint8_t value_mask, void *user_data) {
	(void)user_data; // avoid unused parameter warning

	printf("Interrupt on port: %c\n", port);
	printf("Interrupt by: %d\n", interrupt_mask);
	printf("Value: %d\n", value_mask);
}

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	IO16 io;
	io16_create(&io, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Register callback for interrupts
	io16_register_callback(&io,
	                       IO16_CALLBACK_INTERRUPT,
	                       (void *)cb_interrupt,
	                       NULL);

	// Enable interrupt on pin 2 of port a
	io16_set_port_interrupt(&io, 'a', 1 << 2);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
