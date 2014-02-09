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

#include "bricklet_voltage_current.h"

#include <string.h>



typedef void (*CurrentCallbackFunction)(int32_t, void *);

typedef void (*VoltageCallbackFunction)(int32_t, void *);

typedef void (*PowerCallbackFunction)(int32_t, void *);

typedef void (*CurrentReachedCallbackFunction)(int32_t, void *);

typedef void (*VoltageReachedCallbackFunction)(int32_t, void *);

typedef void (*PowerReachedCallbackFunction)(int32_t, void *);

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
} ATTRIBUTE_PACKED GetCurrent_;

typedef struct {
	PacketHeader header;
	int32_t current;
} ATTRIBUTE_PACKED GetCurrentResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetVoltage_;

typedef struct {
	PacketHeader header;
	int32_t voltage;
} ATTRIBUTE_PACKED GetVoltageResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetPower_;

typedef struct {
	PacketHeader header;
	int32_t power;
} ATTRIBUTE_PACKED GetPowerResponse_;

typedef struct {
	PacketHeader header;
	uint8_t averaging;
	uint8_t voltage_conversion_time;
	uint8_t current_conversion_time;
} ATTRIBUTE_PACKED SetConfiguration_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetConfiguration_;

typedef struct {
	PacketHeader header;
	uint8_t averaging;
	uint8_t voltage_conversion_time;
	uint8_t current_conversion_time;
} ATTRIBUTE_PACKED GetConfigurationResponse_;

typedef struct {
	PacketHeader header;
	uint16_t gain_multiplier;
	uint16_t gain_divisor;
} ATTRIBUTE_PACKED SetCalibration_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetCalibration_;

typedef struct {
	PacketHeader header;
	uint16_t gain_multiplier;
	uint16_t gain_divisor;
} ATTRIBUTE_PACKED GetCalibrationResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetCurrentCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetCurrentCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetCurrentCallbackPeriodResponse_;

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
} ATTRIBUTE_PACKED SetPowerCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetPowerCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetPowerCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED SetCurrentCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetCurrentCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED GetCurrentCallbackThresholdResponse_;

typedef struct {
	PacketHeader header;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED SetVoltageCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetVoltageCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED GetVoltageCallbackThresholdResponse_;

typedef struct {
	PacketHeader header;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED SetPowerCallbackThreshold_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetPowerCallbackThreshold_;

typedef struct {
	PacketHeader header;
	char option;
	int32_t min;
	int32_t max;
} ATTRIBUTE_PACKED GetPowerCallbackThresholdResponse_;

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
	int32_t current;
} ATTRIBUTE_PACKED CurrentCallback_;

typedef struct {
	PacketHeader header;
	int32_t voltage;
} ATTRIBUTE_PACKED VoltageCallback_;

typedef struct {
	PacketHeader header;
	int32_t power;
} ATTRIBUTE_PACKED PowerCallback_;

typedef struct {
	PacketHeader header;
	int32_t current;
} ATTRIBUTE_PACKED CurrentReachedCallback_;

typedef struct {
	PacketHeader header;
	int32_t voltage;
} ATTRIBUTE_PACKED VoltageReachedCallback_;

typedef struct {
	PacketHeader header;
	int32_t power;
} ATTRIBUTE_PACKED PowerReachedCallback_;

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

static void voltage_current_callback_wrapper_current(VoltageCurrent *voltage_current, Packet *packet) {
	CurrentCallbackFunction callback_function = (CurrentCallbackFunction)voltage_current->registered_callbacks[VOLTAGE_CURRENT_CALLBACK_CURRENT];
	void *user_data = voltage_current->registered_callback_user_data[VOLTAGE_CURRENT_CALLBACK_CURRENT];
	CurrentCallback_ *callback = (CurrentCallback_ *)packet;

	callback->current = leconvert_int32_from(callback->current);

	if (callback_function != NULL) {
		callback_function(callback->current, user_data);
	}
}

static void voltage_current_callback_wrapper_voltage(VoltageCurrent *voltage_current, Packet *packet) {
	VoltageCallbackFunction callback_function = (VoltageCallbackFunction)voltage_current->registered_callbacks[VOLTAGE_CURRENT_CALLBACK_VOLTAGE];
	void *user_data = voltage_current->registered_callback_user_data[VOLTAGE_CURRENT_CALLBACK_VOLTAGE];
	VoltageCallback_ *callback = (VoltageCallback_ *)packet;

	callback->voltage = leconvert_int32_from(callback->voltage);

	if (callback_function != NULL) {
		callback_function(callback->voltage, user_data);
	}
}

static void voltage_current_callback_wrapper_power(VoltageCurrent *voltage_current, Packet *packet) {
	PowerCallbackFunction callback_function = (PowerCallbackFunction)voltage_current->registered_callbacks[VOLTAGE_CURRENT_CALLBACK_POWER];
	void *user_data = voltage_current->registered_callback_user_data[VOLTAGE_CURRENT_CALLBACK_POWER];
	PowerCallback_ *callback = (PowerCallback_ *)packet;

	callback->power = leconvert_int32_from(callback->power);

	if (callback_function != NULL) {
		callback_function(callback->power, user_data);
	}
}

static void voltage_current_callback_wrapper_current_reached(VoltageCurrent *voltage_current, Packet *packet) {
	CurrentReachedCallbackFunction callback_function = (CurrentReachedCallbackFunction)voltage_current->registered_callbacks[VOLTAGE_CURRENT_CALLBACK_CURRENT_REACHED];
	void *user_data = voltage_current->registered_callback_user_data[VOLTAGE_CURRENT_CALLBACK_CURRENT_REACHED];
	CurrentReachedCallback_ *callback = (CurrentReachedCallback_ *)packet;

	callback->current = leconvert_int32_from(callback->current);

	if (callback_function != NULL) {
		callback_function(callback->current, user_data);
	}
}

static void voltage_current_callback_wrapper_voltage_reached(VoltageCurrent *voltage_current, Packet *packet) {
	VoltageReachedCallbackFunction callback_function = (VoltageReachedCallbackFunction)voltage_current->registered_callbacks[VOLTAGE_CURRENT_CALLBACK_VOLTAGE_REACHED];
	void *user_data = voltage_current->registered_callback_user_data[VOLTAGE_CURRENT_CALLBACK_VOLTAGE_REACHED];
	VoltageReachedCallback_ *callback = (VoltageReachedCallback_ *)packet;

	callback->voltage = leconvert_int32_from(callback->voltage);

	if (callback_function != NULL) {
		callback_function(callback->voltage, user_data);
	}
}

static void voltage_current_callback_wrapper_power_reached(VoltageCurrent *voltage_current, Packet *packet) {
	PowerReachedCallbackFunction callback_function = (PowerReachedCallbackFunction)voltage_current->registered_callbacks[VOLTAGE_CURRENT_CALLBACK_POWER_REACHED];
	void *user_data = voltage_current->registered_callback_user_data[VOLTAGE_CURRENT_CALLBACK_POWER_REACHED];
	PowerReachedCallback_ *callback = (PowerReachedCallback_ *)packet;

	callback->power = leconvert_int32_from(callback->power);

	if (callback_function != NULL) {
		callback_function(callback->power, user_data);
	}
}

void voltage_current_create(VoltageCurrent *voltage_current, const char *uid, IPConnection *ipcon) {
	device_create(voltage_current, uid, ipcon, 2, 0, 0);

	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_CURRENT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_POWER] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_CONFIGURATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_CALIBRATION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_CALIBRATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_CURRENT_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_CURRENT_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_VOLTAGE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_VOLTAGE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_POWER_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_POWER_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_CURRENT_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_CURRENT_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_VOLTAGE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_VOLTAGE_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_POWER_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_POWER_CALLBACK_THRESHOLD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	voltage_current->response_expected[VOLTAGE_CURRENT_CALLBACK_CURRENT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_CALLBACK_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_CALLBACK_POWER] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_CALLBACK_CURRENT_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_CALLBACK_VOLTAGE_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_CALLBACK_POWER_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	voltage_current->response_expected[VOLTAGE_CURRENT_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	voltage_current->callback_wrappers[VOLTAGE_CURRENT_CALLBACK_CURRENT] = (void *)voltage_current_callback_wrapper_current;
	voltage_current->callback_wrappers[VOLTAGE_CURRENT_CALLBACK_VOLTAGE] = (void *)voltage_current_callback_wrapper_voltage;
	voltage_current->callback_wrappers[VOLTAGE_CURRENT_CALLBACK_POWER] = (void *)voltage_current_callback_wrapper_power;
	voltage_current->callback_wrappers[VOLTAGE_CURRENT_CALLBACK_CURRENT_REACHED] = (void *)voltage_current_callback_wrapper_current_reached;
	voltage_current->callback_wrappers[VOLTAGE_CURRENT_CALLBACK_VOLTAGE_REACHED] = (void *)voltage_current_callback_wrapper_voltage_reached;
	voltage_current->callback_wrappers[VOLTAGE_CURRENT_CALLBACK_POWER_REACHED] = (void *)voltage_current_callback_wrapper_power_reached;
}

void voltage_current_destroy(VoltageCurrent *voltage_current) {
	device_destroy(voltage_current);
}

int voltage_current_get_response_expected(VoltageCurrent *voltage_current, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(voltage_current, function_id, ret_response_expected);
}

int voltage_current_set_response_expected(VoltageCurrent *voltage_current, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(voltage_current, function_id, response_expected);
}

int voltage_current_set_response_expected_all(VoltageCurrent *voltage_current, bool response_expected) {
	return device_set_response_expected_all(voltage_current, response_expected);
}

void voltage_current_register_callback(VoltageCurrent *voltage_current, uint8_t id, void *callback, void *user_data) {
	device_register_callback(voltage_current, id, callback, user_data);
}

int voltage_current_get_api_version(VoltageCurrent *voltage_current, uint8_t ret_api_version[3]) {
	return device_get_api_version(voltage_current, ret_api_version);
}

int voltage_current_get_current(VoltageCurrent *voltage_current, int32_t *ret_current) {
	GetCurrent_ request;
	GetCurrentResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_CURRENT, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_current = leconvert_int32_from(response.current);



	return ret;
}

int voltage_current_get_voltage(VoltageCurrent *voltage_current, int32_t *ret_voltage) {
	GetVoltage_ request;
	GetVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_VOLTAGE, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_int32_from(response.voltage);



	return ret;
}

int voltage_current_get_power(VoltageCurrent *voltage_current, int32_t *ret_power) {
	GetPower_ request;
	GetPowerResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_POWER, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_power = leconvert_int32_from(response.power);



	return ret;
}

int voltage_current_set_configuration(VoltageCurrent *voltage_current, uint8_t averaging, uint8_t voltage_conversion_time, uint8_t current_conversion_time) {
	SetConfiguration_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_CONFIGURATION, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.averaging = averaging;
	request.voltage_conversion_time = voltage_conversion_time;
	request.current_conversion_time = current_conversion_time;

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_configuration(VoltageCurrent *voltage_current, uint8_t *ret_averaging, uint8_t *ret_voltage_conversion_time, uint8_t *ret_current_conversion_time) {
	GetConfiguration_ request;
	GetConfigurationResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_CONFIGURATION, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_averaging = response.averaging;
	*ret_voltage_conversion_time = response.voltage_conversion_time;
	*ret_current_conversion_time = response.current_conversion_time;



	return ret;
}

int voltage_current_set_calibration(VoltageCurrent *voltage_current, uint16_t gain_multiplier, uint16_t gain_divisor) {
	SetCalibration_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_CALIBRATION, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.gain_multiplier = leconvert_uint16_to(gain_multiplier);
	request.gain_divisor = leconvert_uint16_to(gain_divisor);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_calibration(VoltageCurrent *voltage_current, uint16_t *ret_gain_multiplier, uint16_t *ret_gain_divisor) {
	GetCalibration_ request;
	GetCalibrationResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_CALIBRATION, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_gain_multiplier = leconvert_uint16_from(response.gain_multiplier);
	*ret_gain_divisor = leconvert_uint16_from(response.gain_divisor);



	return ret;
}

int voltage_current_set_current_callback_period(VoltageCurrent *voltage_current, uint32_t period) {
	SetCurrentCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_CURRENT_CALLBACK_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_current_callback_period(VoltageCurrent *voltage_current, uint32_t *ret_period) {
	GetCurrentCallbackPeriod_ request;
	GetCurrentCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_CURRENT_CALLBACK_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int voltage_current_set_voltage_callback_period(VoltageCurrent *voltage_current, uint32_t period) {
	SetVoltageCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_VOLTAGE_CALLBACK_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_voltage_callback_period(VoltageCurrent *voltage_current, uint32_t *ret_period) {
	GetVoltageCallbackPeriod_ request;
	GetVoltageCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_VOLTAGE_CALLBACK_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int voltage_current_set_power_callback_period(VoltageCurrent *voltage_current, uint32_t period) {
	SetPowerCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_POWER_CALLBACK_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_power_callback_period(VoltageCurrent *voltage_current, uint32_t *ret_period) {
	GetPowerCallbackPeriod_ request;
	GetPowerCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_POWER_CALLBACK_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int voltage_current_set_current_callback_threshold(VoltageCurrent *voltage_current, char option, int32_t min, int32_t max) {
	SetCurrentCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_CURRENT_CALLBACK_THRESHOLD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int32_to(min);
	request.max = leconvert_int32_to(max);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_current_callback_threshold(VoltageCurrent *voltage_current, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
	GetCurrentCallbackThreshold_ request;
	GetCurrentCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_CURRENT_CALLBACK_THRESHOLD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int32_from(response.min);
	*ret_max = leconvert_int32_from(response.max);



	return ret;
}

int voltage_current_set_voltage_callback_threshold(VoltageCurrent *voltage_current, char option, int32_t min, int32_t max) {
	SetVoltageCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_VOLTAGE_CALLBACK_THRESHOLD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int32_to(min);
	request.max = leconvert_int32_to(max);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_voltage_callback_threshold(VoltageCurrent *voltage_current, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
	GetVoltageCallbackThreshold_ request;
	GetVoltageCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_VOLTAGE_CALLBACK_THRESHOLD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int32_from(response.min);
	*ret_max = leconvert_int32_from(response.max);



	return ret;
}

int voltage_current_set_power_callback_threshold(VoltageCurrent *voltage_current, char option, int32_t min, int32_t max) {
	SetPowerCallbackThreshold_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_POWER_CALLBACK_THRESHOLD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.option = option;
	request.min = leconvert_int32_to(min);
	request.max = leconvert_int32_to(max);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_power_callback_threshold(VoltageCurrent *voltage_current, char *ret_option, int32_t *ret_min, int32_t *ret_max) {
	GetPowerCallbackThreshold_ request;
	GetPowerCallbackThresholdResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_POWER_CALLBACK_THRESHOLD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_option = response.option;
	*ret_min = leconvert_int32_from(response.min);
	*ret_max = leconvert_int32_from(response.max);



	return ret;
}

int voltage_current_set_debounce_period(VoltageCurrent *voltage_current, uint32_t debounce) {
	SetDebouncePeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_SET_DEBOUNCE_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(voltage_current, (Packet *)&request, NULL);


	return ret;
}

int voltage_current_get_debounce_period(VoltageCurrent *voltage_current, uint32_t *ret_debounce) {
	GetDebouncePeriod_ request;
	GetDebouncePeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_DEBOUNCE_PERIOD, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_debounce = leconvert_uint32_from(response.debounce);



	return ret;
}

int voltage_current_get_identity(VoltageCurrent *voltage_current, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), VOLTAGE_CURRENT_FUNCTION_GET_IDENTITY, voltage_current->ipcon, voltage_current);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(voltage_current, (Packet *)&request, (Packet *)&response);

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
