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

#include "bricklet_industrial_dual_0_20ma.h"

#include <string.h>



typedef void (*CurrentCallbackFunction)(uint8_t, int32_t, void *);

typedef void (*CurrentReachedCallbackFunction)(uint8_t, int32_t, void *);

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
	uint8_t sensor;
} ATTRIBUTE_PACKED GetCurrent_;

typedef struct {
	PacketHeader header;
	int32_t current;
} ATTRIBUTE_PACKED GetCurrentResponse_;

typedef struct {
	PacketHeader header;
	uint8_t sensor;
	uint32_t period;
} ATTRIBUTE_PACKED SetCurrentCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint8_t sensor;
} ATTRIBUTE_PACKED GetCurrentCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetCurrentCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint8_t sensor;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED SetCurrentCallbackThreshold_;

typedef struct {
	PacketHeader header;
	uint8_t sensor;
} ATTRIBUTE_PACKED GetCurrentCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED GetCurrentCallbackThresholdResponse_;

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
	uint8_t rate;
} ATTRIBUTE_PACKED SetSampleRate_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetSampleRate_;

typedef struct {
	PacketHeader header;
	uint8_t rate;
} ATTRIBUTE_PACKED GetSampleRateResponse_;

typedef struct {
	PacketHeader header;
	uint8_t sensor;
	int32_t current;
} ATTRIBUTE_PACKED CurrentCallback_;

typedef struct {
	PacketHeader header;
	uint8_t sensor;
	int32_t current;
} ATTRIBUTE_PACKED CurrentReachedCallback_;

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

static void industrial_dual_0_20ma_callback_wrapper_current(IndustrialDual020mA *industrial_dual_0_20ma, Packet *packet) {
	CurrentCallbackFunction callback_function = (CurrentCallbackFunction)industrial_dual_0_20ma->registered_callbacks[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT];
	void *user_data = industrial_dual_0_20ma->registered_callback_user_data[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT];
	CurrentCallback_ *callback = (CurrentCallback_ *)packet;

	callback->current = leconvert_int32_from(callback->current);

	if (callback_function != NULL) {
		callback_function(callback->sensor, callback->current, user_data);
	}
}

static void industrial_dual_0_20ma_callback_wrapper_current_reached(IndustrialDual020mA *industrial_dual_0_20ma, Packet *packet) {
	CurrentReachedCallbackFunction callback_function = (CurrentReachedCallbackFunction)industrial_dual_0_20ma->registered_callbacks[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT_REACHED];
	void *user_data = industrial_dual_0_20ma->registered_callback_user_data[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT_REACHED];
	CurrentReachedCallback_ *callback = (CurrentReachedCallback_ *)packet;

	callback->current = leconvert_int32_from(callback->current);

	if (callback_function != NULL) {
		callback_function(callback->sensor, callback->current, user_data);
	}
}

void industrial_dual_0_20ma_create(IndustrialDual020mA *industrial_dual_0_20ma, const char *uid, IPConnection *ipcon) {
	device_create(industrial_dual_0_20ma, uid, ipcon, 2, 0, 0);

	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_CURRENT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_CURRENT_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_CURRENT_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_CURRENT_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_CURRENT_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_SAMPLE_RATE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_SAMPLE_RATE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	industrial_dual_0_20ma->response_expected[INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	industrial_dual_0_20ma->callback_wrappers[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT] = (void *)industrial_dual_0_20ma_callback_wrapper_current;
	industrial_dual_0_20ma->callback_wrappers[INDUSTRIAL_DUAL_0_20MA_CALLBACK_CURRENT_REACHED] = (void *)industrial_dual_0_20ma_callback_wrapper_current_reached;
}

void industrial_dual_0_20ma_destroy(IndustrialDual020mA *industrial_dual_0_20ma) {
	device_destroy(industrial_dual_0_20ma);
}

int industrial_dual_0_20ma_get_response_expected(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(industrial_dual_0_20ma, function_id, ret_response_expected);
}

int industrial_dual_0_20ma_set_response_expected(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(industrial_dual_0_20ma, function_id, response_expected);
}

int industrial_dual_0_20ma_set_response_expected_all(IndustrialDual020mA *industrial_dual_0_20ma, bool response_expected) {
	return device_set_response_expected_all(industrial_dual_0_20ma, response_expected);
}

void industrial_dual_0_20ma_register_callback(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t id, void *callback, void *user_data) {
	device_register_callback(industrial_dual_0_20ma, id, callback, user_data);
}

int industrial_dual_0_20ma_get_api_version(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t ret_api_version[3]) {
	return device_get_api_version(industrial_dual_0_20ma, ret_api_version);
}

int industrial_dual_0_20ma_get_current(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t sensor, int32_t *ret_current) {
	GetCurrent_ request;
	GetCurrentResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_CURRENT, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}

	request.sensor = sensor;

	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_current = leconvert_int32_from(response.current);



	return ret;
}

int industrial_dual_0_20ma_set_current_callback_period(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t sensor, uint32_t period) {
	SetCurrentCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_CURRENT_CALLBACK_PERIOD, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}

	request.sensor = sensor;
	request.period = leconvert_uint32_to(period);

	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, NULL);


	return ret;
}

int industrial_dual_0_20ma_get_current_callback_period(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t sensor, uint32_t *ret_period) {
	GetCurrentCallbackPeriod_ request;
	GetCurrentCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_CURRENT_CALLBACK_PERIOD, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}

	request.sensor = sensor;

	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int industrial_dual_0_20ma_set_current_callback_threshold(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t sensor, char option, int32_t min, int32_t max) {
	SetCurrentCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_CURRENT_CALLBACK_THRESHOLD, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}

	request.sensor = sensor;
	request.option = option;
	request.min = leconvert_int32_to(min);
	request.max = leconvert_int32_to(max);

	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, NULL);


	return ret;
}

int industrial_dual_0_20ma_get_current_callback_threshold(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t sensor, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
	GetCurrentCallbackThreshold_ request;
	GetCurrentCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_CURRENT_CALLBACK_THRESHOLD, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}

	request.sensor = sensor;

	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int32_from(response.min);
	*ret_max = leconvert_int32_from(response.max);



	return ret;
}

int industrial_dual_0_20ma_set_debounce_period(IndustrialDual020mA *industrial_dual_0_20ma, uint32_t debounce) {
	SetDebouncePeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_DEBOUNCE_PERIOD, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, NULL);


	return ret;
}

int industrial_dual_0_20ma_get_debounce_period(IndustrialDual020mA *industrial_dual_0_20ma, uint32_t *ret_debounce) {
	GetDebouncePeriod_ request;
	GetDebouncePeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_DEBOUNCE_PERIOD, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_debounce = leconvert_uint32_from(response.debounce);



	return ret;
}

int industrial_dual_0_20ma_set_sample_rate(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t rate) {
	SetSampleRate_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_SET_SAMPLE_RATE, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}

	request.rate = rate;

	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, NULL);


	return ret;
}

int industrial_dual_0_20ma_get_sample_rate(IndustrialDual020mA *industrial_dual_0_20ma, uint8_t *ret_rate) {
	GetSampleRate_ request;
	GetSampleRateResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_SAMPLE_RATE, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_rate = response.rate;



	return ret;
}

int industrial_dual_0_20ma_get_identity(IndustrialDual020mA *industrial_dual_0_20ma, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DUAL_0_20MA_FUNCTION_GET_IDENTITY, industrial_dual_0_20ma->ipcon, industrial_dual_0_20ma);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_dual_0_20ma, (Packet *)&request, (Packet *)&response);

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
