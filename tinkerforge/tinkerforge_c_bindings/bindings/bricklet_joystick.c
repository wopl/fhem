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

#include "bricklet_joystick.h"

#include <string.h>



typedef void (*PositionCallbackFunction)(int16_t, int16_t, void *);

typedef void (*AnalogValueCallbackFunction)(uint16_t, uint16_t, void *);

typedef void (*PositionReachedCallbackFunction)(int16_t, int16_t, void *);

typedef void (*AnalogValueReachedCallbackFunction)(uint16_t, uint16_t, void *);

typedef void (*PressedCallbackFunction)(void *);

typedef void (*ReleasedCallbackFunction)(void *);

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
} ATTRIBUTE_PACKED GetPosition_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
} ATTRIBUTE_PACKED GetPositionResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED IsPressed_;

typedef struct {
	PacketHeader header;
	bool pressed;
} ATTRIBUTE_PACKED IsPressedResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValue_;

typedef struct {
	PacketHeader header;
	uint16_t x;
	uint16_t y;
} ATTRIBUTE_PACKED GetAnalogValueResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Calibrate_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetPositionCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetPositionCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetPositionCallbackPeriodResponse_;

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
	int16_t min_x;
	int16_t max_x;
	int16_t min_y;
	int16_t max_y;
} ATTRIBUTE_PACKED SetPositionCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetPositionCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min_x;
	int16_t max_x;
	int16_t min_y;
	int16_t max_y;
} ATTRIBUTE_PACKED GetPositionCallbackThresholdResponse_;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min_x;
	uint16_t max_x;
	uint16_t min_y;
	uint16_t max_y;
} ATTRIBUTE_PACKED SetAnalogValueCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAnalogValueCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	uint16_t min_x;
	uint16_t max_x;
	uint16_t min_y;
	uint16_t max_y;
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
	int16_t x;
	int16_t y;
} ATTRIBUTE_PACKED PositionCallback_;

typedef struct {
	PacketHeader header;
	uint16_t x;
	uint16_t y;
} ATTRIBUTE_PACKED AnalogValueCallback_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
} ATTRIBUTE_PACKED PositionReachedCallback_;

typedef struct {
	PacketHeader header;
	uint16_t x;
	uint16_t y;
} ATTRIBUTE_PACKED AnalogValueReachedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED PressedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED ReleasedCallback_;

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

static void joystick_callback_wrapper_position(Joystick *joystick, Packet *packet) {
	PositionCallbackFunction callback_function = (PositionCallbackFunction)joystick->registered_callbacks[JOYSTICK_CALLBACK_POSITION];
	void *user_data = joystick->registered_callback_user_data[JOYSTICK_CALLBACK_POSITION];
	PositionCallback_ *callback = (PositionCallback_ *)packet;

	callback->x = leconvert_int16_from(callback->x);
	callback->y = leconvert_int16_from(callback->y);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, user_data);
	}
}

static void joystick_callback_wrapper_analog_value(Joystick *joystick, Packet *packet) {
	AnalogValueCallbackFunction callback_function = (AnalogValueCallbackFunction)joystick->registered_callbacks[JOYSTICK_CALLBACK_ANALOG_VALUE];
	void *user_data = joystick->registered_callback_user_data[JOYSTICK_CALLBACK_ANALOG_VALUE];
	AnalogValueCallback_ *callback = (AnalogValueCallback_ *)packet;

	callback->x = leconvert_uint16_from(callback->x);
	callback->y = leconvert_uint16_from(callback->y);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, user_data);
	}
}

static void joystick_callback_wrapper_position_reached(Joystick *joystick, Packet *packet) {
	PositionReachedCallbackFunction callback_function = (PositionReachedCallbackFunction)joystick->registered_callbacks[JOYSTICK_CALLBACK_POSITION_REACHED];
	void *user_data = joystick->registered_callback_user_data[JOYSTICK_CALLBACK_POSITION_REACHED];
	PositionReachedCallback_ *callback = (PositionReachedCallback_ *)packet;

	callback->x = leconvert_int16_from(callback->x);
	callback->y = leconvert_int16_from(callback->y);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, user_data);
	}
}

static void joystick_callback_wrapper_analog_value_reached(Joystick *joystick, Packet *packet) {
	AnalogValueReachedCallbackFunction callback_function = (AnalogValueReachedCallbackFunction)joystick->registered_callbacks[JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED];
	void *user_data = joystick->registered_callback_user_data[JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED];
	AnalogValueReachedCallback_ *callback = (AnalogValueReachedCallback_ *)packet;

	callback->x = leconvert_uint16_from(callback->x);
	callback->y = leconvert_uint16_from(callback->y);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, user_data);
	}
}

static void joystick_callback_wrapper_pressed(Joystick *joystick, Packet *packet) {
	PressedCallbackFunction callback_function = (PressedCallbackFunction)joystick->registered_callbacks[JOYSTICK_CALLBACK_PRESSED];
	void *user_data = joystick->registered_callback_user_data[JOYSTICK_CALLBACK_PRESSED];
	(void)packet;

	if (callback_function != NULL) {
		callback_function(user_data);
	}
}

static void joystick_callback_wrapper_released(Joystick *joystick, Packet *packet) {
	ReleasedCallbackFunction callback_function = (ReleasedCallbackFunction)joystick->registered_callbacks[JOYSTICK_CALLBACK_RELEASED];
	void *user_data = joystick->registered_callback_user_data[JOYSTICK_CALLBACK_RELEASED];
	(void)packet;

	if (callback_function != NULL) {
		callback_function(user_data);
	}
}

void joystick_create(Joystick *joystick, const char *uid, IPConnection *ipcon) {
	device_create(joystick, uid, ipcon, 2, 0, 0);

	joystick->response_expected[JOYSTICK_FUNCTION_GET_POSITION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_IS_PRESSED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_GET_ANALOG_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_CALIBRATE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	joystick->response_expected[JOYSTICK_FUNCTION_SET_POSITION_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_GET_POSITION_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_SET_POSITION_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_GET_POSITION_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	joystick->response_expected[JOYSTICK_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	joystick->response_expected[JOYSTICK_CALLBACK_POSITION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	joystick->response_expected[JOYSTICK_CALLBACK_ANALOG_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	joystick->response_expected[JOYSTICK_CALLBACK_POSITION_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	joystick->response_expected[JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	joystick->response_expected[JOYSTICK_CALLBACK_PRESSED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	joystick->response_expected[JOYSTICK_CALLBACK_RELEASED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	joystick->response_expected[JOYSTICK_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	joystick->callback_wrappers[JOYSTICK_CALLBACK_POSITION] = (void *)joystick_callback_wrapper_position;
	joystick->callback_wrappers[JOYSTICK_CALLBACK_ANALOG_VALUE] = (void *)joystick_callback_wrapper_analog_value;
	joystick->callback_wrappers[JOYSTICK_CALLBACK_POSITION_REACHED] = (void *)joystick_callback_wrapper_position_reached;
	joystick->callback_wrappers[JOYSTICK_CALLBACK_ANALOG_VALUE_REACHED] = (void *)joystick_callback_wrapper_analog_value_reached;
	joystick->callback_wrappers[JOYSTICK_CALLBACK_PRESSED] = (void *)joystick_callback_wrapper_pressed;
	joystick->callback_wrappers[JOYSTICK_CALLBACK_RELEASED] = (void *)joystick_callback_wrapper_released;
}

void joystick_destroy(Joystick *joystick) {
	device_destroy(joystick);
}

int joystick_get_response_expected(Joystick *joystick, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(joystick, function_id, ret_response_expected);
}

int joystick_set_response_expected(Joystick *joystick, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(joystick, function_id, response_expected);
}

int joystick_set_response_expected_all(Joystick *joystick, bool response_expected) {
	return device_set_response_expected_all(joystick, response_expected);
}

void joystick_register_callback(Joystick *joystick, uint8_t id, void *callback, void *user_data) {
	device_register_callback(joystick, id, callback, user_data);
}

int joystick_get_api_version(Joystick *joystick, uint8_t ret_api_version[3]) {
	return device_get_api_version(joystick, ret_api_version);
}

int joystick_get_position(Joystick *joystick, int16_t *ret_x, int16_t *ret_y) {
	GetPosition_ request;
	GetPositionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_POSITION, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_x = leconvert_int16_from(response.x);
	*ret_y = leconvert_int16_from(response.y);



	return ret;
}

int joystick_is_pressed(Joystick *joystick, bool *ret_pressed) {
	IsPressed_ request;
	IsPressedResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_IS_PRESSED, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_pressed = response.pressed;



	return ret;
}

int joystick_get_analog_value(Joystick *joystick, uint16_t *ret_x, uint16_t *ret_y) {
	GetAnalogValue_ request;
	GetAnalogValueResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_ANALOG_VALUE, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_x = leconvert_uint16_from(response.x);
	*ret_y = leconvert_uint16_from(response.y);



	return ret;
}

int joystick_calibrate(Joystick *joystick) {
	Calibrate_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_CALIBRATE, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, NULL);


	return ret;
}

int joystick_set_position_callback_period(Joystick *joystick, uint32_t period) {
	SetPositionCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_SET_POSITION_CALLBACK_PERIOD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(joystick, (Packet *)&request, NULL);


	return ret;
}

int joystick_get_position_callback_period(Joystick *joystick, uint32_t *ret_period) {
	GetPositionCallbackPeriod_ request;
	GetPositionCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_POSITION_CALLBACK_PERIOD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int joystick_set_analog_value_callback_period(Joystick *joystick, uint32_t period) {
	SetAnalogValueCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_SET_ANALOG_VALUE_CALLBACK_PERIOD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(joystick, (Packet *)&request, NULL);


	return ret;
}

int joystick_get_analog_value_callback_period(Joystick *joystick, uint32_t *ret_period) {
	GetAnalogValueCallbackPeriod_ request;
	GetAnalogValueCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_ANALOG_VALUE_CALLBACK_PERIOD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int joystick_set_position_callback_threshold(Joystick *joystick, char option, int16_t min_x, int16_t max_x, int16_t min_y, int16_t max_y) {
	SetPositionCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_SET_POSITION_CALLBACK_THRESHOLD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min_x = leconvert_int16_to(min_x);
	request.max_x = leconvert_int16_to(max_x);
	request.min_y = leconvert_int16_to(min_y);
	request.max_y = leconvert_int16_to(max_y);

	ret = device_send_request(joystick, (Packet *)&request, NULL);


	return ret;
}

int joystick_get_position_callback_threshold(Joystick *joystick, char *ret_option, int16_t *ret_min_x, int16_t *ret_max_x, int16_t *ret_min_y, int16_t *ret_max_y) {
	GetPositionCallbackThreshold_ request;
	GetPositionCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_POSITION_CALLBACK_THRESHOLD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min_x = leconvert_int16_from(response.min_x);
	*ret_max_x = leconvert_int16_from(response.max_x);
	*ret_min_y = leconvert_int16_from(response.min_y);
	*ret_max_y = leconvert_int16_from(response.max_y);



	return ret;
}

int joystick_set_analog_value_callback_threshold(Joystick *joystick, char option, uint16_t min_x, uint16_t max_x, uint16_t min_y, uint16_t max_y) {
	SetAnalogValueCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min_x = leconvert_uint16_to(min_x);
	request.max_x = leconvert_uint16_to(max_x);
	request.min_y = leconvert_uint16_to(min_y);
	request.max_y = leconvert_uint16_to(max_y);

	ret = device_send_request(joystick, (Packet *)&request, NULL);


	return ret;
}

int joystick_get_analog_value_callback_threshold(Joystick *joystick, char *ret_option, uint16_t *ret_min_x, uint16_t *ret_max_x, uint16_t *ret_min_y, uint16_t *ret_max_y) {
	GetAnalogValueCallbackThreshold_ request;
	GetAnalogValueCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min_x = leconvert_uint16_from(response.min_x);
	*ret_max_x = leconvert_uint16_from(response.max_x);
	*ret_min_y = leconvert_uint16_from(response.min_y);
	*ret_max_y = leconvert_uint16_from(response.max_y);



	return ret;
}

int joystick_set_debounce_period(Joystick *joystick, uint32_t debounce) {
	SetDebouncePeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_SET_DEBOUNCE_PERIOD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(joystick, (Packet *)&request, NULL);


	return ret;
}

int joystick_get_debounce_period(Joystick *joystick, uint32_t *ret_debounce) {
	GetDebouncePeriod_ request;
	GetDebouncePeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_DEBOUNCE_PERIOD, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_debounce = leconvert_uint32_from(response.debounce);



	return ret;
}

int joystick_get_identity(Joystick *joystick, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), JOYSTICK_FUNCTION_GET_IDENTITY, joystick->ipcon, joystick);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(joystick, (Packet *)&request, (Packet *)&response);

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
