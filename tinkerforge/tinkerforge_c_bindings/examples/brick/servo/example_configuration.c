
#include <stdio.h>

#include "ip_connection.h"
#include "brick_servo.h"

#define HOST "localhost"
#define PORT 4223
#define UID "aySDPqVAkmw" // Change to your UID

int main() {
	// Create IP connection
	IPConnection ipcon;
	ipcon_create(&ipcon);

	// Create device object
	Servo servo;
	servo_create(&servo, UID, &ipcon); 

	// Connect to brickd
	if(ipcon_connect(&ipcon, HOST, PORT) < 0) {
		fprintf(stderr, "Could not connect\n");
		exit(1);
	}
	// Don't use device before ipcon is connected

	// Configure two servos with voltage 5.5V
	// Servo 1: Connected to port 0, period of 19.5ms, pulse width of 1 to 2ms
	//          and operating angle -100 to 100°
	//
	// Servo 2: Connected to port 5, period of 20ms, pulse width of 0.95 
	//          to 1.95ms and operating angle -90 to 90°
	servo_set_output_voltage(&servo, 5500);

	servo_set_degree(&servo, 0, -10000, 10000);
	servo_set_pulse_width(&servo, 0, 1000, 2000);
	servo_set_period(&servo, 0, 19500);
	servo_set_acceleration(&servo, 0, 1000); // Slow acceleration
	servo_set_velocity(&servo, 0, 0xFFFF); // Full speed

	servo_set_degree(&servo, 5, -9000, 9000);
	servo_set_pulse_width(&servo, 5, 950, 1950);
	servo_set_period(&servo, 5, 20000);
	servo_set_acceleration(&servo, 5, 0xFFFF); // Full acceleration
	servo_set_velocity(&servo, 5, 0xFFFF); // Full speed

	servo_set_position(&servo, 0, 10000); // Set to most right position
	servo_enable(&servo, 0);

	servo_set_position(&servo, 5, -9000); // Set to most left position
	servo_enable(&servo, 5);

	printf("Press key to exit\n");
	getchar();
	ipcon_destroy(&ipcon); // Calls ipcon_disconnect internally
}
