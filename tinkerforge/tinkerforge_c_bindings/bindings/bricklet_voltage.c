/* ***********************************************************
 * This file was automatically generated on 2013-07-18.      *
 *                                                           *
 * Bindings Version 2.0.8                                    *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/


#define IPCON_EXPOSE_INTERNALS

#include "bricklet_voltage.h"

#include <string.h>



typedef void (*VoltageCallbackFunction)(uint16_t, void *);

typedef void (*AnalogValueCallbackFunction)(uint16_t, void *);

typedef void (*VoltageReachedCallbackFunction)(uint16_t, void *);

typedef void (*AnalogValueReachedCallbackFunction)(uint16_t, void *);

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(push)
	#pragma pack(1)
	#define ATTRIBUTE_PACKED
#elif defined __GNUC__
	#define ATTRIBUTE_PACKED __attribute__((packed))
#else
	#error unknown compiler, do not know how to enable struct packing
#endif

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetVoltage_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetVoltageResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValue_;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED GetAnalogValueResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetVoltageCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetVoltageCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetVoltageCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetAnalogValueCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValueCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetAnalogValueCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED SetVoltageCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetVoltageCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetVoltageCallbackThresholdResponse_;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED SetAnalogValueCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValueCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED GetAnalogValueCallbackThresholdResponse_;

typedef struct {
	PacketHeader header;
	uint32_t debounce;
} ATTRIBUTE_PACKED SetDebouncePeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDebouncePeriod_;

typedef struct {
	PacketHeader header;
	uint32_t debounce;
} ATTRIBUTE_PACKED GetDebouncePeriodResponse_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED VoltageCallback_;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED AnalogValueCallback_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED VoltageReachedCallback_;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED AnalogValueReachedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetIdentity_;

typedef struct {
	PacketHeader header;
	char uid[8];
	char connected_uid[8];
	char position;
	uint8_t hardware_version[3];
	uint8_t firmware_version[3];
	uint16_t device_identifier;
} ATTRIBUTE_PACKED GetIdentityResponse_;

#if defined _MSC_VER || defined __BORLANDC__
	#pragma pack(pop)
#endif
#undef ATTRIBUTE_PACKED

static void voltage_callback_wrapper_voltage(Voltage *voltage, Packet *packet) {
	VoltageCallbackFunction callback_function = (VoltageCallbackFunction)voltage->registered_callbacks[VOLTAGE_CALLBACK_VOLTAGE];
	void *user_data = voltage->registered_callback_user_data[VOLTAGE_CALLBACK_VOLTAGE];
	VoltageCallback_ *callback = (VoltageCallback_ *)packet;

	callback->voltage = leconvert_uint16_from(callback->voltage);

	if (callback_function != NULL) {
		callback_function(callback->voltage, user_data);
	}
}

static void voltage_callback_wrapper_analog_value(Voltage *voltage, Packet *packet) {
	AnalogValueCallbackFunction callback_function = (AnalogValueCallbackFunction)voltage->registered_callbacks[VOLTAGE_CALLBACK_ANALOG_VALUE];
	void *user_data = voltage->registered_callback_user_data[VOLTAGE_CALLBACK_ANALOG_VALUE];
	AnalogValueCallback_ *callback = (AnalogValueCallback_ *)packet;

	callback->value = leconvert_uint16_from(callback->value);

	if (callback_function != NULL) {
		callback_function(callback->value, user_data);
	}
}

static void voltage_callback_wrapper_voltage_reached(Voltage *voltage, Packet *packet) {
	VoltageReachedCallbackFunction callback_function = (VoltageReachedCallbackFunction)voltage->registered_callbacks[VOLTAGE_CALLBACK_VOLTAGE_REACHED];
	void *user_data = voltage->registered_callback_user_data[VOLTAGE_CALLBACK_VOLTAGE_REACHED];
	VoltageReachedCallback_ *callback = (VoltageReachedCallback_ *)packet;

	callback->voltage = leconvert_uint16_from(callback->voltage);

	if (callback_function != NULL) {
		callback_function(callback->voltage, user_data);
	}
}

static void voltage_callback_wrapper_analog_value_reached(Voltage *voltage, Packet *packet) {
	AnalogValueReachedCallbackFunction callback_function = (AnalogValueReachedCallbackFunction)voltage->registered_callbacks[VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED];
	void *user_data = voltage->registered_callback_user_data[VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED];
	AnalogValueReachedCallback_ *callback = (AnalogValueReachedCallback_ *)packet;

	callback->value = leconvert_uint16_from(callback->value);

	if (callback_function != NULL) {
		callback_function(callback->value, user_data);
	}
}

void voltage_create(Voltage *voltage, const char *uid, IPConnection *ipcon) {
	device_create(voltage, uid, ipcon, 2, 0, 0);

	voltage->response_expected[VOLTAGE_FUNCTION_GET_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_GET_ANALOG_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_SET_VOLTAGE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_GET_VOLTAGE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_SET_VOLTAGE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_GET_VOLTAGE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage->response_expected[VOLTAGE_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage->response_expected[VOLTAGE_CALLBACK_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage->response_expected[VOLTAGE_CALLBACK_ANALOG_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage->response_expected[VOLTAGE_CALLBACK_VOLTAGE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage->response_expected[VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage->response_expected[VOLTAGE_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	voltage->callback_wrappers[VOLTAGE_CALLBACK_VOLTAGE] = (void *)voltage_callback_wrapper_voltage;
	voltage->callback_wrappers[VOLTAGE_CALLBACK_ANALOG_VALUE] = (void *)voltage_callback_wrapper_analog_value;
	voltage->callback_wrappers[VOLTAGE_CALLBACK_VOLTAGE_REACHED] = (void *)voltage_callback_wrapper_voltage_reached;
	voltage->callback_wrappers[VOLTAGE_CALLBACK_ANALOG_VALUE_REACHED] = (void *)voltage_callback_wrapper_analog_value_reached;
}

void voltage_destroy(Voltage *voltage) {
	device_destroy(voltage);
}

int voltage_get_response_expected(Voltage *voltage, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(voltage, function_id, ret_response_expected);
}

int voltage_set_response_expected(Voltage *voltage, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(voltage, function_id, response_expected);
}

int voltage_set_response_expected_all(Voltage *voltage, bool response_expected) {
	return device_set_response_expected_all(voltage, response_expected);
}

void voltage_register_callback(Voltage *voltage, uint8_t id, void *callback, void *user_data) {
	device_register_callback(voltage, id, callback, user_data);
}

int voltage_get_api_version(Voltage *voltage, uint8_t ret_api_version[3]) {
	return device_get_api_version(voltage, ret_api_version);
}

int voltage_get_voltage(Voltage *voltage, uint16_t *ret_voltage) {
	GetVoltage_ request;
	GetVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_VOLTAGE, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int voltage_get_analog_value(Voltage *voltage, uint16_t *ret_value) {
	GetAnalogValue_ request;
	GetAnalogValueResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_ANALOG_VALUE, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_value = leconvert_uint16_from(response.value);



	return ret;
}

int voltage_set_voltage_callback_period(Voltage *voltage, uint32_t period) {
	SetVoltageCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_SET_VOLTAGE_CALLBACK_PERIOD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(voltage, (Packet *)&request, NULL);


	return ret;
}

int voltage_get_voltage_callback_period(Voltage *voltage, uint32_t *ret_period) {
	GetVoltageCallbackPeriod_ request;
	GetVoltageCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_VOLTAGE_CALLBACK_PERIOD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int voltage_set_analog_value_callback_period(Voltage *voltage, uint32_t period) {
	SetAnalogValueCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(voltage, (Packet *)&request, NULL);


	return ret;
}

int voltage_get_analog_value_callback_period(Voltage *voltage, uint32_t *ret_period) {
	GetAnalogValueCallbackPeriod_ request;
	GetAnalogValueCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int voltage_set_voltage_callback_threshold(Voltage *voltage, char option, int16_t min, int16_t max) {
	SetVoltageCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_SET_VOLTAGE_CALLBACK_THRESHOLD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int16_to(min);
	request.max = leconvert_int16_to(max);

	ret = device_send_request(voltage, (Packet *)&request, NULL);


	return ret;
}

int voltage_get_voltage_callback_threshold(Voltage *voltage, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	GetVoltageCallbackThreshold_ request;
	GetVoltageCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_VOLTAGE_CALLBACK_THRESHOLD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int16_from(response.min);
	*ret_max = leconvert_int16_from(response.max);



	return ret;
}

int voltage_set_analog_value_callback_threshold(Voltage *voltage, char option, uint16_t min, uint16_t max) {
	SetAnalogValueCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_uint16_to(min);
	request.max = leconvert_uint16_to(max);

	ret = device_send_request(voltage, (Packet *)&request, NULL);


	return ret;
}

int voltage_get_analog_value_callback_threshold(Voltage *voltage, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	GetAnalogValueCallbackThreshold_ request;
	GetAnalogValueCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_uint16_from(response.min);
	*ret_max = leconvert_uint16_from(response.max);



	return ret;
}

int voltage_set_debounce_period(Voltage *voltage, uint32_t debounce) {
	SetDebouncePeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_SET_DEBOUNCE_PERIOD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(voltage, (Packet *)&request, NULL);


	return ret;
}

int voltage_get_debounce_period(Voltage *voltage, uint32_t *ret_debounce) {
	GetDebouncePeriod_ request;
	GetDebouncePeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_DEBOUNCE_PERIOD, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_debounce = leconvert_uint32_from(response.debounce);



	return ret;
}

int voltage_get_identity(Voltage *voltage, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_FUNCTION_GET_IDENTITY, voltage->ipcon, voltage);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	strncpy(ret_uid, response.uid, 8);
	strncpy(ret_connected_uid, response.connected_uid, 8);
	*ret_position = response.position;
	memcpy(ret_hardware_version, response.hardware_version, 3 * sizeof(uint8_t));
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	*ret_device_identifier = leconvert_uint16_from(response.device_identifier);



	return ret;
}
