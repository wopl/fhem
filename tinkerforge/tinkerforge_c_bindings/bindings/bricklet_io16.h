/* ***********************************************************
 * This file was automatically generated on 2013-07-18.      *
 *                                                           *
 * Bindings Version 2.0.8                                    *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

#ifndef BRICKLET_IO16_H
#define BRICKLET_IO16_H

#include "ip_connection.h"

/**
 * \defgroup BrickletIO16 IO16 Bricklet
 */

/**
 * \ingroup BrickletIO16
 *
 * Device for controlling up to 16 general purpose input/output pins
 */
typedef Device IO16;

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_SET_PORT 1

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_GET_PORT 2

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_SET_PORT_CONFIGURATION 3

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_GET_PORT_CONFIGURATION 4

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_SET_DEBOUNCE_PERIOD 5

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_GET_DEBOUNCE_PERIOD 6

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_SET_PORT_INTERRUPT 7

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_GET_PORT_INTERRUPT 8

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_SET_PORT_MONOFLOP 10

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_GET_PORT_MONOFLOP 11

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_SET_SELECTED_VALUES 13

/**
 * \ingroup BrickletIO16
 */
#define IO16_FUNCTION_GET_IDENTITY 255

/**
 * \ingroup BrickletIO16
 *
 * Signature: \code void callback(char port, uint8_t interrupt_mask, uint8_t value_mask, void *user_data) \endcode
 * 
 * This callback is triggered whenever a change of the voltage level is detected
 * on pins where the interrupt was activated with {@link io16_set_port_interrupt}.
 * 
 * The values are the port, a bitmask that specifies which interrupts occurred
 * and the current value bitmask of the port.
 * 
 * For example:
 * 
 * * ("a", 1, 1) means that on port a an interrupt on pin 0 occurred and
 *   currently pin 0 is high and pins 1-7 are low.
 * * ("b", 128, 254) means that on port b interrupts on pins 0 and 7
 *   occurred and currently pin 0 is low and pins 1-7 are high.
 */
#define IO16_CALLBACK_INTERRUPT 9

/**
 * \ingroup BrickletIO16
 *
 * Signature: \code void callback(char port, uint8_t selection_mask, uint8_t value_mask, void *user_data) \endcode
 * 
 * This callback is triggered whenever a monoflop timer reaches 0. The
 * parameters contain the port, the involved pins and the current value of
 * the pins (the value after the monoflop).
 * 
 * .. versionadded:: 1.1.2~(Plugin)
 */
#define IO16_CALLBACK_MONOFLOP_DONE 12


/**
 * \ingroup BrickletIO16
 */
#define IO16_DIRECTION_IN 'i'

/**
 * \ingroup BrickletIO16
 */
#define IO16_DIRECTION_OUT 'o'

/**
 * \ingroup BrickletIO16
 *
 * This constant is used to identify a IO16 Bricklet.
 *
 * The {@link io16_get_identity} function and the
 * {@link IPCON_CALLBACK_ENUMERATE} callback of the IP Connection have a
 * \c device_identifier parameter to specify the Brick's or Bricklet's type.
 */
#define IO16_DEVICE_IDENTIFIER 28

/**
 * \ingroup BrickletIO16
 *
 * Creates the device object \c io16 with the unique device ID \c uid and adds
 * it to the IPConnection \c ipcon.
 */
void io16_create(IO16 *io16, const char *uid, IPConnection *ipcon);

/**
 * \ingroup BrickletIO16
 *
 * Removes the device object \c io16 from its IPConnection and destroys it.
 * The device object cannot be used anymore afterwards.
 */
void io16_destroy(IO16 *io16);

/**
 * \ingroup BrickletIO16
 *
 * Returns the response expected flag for the function specified by the
 * \c function_id parameter. It is *true* if the function is expected to
 * send a response, *false* otherwise.
 *
 * For getter functions this is enabled by default and cannot be disabled,
 * because those functions will always send a response. For callback
 * configuration functions it is enabled by default too, but can be disabled
 * via the io16_set_response_expected function. For setter functions it is
 * disabled by default and can be enabled.
 *
 * Enabling the response expected flag for a setter function allows to
 * detect timeouts and other error conditions calls of this setter as well.
 * The device will then send a response for this purpose. If this flag is
 * disabled for a setter function then no response is send and errors are
 * silently ignored, because they cannot be detected.
 */
int io16_get_response_expected(IO16 *io16, uint8_t function_id, bool *ret_response_expected);

/**
 * \ingroup BrickletIO16
 *
 * Changes the response expected flag of the function specified by the
 * \c function_id parameter. This flag can only be changed for setter
 * (default value: *false*) and callback configuration functions
 * (default value: *true*). For getter functions it is always enabled and
 * callbacks it is always disabled.
 *
 * Enabling the response expected flag for a setter function allows to detect
 * timeouts and other error conditions calls of this setter as well. The device
 * will then send a response for this purpose. If this flag is disabled for a
 * setter function then no response is send and errors are silently ignored,
 * because they cannot be detected.
 */
int io16_set_response_expected(IO16 *io16, uint8_t function_id, bool response_expected);

/**
 * \ingroup BrickletIO16
 *
 * Changes the response expected flag for all setter and callback configuration
 * functions of this device at once.
 */
int io16_set_response_expected_all(IO16 *io16, bool response_expected);

/**
 * \ingroup BrickletIO16
 *
 * Registers a callback with ID \c id to the function \c callback. The
 * \c user_data will be given as a parameter of the callback.
 */
void io16_register_callback(IO16 *io16, uint8_t id, void *callback, void *user_data);

/**
 * \ingroup BrickletIO16
 *
 * Returns the API version (major, minor, release) of the bindings for this
 * device.
 */
int io16_get_api_version(IO16 *io16, uint8_t ret_api_version[3]);

/**
 * \ingroup BrickletIO16
 *
 * Sets the output value (high or low) for a port ("a" or "b") with a bitmask.
 * The bitmask is 8 bit long, *true* refers to high and *false* refers to low.
 * 
 * For example: The value 0b00001111 will turn the pins 0-3 high and the
 * pins 4-7 low for the specified port.
 * 
 * \note
 *  This function does nothing for pins that are configured as input.
 *  Pull-up resistors can be switched on with {@link io16_set_port_configuration}.
 */
int io16_set_port(IO16 *io16, char port, uint8_t value_mask);

/**
 * \ingroup BrickletIO16
 *
 * Returns a bitmask of the values that are currently measured on the
 * specified port. This function works if the pin is configured to input
 * as well as if it is configured to output.
 */
int io16_get_port(IO16 *io16, char port, uint8_t *ret_value_mask);

/**
 * \ingroup BrickletIO16
 *
 * Configures the value and direction of a specified port. Possible directions
 * are "i" and "o" for input and output.
 * 
 * If the direction is configured as output, the value is either high or low
 * (set as *true* or *false*).
 * 
 * If the direction is configured as input, the value is either pull-up or
 * default (set as *true* or *false*).
 * 
 * For example:
 * 
 * * ("a", 0xFF, 'i', true) will set all pins of port a as input pull-up.
 * * ("a", 128, 'i', false) will set pin 7 of port a as input default (floating if nothing is connected).
 * * ("b", 3, 'o', false) will set pins 0 and 1 of port b as output low.
 * * ("b", 4, 'o', true) will set pin 2 of port b as output high.
 */
int io16_set_port_configuration(IO16 *io16, char port, uint8_t selection_mask, char direction, bool value);

/**
 * \ingroup BrickletIO16
 *
 * Returns a direction bitmask and a value bitmask for the specified port.
 * 
 * For example: A return value of 0b00001111 and 0b00110011 for
 * direction and value means that:
 * 
 * * pins 0 and 1 are configured as input pull-up,
 * * pins 2 and 3 are configured as input default,
 * * pins 4 and 5 are configured as output high
 * * and pins 6 and 7 are configured as output low.
 */
int io16_get_port_configuration(IO16 *io16, char port, uint8_t *ret_direction_mask, uint8_t *ret_value_mask);

/**
 * \ingroup BrickletIO16
 *
 * Sets the debounce period of the {@link IO16_CALLBACK_INTERRUPT} callback in ms.
 * 
 * For example: If you set this value to 100, you will get the interrupt
 * maximal every 100ms. This is necessary if something that bounces is
 * connected to the IO-16 Bricklet, such as a button.
 * 
 * The default value is 100.
 */
int io16_set_debounce_period(IO16 *io16, uint32_t debounce);

/**
 * \ingroup BrickletIO16
 *
 * Returns the debounce period as set by {@link io16_set_debounce_period}.
 */
int io16_get_debounce_period(IO16 *io16, uint32_t *ret_debounce);

/**
 * \ingroup BrickletIO16
 *
 * Sets the pins on which an interrupt is activated with a bitmask.
 * Interrupts are triggered on changes of the voltage level of the pin,
 * i.e. changes from high to low and low to high.
 * 
 * For example: ('a', 129) will enable the interrupt for pins 0 and 7 of
 * port a.
 * 
 * The interrupt is delivered with the callback {@link IO16_CALLBACK_INTERRUPT}.
 */
int io16_set_port_interrupt(IO16 *io16, char port, uint8_t interrupt_mask);

/**
 * \ingroup BrickletIO16
 *
 * Returns the interrupt bitmask for the specified port as set by
 * {@link io16_set_port_interrupt}.
 */
int io16_get_port_interrupt(IO16 *io16, char port, uint8_t *ret_interrupt_mask);

/**
 * \ingroup BrickletIO16
 *
 * Configures a monoflop of the pins specified by the second parameter as 8 bit
 * long bitmask. The specified pins must be configured for output. Non-output
 * pins will be ignored.
 * 
 * The third parameter is a bitmask with the desired value of the specified
 * output pins (*true* means high and *false* means low).
 * 
 * The forth parameter indicates the time (in ms) that the pins should hold
 * the value.
 * 
 * If this function is called with the parameters ('a', (1 << 0) | (1 << 3), (1 << 0), 1500):
 * Pin 0 will get high and pin 3 will get low on port 'a'. In 1.5s pin 0 will get
 * low and pin 3 will get high again.
 * 
 * A monoflop can be used as a fail-safe mechanism. For example: Lets assume you
 * have a RS485 bus and an IO-16 Bricklet connected to one of the slave
 * stacks. You can now call this function every second, with a time parameter
 * of two seconds and pin 0 set to high. Pin 0 will be high all the time. If now
 * the RS485 connection is lost, then pin 0 will get low in at most two seconds.
 * 
 * .. versionadded:: 1.1.2~(Plugin)
 */
int io16_set_port_monoflop(IO16 *io16, char port, uint8_t selection_mask, uint8_t value_mask, uint32_t time);

/**
 * \ingroup BrickletIO16
 *
 * Returns (for the given pin) the current value and the time as set by
 * {@link io16_set_port_monoflop} as well as the remaining time until the value flips.
 * 
 * If the timer is not running currently, the remaining time will be returned
 * as 0.
 * 
 * .. versionadded:: 1.1.2~(Plugin)
 */
int io16_get_port_monoflop(IO16 *io16, char port, uint8_t pin, uint8_t *ret_value, uint32_t *ret_time, uint32_t *ret_time_remaining);

/**
 * \ingroup BrickletIO16
 *
 * Sets the output value (high or low) for a port ("a" or "b" with a bitmask, 
 * according to the selection mask. The bitmask is 8 bit long, *true* refers 
 * to high and *false* refers to low.
 * 
 * For example: The values 0b11000000, 0b10000000 will turn pin 7 high and
 * pin 6 low, pins 0-6 will remain untouched.
 * 
 * \note
 *  This function does nothing for pins that are configured as input.
 *  Pull-up resistors can be switched on with :func:`SetConfiguration`.
 * 
 * .. versionadded:: 2.0.0~(Plugin)
 */
int io16_set_selected_values(IO16 *io16, char port, uint8_t selection_mask, uint8_t value_mask);

/**
 * \ingroup BrickletIO16
 *
 * Returns the UID, the UID where the Bricklet is connected to, 
 * the position, the hardware and firmware version as well as the
 * device identifier.
 * 
 * The position can be 'a', 'b', 'c' or 'd'.
 * 
 * The device identifiers can be found :ref:`here <device_identifier>`.
 * 
 * .. versionadded:: 2.0.0~(Plugin)
 */
int io16_get_identity(IO16 *io16, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier);

#endif
