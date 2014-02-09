
#include <stdio.h>

#include "ip_connection.h"
#include "bricklet_temperature_ir.h"

#define HOST "localhost"
#define PORT 4223
#define UID "abcde" // Change to your UID

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

	// Get current ambient and object temperatures (unit is °C/10)
	int16_t obj;
	int16_t amb;
	temperature_ir_get_object_temperature(&tir, &obj);
	temperature_ir_get_ambient_temperature(&tir, &amb);

	printf("Object Temperature: %f °C\n", obj/10.0);
	printf("Ambient Temperature: %f °C\n", amb/10.0);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
