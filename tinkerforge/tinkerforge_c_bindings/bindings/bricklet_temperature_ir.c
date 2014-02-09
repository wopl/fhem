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

#include "bricklet_temperature_ir.h"

#include <string.h>



typedef void (*AmbientTemperatureCallbackFunction)(int16_t, void *);

typedef void (*ObjectTemperatureCallbackFunction)(int16_t, void *);

typedef void (*AmbientTemperatureReachedCallbackFunction)(int16_t, void *);

typedef void (*ObjectTemperatureReachedCallbackFunction)(int16_t, void *);

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
} ATTRIBUTE_PACKED GetAmbientTemperature_;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED GetAmbientTemperatureResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetObjectTemperature_;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED GetObjectTemperatureResponse_;

typedef struct {
	PacketHeader header;
	uint16_t emissivity;
} ATTRIBUTE_PACKED SetEmissivity_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetEmissivity_;

typedef struct {
	PacketHeader header;
	uint16_t emissivity;
} ATTRIBUTE_PACKED GetEmissivityResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetAmbientTemperatureCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAmbientTemperatureCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetAmbientTemperatureCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetObjectTemperatureCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetObjectTemperatureCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetObjectTemperatureCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED SetAmbientTemperatureCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAmbientTemperatureCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetAmbientTemperatureCallbackThresholdResponse_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED SetObjectTemperatureCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetObjectTemperatureCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetObjectTemperatureCallbackThresholdResponse_;

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
	int16_t temperature;
} ATTRIBUTE_PACKED AmbientTemperatureCallback_;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED ObjectTemperatureCallback_;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED AmbientTemperatureReachedCallback_;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED ObjectTemperatureReachedCallback_;

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

static void temperature_ir_callback_wrapper_ambient_temperature(TemperatureIR *temperature_ir, Packet *packet) {
	AmbientTemperatureCallbackFunction callback_function = (AmbientTemperatureCallbackFunction)temperature_ir->registered_callbacks[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE];
	void *user_data = temperature_ir->registered_callback_user_data[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE];
	AmbientTemperatureCallback_ *callback = (AmbientTemperatureCallback_ *)packet;

	callback->temperature = leconvert_int16_from(callback->temperature);

	if (callback_function != NULL) {
		callback_function(callback->temperature, user_data);
	}
}

static void temperature_ir_callback_wrapper_object_temperature(TemperatureIR *temperature_ir, Packet *packet) {
	ObjectTemperatureCallbackFunction callback_function = (ObjectTemperatureCallbackFunction)temperature_ir->registered_callbacks[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE];
	void *user_data = temperature_ir->registered_callback_user_data[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE];
	ObjectTemperatureCallback_ *callback = (ObjectTemperatureCallback_ *)packet;

	callback->temperature = leconvert_int16_from(callback->temperature);

	if (callback_function != NULL) {
		callback_function(callback->temperature, user_data);
	}
}

static void temperature_ir_callback_wrapper_ambient_temperature_reached(TemperatureIR *temperature_ir, Packet *packet) {
	AmbientTemperatureReachedCallbackFunction callback_function = (AmbientTemperatureReachedCallbackFunction)temperature_ir->registered_callbacks[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE_REACHED];
	void *user_data = temperature_ir->registered_callback_user_data[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE_REACHED];
	AmbientTemperatureReachedCallback_ *callback = (AmbientTemperatureReachedCallback_ *)packet;

	callback->temperature = leconvert_int16_from(callback->temperature);

	if (callback_function != NULL) {
		callback_function(callback->temperature, user_data);
	}
}

static void temperature_ir_callback_wrapper_object_temperature_reached(TemperatureIR *temperature_ir, Packet *packet) {
	ObjectTemperatureReachedCallbackFunction callback_function = (ObjectTemperatureReachedCallbackFunction)temperature_ir->registered_callbacks[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED];
	void *user_data = temperature_ir->registered_callback_user_data[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED];
	ObjectTemperatureReachedCallback_ *callback = (ObjectTemperatureReachedCallback_ *)packet;

	callback->temperature = leconvert_int16_from(callback->temperature);

	if (callback_function != NULL) {
		callback_function(callback->temperature, user_data);
	}
}

void temperature_ir_create(TemperatureIR *temperature_ir, const char *uid, IPConnection *ipcon) {
	device_create(temperature_ir, uid, ipcon, 2, 0, 0);

	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_AMBIENT_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_OBJECT_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_SET_EMISSIVITY] = DEVICE_RESPONSE_EXPECTED_FALSE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_EMISSIVITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_SET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_SET_OBJECT_TEMPERATURE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_OBJECT_TEMPERATURE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_SET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_SET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	temperature_ir->response_expected[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	temperature_ir->response_expected[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	temperature_ir->response_expected[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	temperature_ir->response_expected[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	temperature_ir->response_expected[TEMPERATURE_IR_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	temperature_ir->callback_wrappers[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE] = (void *)temperature_ir_callback_wrapper_ambient_temperature;
	temperature_ir->callback_wrappers[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE] = (void *)temperature_ir_callback_wrapper_object_temperature;
	temperature_ir->callback_wrappers[TEMPERATURE_IR_CALLBACK_AMBIENT_TEMPERATURE_REACHED] = (void *)temperature_ir_callback_wrapper_ambient_temperature_reached;
	temperature_ir->callback_wrappers[TEMPERATURE_IR_CALLBACK_OBJECT_TEMPERATURE_REACHED] = (void *)temperature_ir_callback_wrapper_object_temperature_reached;
}

void temperature_ir_destroy(TemperatureIR *temperature_ir) {
	device_destroy(temperature_ir);
}

int temperature_ir_get_response_expected(TemperatureIR *temperature_ir, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(temperature_ir, function_id, ret_response_expected);
}

int temperature_ir_set_response_expected(TemperatureIR *temperature_ir, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(temperature_ir, function_id, response_expected);
}

int temperature_ir_set_response_expected_all(TemperatureIR *temperature_ir, bool response_expected) {
	return device_set_response_expected_all(temperature_ir, response_expected);
}

void temperature_ir_register_callback(TemperatureIR *temperature_ir, uint8_t id, void *callback, void *user_data) {
	device_register_callback(temperature_ir, id, callback, user_data);
}

int temperature_ir_get_api_version(TemperatureIR *temperature_ir, uint8_t ret_api_version[3]) {
	return device_get_api_version(temperature_ir, ret_api_version);
}

int temperature_ir_get_ambient_temperature(TemperatureIR *temperature_ir, int16_t *ret_temperature) {
	GetAmbientTemperature_ request;
	GetAmbientTemperatureResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_AMBIENT_TEMPERATURE, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_temperature = leconvert_int16_from(response.temperature);



	return ret;
}

int temperature_ir_get_object_temperature(TemperatureIR *temperature_ir, int16_t *ret_temperature) {
	GetObjectTemperature_ request;
	GetObjectTemperatureResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_OBJECT_TEMPERATURE, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_temperature = leconvert_int16_from(response.temperature);



	return ret;
}

int temperature_ir_set_emissivity(TemperatureIR *temperature_ir, uint16_t emissivity) {
	SetEmissivity_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_SET_EMISSIVITY, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}

	request.emissivity = leconvert_uint16_to(emissivity);

	ret = device_send_request(temperature_ir, (Packet *)&request, NULL);


	return ret;
}

int temperature_ir_get_emissivity(TemperatureIR *temperature_ir, uint16_t *ret_emissivity) {
	GetEmissivity_ request;
	GetEmissivityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_EMISSIVITY, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_emissivity = leconvert_uint16_from(response.emissivity);



	return ret;
}

int temperature_ir_set_ambient_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t period) {
	SetAmbientTemperatureCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_SET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(temperature_ir, (Packet *)&request, NULL);


	return ret;
}

int temperature_ir_get_ambient_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t *ret_period) {
	GetAmbientTemperatureCallbackPeriod_ request;
	GetAmbientTemperatureCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_AMBIENT_TEMPERATURE_CALLBACK_PERIOD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int temperature_ir_set_object_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t period) {
	SetObjectTemperatureCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_SET_OBJECT_TEMPERATURE_CALLBACK_PERIOD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(temperature_ir, (Packet *)&request, NULL);


	return ret;
}

int temperature_ir_get_object_temperature_callback_period(TemperatureIR *temperature_ir, uint32_t *ret_period) {
	GetObjectTemperatureCallbackPeriod_ request;
	GetObjectTemperatureCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_OBJECT_TEMPERATURE_CALLBACK_PERIOD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int temperature_ir_set_ambient_temperature_callback_threshold(TemperatureIR *temperature_ir, char option, int16_t min, int16_t max) {
	SetAmbientTemperatureCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_SET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int16_to(min);
	request.max = leconvert_int16_to(max);

	ret = device_send_request(temperature_ir, (Packet *)&request, NULL);


	return ret;
}

int temperature_ir_get_ambient_temperature_callback_threshold(TemperatureIR *temperature_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	GetAmbientTemperatureCallbackThreshold_ request;
	GetAmbientTemperatureCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_AMBIENT_TEMPERATURE_CALLBACK_THRESHOLD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int16_from(response.min);
	*ret_max = leconvert_int16_from(response.max);



	return ret;
}

int temperature_ir_set_object_temperature_callback_threshold(TemperatureIR *temperature_ir, char option, int16_t min, int16_t max) {
	SetObjectTemperatureCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_SET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int16_to(min);
	request.max = leconvert_int16_to(max);

	ret = device_send_request(temperature_ir, (Packet *)&request, NULL);


	return ret;
}

int temperature_ir_get_object_temperature_callback_threshold(TemperatureIR *temperature_ir, char *ret_option, int16_t *ret_min, int16_t *ret_max) {
	GetObjectTemperatureCallbackThreshold_ request;
	GetObjectTemperatureCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_OBJECT_TEMPERATURE_CALLBACK_THRESHOLD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int16_from(response.min);
	*ret_max = leconvert_int16_from(response.max);



	return ret;
}

int temperature_ir_set_debounce_period(TemperatureIR *temperature_ir, uint32_t debounce) {
	SetDebouncePeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_SET_DEBOUNCE_PERIOD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(temperature_ir, (Packet *)&request, NULL);


	return ret;
}

int temperature_ir_get_debounce_period(TemperatureIR *temperature_ir, uint32_t *ret_debounce) {
	GetDebouncePeriod_ request;
	GetDebouncePeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_DEBOUNCE_PERIOD, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_debounce = leconvert_uint32_from(response.debounce);



	return ret;
}

int temperature_ir_get_identity(TemperatureIR *temperature_ir, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), TEMPERATURE_IR_FUNCTION_GET_IDENTITY, temperature_ir->ipcon, temperature_ir);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(temperature_ir, (Packet *)&request, (Packet *)&response);

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
