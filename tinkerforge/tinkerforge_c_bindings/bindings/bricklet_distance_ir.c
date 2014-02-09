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

#include "bricklet_distance_ir.h"

#include <string.h>



typedef void (*DistanceCallbackFunction)(uint16_t, void *);

typedef void (*AnalogValueCallbackFunction)(uint16_t, void *);

typedef void (*DistanceReachedCallbackFunction)(uint16_t, void *);

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
} ATTRIBUTE_PACKED GetDistance_;

typedef struct {
	PacketHeader header;
	uint16_t distance;
} ATTRIBUTE_PACKED GetDistanceResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValue_;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED GetAnalogValueResponse_;

typedef struct {
	PacketHeader header;
	uint8_t position;
	uint16_t distance;
} ATTRIBUTE_PACKED SetSamplingPoint_;

typedef struct {
	PacketHeader header;
	uint8_t position;
} ATTRIBUTE_PACKED GetSamplingPoint_;

typedef struct {
	PacketHeader header;
	uint16_t distance;
} ATTRIBUTE_PACKED GetSamplingPointResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetDistanceCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDistanceCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetDistanceCallbackPeriodResponse_;

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
} ATTRIBUTE_PACKED SetDistanceCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDistanceCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetDistanceCallbackThresholdResponse_;

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
	uint16_t distance;
} ATTRIBUTE_PACKED DistanceCallback_;

typedef struct {
	PacketHeader header;
	uint16_t value;
} ATTRIBUTE_PACKED AnalogValueCallback_;

typedef struct {
	PacketHeader header;
	uint16_t distance;
} ATTRIBUTE_PACKED DistanceReachedCallback_;

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

static void distance_ir_callback_wrapper_distance(DistanceIR *distance_ir, Packet *packet) {
	DistanceCallbackFunction callback_function = (DistanceCallbackFunction)distance_ir->registered_callbacks[DISTANCE_IR_CALLBACK_DISTANCE];
	void *user_data = distance_ir->registered_callback_user_data[DISTANCE_IR_CALLBACK_DISTANCE];
	DistanceCallback_ *callback = (DistanceCallback_ *)packet;

	callback->distance = leconvert_uint16_from(callback->distance);

	if (callback_function != NULL) {
		callback_function(callback->distance, user_data);
	}
}

static void distance_ir_callback_wrapper_analog_value(DistanceIR *distance_ir, Packet *packet) {
	AnalogValueCallbackFunction callback_function = (AnalogValueCallbackFunction)distance_ir->registered_callbacks[DISTANCE_IR_CALLBACK_ANALOG_VALUE];
	void *user_data = distance_ir->registered_callback_user_data[DISTANCE_IR_CALLBACK_ANALOG_VALUE];
	AnalogValueCallback_ *callback = (AnalogValueCallback_ *)packet;

	callback->value = leconvert_uint16_from(callback->value);

	if (callback_function != NULL) {
		callback_function(callback->value, user_data);
	}
}

static void distance_ir_callback_wrapper_distance_reached(DistanceIR *distance_ir, Packet *packet) {
	DistanceReachedCallbackFunction callback_function = (DistanceReachedCallbackFunction)distance_ir->registered_callbacks[DISTANCE_IR_CALLBACK_DISTANCE_REACHED];
	void *user_data = distance_ir->registered_callback_user_data[DISTANCE_IR_CALLBACK_DISTANCE_REACHED];
	DistanceReachedCallback_ *callback = (DistanceReachedCallback_ *)packet;

	callback->distance = leconvert_uint16_from(callback->distance);

	if (callback_function != NULL) {
		callback_function(callback->distance, user_data);
	}
}

static void distance_ir_callback_wrapper_analog_value_reached(DistanceIR *distance_ir, Packet *packet) {
	AnalogValueReachedCallbackFunction callback_function = (AnalogValueReachedCallbackFunction)distance_ir->registered_callbacks[DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED];
	void *user_data = distance_ir->registered_callback_user_data[DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED];
	AnalogValueReachedCallback_ *callback = (AnalogValueReachedCallback_ *)packet;

	callback->value = leconvert_uint16_from(callback->value);

	if (callback_function != NULL) {
		callback_function(callback->value, user_data);
	}
}

void distance_ir_create(DistanceIR *distance_ir, const char *uid, IPConnection *ipcon) {
	device_create(distance_ir, uid, ipcon, 2, 0, 0);

	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_DISTANCE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_ANALOG_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_SET_SAMPLING_POINT] = DEVICE_RESPONSE_EXPECTED_FALSE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_SAMPLING_POINT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_SET_DISTANCE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_DISTANCE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_SET_DISTANCE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_DISTANCE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	distance_ir->response_expected[DISTANCE_IR_CALLBACK_DISTANCE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	distance_ir->response_expected[DISTANCE_IR_CALLBACK_ANALOG_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	distance_ir->response_expected[DISTANCE_IR_CALLBACK_DISTANCE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	distance_ir->response_expected[DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	distance_ir->response_expected[DISTANCE_IR_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	distance_ir->callback_wrappers[DISTANCE_IR_CALLBACK_DISTANCE] = (void *)distance_ir_callback_wrapper_distance;
	distance_ir->callback_wrappers[DISTANCE_IR_CALLBACK_ANALOG_VALUE] = (void *)distance_ir_callback_wrapper_analog_value;
	distance_ir->callback_wrappers[DISTANCE_IR_CALLBACK_DISTANCE_REACHED] = (void *)distance_ir_callback_wrapper_distance_reached;
	distance_ir->callback_wrappers[DISTANCE_IR_CALLBACK_ANALOG_VALUE_REACHED] = (void *)distance_ir_callback_wrapper_analog_value_reached;
}

void distance_ir_destroy(DistanceIR *distance_ir) {
	device_destroy(distance_ir);
}

int distance_ir_get_response_expected(DistanceIR *distance_ir, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(distance_ir, function_id, ret_response_expected);
}

int distance_ir_set_response_expected(DistanceIR *distance_ir, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(distance_ir, function_id, response_expected);
}

int distance_ir_set_response_expected_all(DistanceIR *distance_ir, bool response_expected) {
	return device_set_response_expected_all(distance_ir, response_expected);
}

void distance_ir_register_callback(DistanceIR *distance_ir, uint8_t id, void *callback, void *user_data) {
	device_register_callback(distance_ir, id, callback, user_data);
}

int distance_ir_get_api_version(DistanceIR *distance_ir, uint8_t ret_api_version[3]) {
	return device_get_api_version(distance_ir, ret_api_version);
}

int distance_ir_get_distance(DistanceIR *distance_ir, uint16_t *ret_distance) {
	GetDistance_ request;
	GetDistanceResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_DISTANCE, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_distance = leconvert_uint16_from(response.distance);



	return ret;
}

int distance_ir_get_analog_value(DistanceIR *distance_ir, uint16_t *ret_value) {
	GetAnalogValue_ request;
	GetAnalogValueResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_ANALOG_VALUE, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_value = leconvert_uint16_from(response.value);



	return ret;
}

int distance_ir_set_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t distance) {
	SetSamplingPoint_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_SET_SAMPLING_POINT, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}

	request.position = position;
	request.distance = leconvert_uint16_to(distance);

	ret = device_send_request(distance_ir, (Packet *)&request, NULL);


	return ret;
}

int distance_ir_get_sampling_point(DistanceIR *distance_ir, uint8_t position, uint16_t *ret_distance) {
	GetSamplingPoint_ request;
	GetSamplingPointResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_SAMPLING_POINT, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}

	request.position = position;

	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_distance = leconvert_uint16_from(response.distance);



	return ret;
}

int distance_ir_set_distance_callback_period(DistanceIR *distance_ir, uint32_t period) {
	SetDistanceCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_SET_DISTANCE_CALLBACK_PERIOD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(distance_ir, (Packet *)&request, NULL);


	return ret;
}

int distance_ir_get_distance_callback_period(DistanceIR *distance_ir, uint32_t *ret_period) {
	GetDistanceCallbackPeriod_ request;
	GetDistanceCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_DISTANCE_CALLBACK_PERIOD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int distance_ir_set_analog_value_callback_period(DistanceIR *distance_ir, uint32_t period) {
	SetAnalogValueCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(distance_ir, (Packet *)&request, NULL);


	return ret;
}

int distance_ir_get_analog_value_callback_period(DistanceIR *distance_ir, uint32_t *ret_period) {
	GetAnalogValueCallbackPeriod_ request;
	GetAnalogValueCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int distance_ir_set_distance_callback_threshold(DistanceIR *distance_ir, char option, int16_t min, int16_t max) {
	SetDistanceCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_SET_DISTANCE_CALLBACK_THRESHOLD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int16_to(min);
	request.max = leconvert_int16_to(max);

	ret = device_send_request(distance_ir, (Packet *)&request, NULL);


	return ret;
}

int distance_ir_get_distance_callback_threshold(DistanceIR *distance_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	GetDistanceCallbackThreshold_ request;
	GetDistanceCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_DISTANCE_CALLBACK_THRESHOLD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int16_from(response.min);
	*ret_max = leconvert_int16_from(response.max);



	return ret;
}

int distance_ir_set_analog_value_callback_threshold(DistanceIR *distance_ir, char option, uint16_t min, uint16_t max) {
	SetAnalogValueCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_uint16_to(min);
	request.max = leconvert_uint16_to(max);

	ret = device_send_request(distance_ir, (Packet *)&request, NULL);


	return ret;
}

int distance_ir_get_analog_value_callback_threshold(DistanceIR *distance_ir, char *ret_option, uint16_t *ret_min, uint16_t *ret_max) {
	GetAnalogValueCallbackThreshold_ request;
	GetAnalogValueCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_uint16_from(response.min);
	*ret_max = leconvert_uint16_from(response.max);



	return ret;
}

int distance_ir_set_debounce_period(DistanceIR *distance_ir, uint32_t debounce) {
	SetDebouncePeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_SET_DEBOUNCE_PERIOD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(distance_ir, (Packet *)&request, NULL);


	return ret;
}

int distance_ir_get_debounce_period(DistanceIR *distance_ir, uint32_t *ret_debounce) {
	GetDebouncePeriod_ request;
	GetDebouncePeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_DEBOUNCE_PERIOD, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_debounce = leconvert_uint32_from(response.debounce);



	return ret;
}

int distance_ir_get_identity(DistanceIR *distance_ir, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), DISTANCE_IR_FUNCTION_GET_IDENTITY, distance_ir->ipcon, distance_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(distance_ir, (Packet *)&request, (Packet *)&response);

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
