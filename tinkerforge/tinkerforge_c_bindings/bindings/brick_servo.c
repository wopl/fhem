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

#include "brick_servo.h"

#include <string.h>



typedef void (*UnderVoltageCallbackFunction)(uint16_t, void *);

typedef void (*PositionReachedCallbackFunction)(uint8_t, int16_t, void *);

typedef void (*VelocityReachedCallbackFunction)(uint8_t, int16_t, void *);

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
	uint8_t servo_num;
} ATTRIBUTE_PACKED Enable_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED Disable_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED IsEnabled_;

typedef struct {
	PacketHeader header;
	bool enabled;
} ATTRIBUTE_PACKED IsEnabledResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	int16_t position;
} ATTRIBUTE_PACKED SetPosition_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetPosition_;

typedef struct {
	PacketHeader header;
	int16_t position;
} ATTRIBUTE_PACKED GetPositionResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetCurrentPosition_;

typedef struct {
	PacketHeader header;
	int16_t position;
} ATTRIBUTE_PACKED GetCurrentPositionResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	uint16_t velocity;
} ATTRIBUTE_PACKED SetVelocity_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetVelocity_;

typedef struct {
	PacketHeader header;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetVelocityResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetCurrentVelocity_;

typedef struct {
	PacketHeader header;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetCurrentVelocityResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	uint16_t acceleration;
} ATTRIBUTE_PACKED SetAcceleration_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetAcceleration_;

typedef struct {
	PacketHeader header;
	uint16_t acceleration;
} ATTRIBUTE_PACKED GetAccelerationResponse_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED SetOutputVoltage_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetOutputVoltage_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetOutputVoltageResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED SetPulseWidth_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetPulseWidth_;

typedef struct {
	PacketHeader header;
	uint16_t min;
	uint16_t max;
} ATTRIBUTE_PACKED GetPulseWidthResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED SetDegree_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetDegree_;

typedef struct {
	PacketHeader header;
	int16_t min;
	int16_t max;
} ATTRIBUTE_PACKED GetDegreeResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	uint16_t period;
} ATTRIBUTE_PACKED SetPeriod_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetPeriod_;

typedef struct {
	PacketHeader header;
	uint16_t period;
} ATTRIBUTE_PACKED GetPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
} ATTRIBUTE_PACKED GetServoCurrent_;

typedef struct {
	PacketHeader header;
	uint16_t current;
} ATTRIBUTE_PACKED GetServoCurrentResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetOverallCurrent_;

typedef struct {
	PacketHeader header;
	uint16_t current;
} ATTRIBUTE_PACKED GetOverallCurrentResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetStackInputVoltage_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetStackInputVoltageResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetExternalInputVoltage_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetExternalInputVoltageResponse_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED SetMinimumVoltage_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMinimumVoltage_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetMinimumVoltageResponse_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED UnderVoltageCallback_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	int16_t position;
} ATTRIBUTE_PACKED PositionReachedCallback_;

typedef struct {
	PacketHeader header;
	uint8_t servo_num;
	int16_t velocity;
} ATTRIBUTE_PACKED VelocityReachedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED EnablePositionReachedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED DisablePositionReachedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED IsPositionReachedCallbackEnabled_;

typedef struct {
	PacketHeader header;
	uint8_t enabled;
} ATTRIBUTE_PACKED IsPositionReachedCallbackEnabledResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED EnableVelocityReachedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED DisableVelocityReachedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED IsVelocityReachedCallbackEnabled_;

typedef struct {
	PacketHeader header;
	uint8_t enabled;
} ATTRIBUTE_PACKED IsVelocityReachedCallbackEnabledResponse_;

typedef struct {
	PacketHeader header;
	char port;
} ATTRIBUTE_PACKED GetProtocol1BrickletName_;

typedef struct {
	PacketHeader header;
	uint8_t protocol_version;
	uint8_t firmware_version[3];
	char name[40];
} ATTRIBUTE_PACKED GetProtocol1BrickletNameResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetChipTemperature_;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED GetChipTemperatureResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Reset_;

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

static void servo_callback_wrapper_under_voltage(Servo *servo, Packet *packet) {
	UnderVoltageCallbackFunction callback_function = (UnderVoltageCallbackFunction)servo->registered_callbacks[SERVO_CALLBACK_UNDER_VOLTAGE];
	void *user_data = servo->registered_callback_user_data[SERVO_CALLBACK_UNDER_VOLTAGE];
	UnderVoltageCallback_ *callback = (UnderVoltageCallback_ *)packet;

	callback->voltage = leconvert_uint16_from(callback->voltage);

	if (callback_function != NULL) {
		callback_function(callback->voltage, user_data);
	}
}

static void servo_callback_wrapper_position_reached(Servo *servo, Packet *packet) {
	PositionReachedCallbackFunction callback_function = (PositionReachedCallbackFunction)servo->registered_callbacks[SERVO_CALLBACK_POSITION_REACHED];
	void *user_data = servo->registered_callback_user_data[SERVO_CALLBACK_POSITION_REACHED];
	PositionReachedCallback_ *callback = (PositionReachedCallback_ *)packet;

	callback->position = leconvert_int16_from(callback->position);

	if (callback_function != NULL) {
		callback_function(callback->servo_num, callback->position, user_data);
	}
}

static void servo_callback_wrapper_velocity_reached(Servo *servo, Packet *packet) {
	VelocityReachedCallbackFunction callback_function = (VelocityReachedCallbackFunction)servo->registered_callbacks[SERVO_CALLBACK_VELOCITY_REACHED];
	void *user_data = servo->registered_callback_user_data[SERVO_CALLBACK_VELOCITY_REACHED];
	VelocityReachedCallback_ *callback = (VelocityReachedCallback_ *)packet;

	callback->velocity = leconvert_int16_from(callback->velocity);

	if (callback_function != NULL) {
		callback_function(callback->servo_num, callback->velocity, user_data);
	}
}

void servo_create(Servo *servo, const char *uid, IPConnection *ipcon) {
	device_create(servo, uid, ipcon, 2, 0, 0);

	servo->response_expected[SERVO_FUNCTION_ENABLE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_DISABLE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_IS_ENABLED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_POSITION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_POSITION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_CURRENT_POSITION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_VELOCITY] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_VELOCITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_CURRENT_VELOCITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_ACCELERATION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_ACCELERATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_OUTPUT_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_OUTPUT_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_PULSE_WIDTH] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_PULSE_WIDTH] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_DEGREE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_DEGREE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_PERIOD] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_SERVO_CURRENT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_OVERALL_CURRENT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_STACK_INPUT_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_SET_MINIMUM_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_MINIMUM_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_CALLBACK_UNDER_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	servo->response_expected[SERVO_CALLBACK_POSITION_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	servo->response_expected[SERVO_CALLBACK_VELOCITY_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	servo->response_expected[SERVO_FUNCTION_ENABLE_POSITION_REACHED_CALLBACK] = DEVICE_RESPONSE_EXPECTED_TRUE;
	servo->response_expected[SERVO_FUNCTION_DISABLE_POSITION_REACHED_CALLBACK] = DEVICE_RESPONSE_EXPECTED_TRUE;
	servo->response_expected[SERVO_FUNCTION_IS_POSITION_REACHED_CALLBACK_ENABLED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_ENABLE_VELOCITY_REACHED_CALLBACK] = DEVICE_RESPONSE_EXPECTED_TRUE;
	servo->response_expected[SERVO_FUNCTION_DISABLE_VELOCITY_REACHED_CALLBACK] = DEVICE_RESPONSE_EXPECTED_TRUE;
	servo->response_expected[SERVO_FUNCTION_IS_VELOCITY_REACHED_CALLBACK_ENABLED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_PROTOCOL1_BRICKLET_NAME] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_GET_CHIP_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	servo->response_expected[SERVO_FUNCTION_RESET] = DEVICE_RESPONSE_EXPECTED_FALSE;
	servo->response_expected[SERVO_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	servo->callback_wrappers[SERVO_CALLBACK_UNDER_VOLTAGE] = (void *)servo_callback_wrapper_under_voltage;
	servo->callback_wrappers[SERVO_CALLBACK_POSITION_REACHED] = (void *)servo_callback_wrapper_position_reached;
	servo->callback_wrappers[SERVO_CALLBACK_VELOCITY_REACHED] = (void *)servo_callback_wrapper_velocity_reached;
}

void servo_destroy(Servo *servo) {
	device_destroy(servo);
}

int servo_get_response_expected(Servo *servo, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(servo, function_id, ret_response_expected);
}

int servo_set_response_expected(Servo *servo, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(servo, function_id, response_expected);
}

int servo_set_response_expected_all(Servo *servo, bool response_expected) {
	return device_set_response_expected_all(servo, response_expected);
}

void servo_register_callback(Servo *servo, uint8_t id, void *callback, void *user_data) {
	device_register_callback(servo, id, callback, user_data);
}

int servo_get_api_version(Servo *servo, uint8_t ret_api_version[3]) {
	return device_get_api_version(servo, ret_api_version);
}

int servo_enable(Servo *servo, uint8_t servo_num) {
	Enable_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_ENABLE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_disable(Servo *servo, uint8_t servo_num) {
	Disable_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_DISABLE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_is_enabled(Servo *servo, uint8_t servo_num, bool *ret_enabled) {
	IsEnabled_ request;
	IsEnabledResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_IS_ENABLED, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_enabled = response.enabled;



	return ret;
}

int servo_set_position(Servo *servo, uint8_t servo_num, int16_t position) {
	SetPosition_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_POSITION, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;
	request.position = leconvert_int16_to(position);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_position(Servo *servo, uint8_t servo_num, int16_t *ret_position) {
	GetPosition_ request;
	GetPositionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_POSITION, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_position = leconvert_int16_from(response.position);



	return ret;
}

int servo_get_current_position(Servo *servo, uint8_t servo_num, int16_t *ret_position) {
	GetCurrentPosition_ request;
	GetCurrentPositionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_CURRENT_POSITION, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_position = leconvert_int16_from(response.position);



	return ret;
}

int servo_set_velocity(Servo *servo, uint8_t servo_num, uint16_t velocity) {
	SetVelocity_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_VELOCITY, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;
	request.velocity = leconvert_uint16_to(velocity);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_velocity(Servo *servo, uint8_t servo_num, uint16_t *ret_velocity) {
	GetVelocity_ request;
	GetVelocityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_VELOCITY, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_velocity = leconvert_uint16_from(response.velocity);



	return ret;
}

int servo_get_current_velocity(Servo *servo, uint8_t servo_num, uint16_t *ret_velocity) {
	GetCurrentVelocity_ request;
	GetCurrentVelocityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_CURRENT_VELOCITY, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_velocity = leconvert_uint16_from(response.velocity);



	return ret;
}

int servo_set_acceleration(Servo *servo, uint8_t servo_num, uint16_t acceleration) {
	SetAcceleration_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_ACCELERATION, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;
	request.acceleration = leconvert_uint16_to(acceleration);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_acceleration(Servo *servo, uint8_t servo_num, uint16_t *ret_acceleration) {
	GetAcceleration_ request;
	GetAccelerationResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_ACCELERATION, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_acceleration = leconvert_uint16_from(response.acceleration);



	return ret;
}

int servo_set_output_voltage(Servo *servo, uint16_t voltage) {
	SetOutputVoltage_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_OUTPUT_VOLTAGE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.voltage = leconvert_uint16_to(voltage);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_output_voltage(Servo *servo, uint16_t *ret_voltage) {
	GetOutputVoltage_ request;
	GetOutputVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_OUTPUT_VOLTAGE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int servo_set_pulse_width(Servo *servo, uint8_t servo_num, uint16_t min, uint16_t max) {
	SetPulseWidth_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_PULSE_WIDTH, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;
	request.min = leconvert_uint16_to(min);
	request.max = leconvert_uint16_to(max);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_pulse_width(Servo *servo, uint8_t servo_num, uint16_t *ret_min, uint16_t *ret_max) {
	GetPulseWidth_ request;
	GetPulseWidthResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_PULSE_WIDTH, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_min = leconvert_uint16_from(response.min);
	*ret_max = leconvert_uint16_from(response.max);



	return ret;
}

int servo_set_degree(Servo *servo, uint8_t servo_num, int16_t min, int16_t max) {
	SetDegree_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_DEGREE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;
	request.min = leconvert_int16_to(min);
	request.max = leconvert_int16_to(max);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_degree(Servo *servo, uint8_t servo_num, int16_t *ret_min, int16_t *ret_max) {
	GetDegree_ request;
	GetDegreeResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_DEGREE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_min = leconvert_int16_from(response.min);
	*ret_max = leconvert_int16_from(response.max);



	return ret;
}

int servo_set_period(Servo *servo, uint8_t servo_num, uint16_t period) {
	SetPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_PERIOD, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;
	request.period = leconvert_uint16_to(period);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_period(Servo *servo, uint8_t servo_num, uint16_t *ret_period) {
	GetPeriod_ request;
	GetPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_PERIOD, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint16_from(response.period);



	return ret;
}

int servo_get_servo_current(Servo *servo, uint8_t servo_num, uint16_t *ret_current) {
	GetServoCurrent_ request;
	GetServoCurrentResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_SERVO_CURRENT, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.servo_num = servo_num;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_current = leconvert_uint16_from(response.current);



	return ret;
}

int servo_get_overall_current(Servo *servo, uint16_t *ret_current) {
	GetOverallCurrent_ request;
	GetOverallCurrentResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_OVERALL_CURRENT, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_current = leconvert_uint16_from(response.current);



	return ret;
}

int servo_get_stack_input_voltage(Servo *servo, uint16_t *ret_voltage) {
	GetStackInputVoltage_ request;
	GetStackInputVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_STACK_INPUT_VOLTAGE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int servo_get_external_input_voltage(Servo *servo, uint16_t *ret_voltage) {
	GetExternalInputVoltage_ request;
	GetExternalInputVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int servo_set_minimum_voltage(Servo *servo, uint16_t voltage) {
	SetMinimumVoltage_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_SET_MINIMUM_VOLTAGE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.voltage = leconvert_uint16_to(voltage);

	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_minimum_voltage(Servo *servo, uint16_t *ret_voltage) {
	GetMinimumVoltage_ request;
	GetMinimumVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_MINIMUM_VOLTAGE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int servo_enable_position_reached_callback(Servo *servo) {
	EnablePositionReachedCallback_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_ENABLE_POSITION_REACHED_CALLBACK, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_disable_position_reached_callback(Servo *servo) {
	DisablePositionReachedCallback_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_DISABLE_POSITION_REACHED_CALLBACK, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_is_position_reached_callback_enabled(Servo *servo, uint8_t *ret_enabled) {
	IsPositionReachedCallbackEnabled_ request;
	IsPositionReachedCallbackEnabledResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_IS_POSITION_REACHED_CALLBACK_ENABLED, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_enabled = response.enabled;



	return ret;
}

int servo_enable_velocity_reached_callback(Servo *servo) {
	EnableVelocityReachedCallback_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_ENABLE_VELOCITY_REACHED_CALLBACK, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_disable_velocity_reached_callback(Servo *servo) {
	DisableVelocityReachedCallback_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_DISABLE_VELOCITY_REACHED_CALLBACK, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_is_velocity_reached_callback_enabled(Servo *servo, uint8_t *ret_enabled) {
	IsVelocityReachedCallbackEnabled_ request;
	IsVelocityReachedCallbackEnabledResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_IS_VELOCITY_REACHED_CALLBACK_ENABLED, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_enabled = response.enabled;



	return ret;
}

int servo_get_protocol1_bricklet_name(Servo *servo, char port, uint8_t *ret_protocol_version, uint8_t ret_firmware_version[3], char ret_name[40]) {
	GetProtocol1BrickletName_ request;
	GetProtocol1BrickletNameResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_PROTOCOL1_BRICKLET_NAME, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}

	request.port = port;

	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_protocol_version = response.protocol_version;
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	strncpy(ret_name, response.name, 40);



	return ret;
}

int servo_get_chip_temperature(Servo *servo, int16_t *ret_temperature) {
	GetChipTemperature_ request;
	GetChipTemperatureResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_CHIP_TEMPERATURE, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_temperature = leconvert_int16_from(response.temperature);



	return ret;
}

int servo_reset(Servo *servo) {
	Reset_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_RESET, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, NULL);


	return ret;
}

int servo_get_identity(Servo *servo, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), SERVO_FUNCTION_GET_IDENTITY, servo->ipcon, servo);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(servo, (Packet *)&request, (Packet *)&response);

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
