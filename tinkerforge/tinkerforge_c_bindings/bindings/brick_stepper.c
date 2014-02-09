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

#include "brick_stepper.h"

#include <string.h>



typedef void (*UnderVoltageCallbackFunction)(uint16_t, void *);

typedef void (*PositionReachedCallbackFunction)(int32_t, void *);

typedef void (*AllDataCallbackFunction)(uint16_t, int32_t, int32_t, uint16_t, uint16_t, uint16_t, void *);

typedef void (*NewStateCallbackFunction)(uint8_t, uint8_t, void *);

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
	uint16_t velocity;
} ATTRIBUTE_PACKED SetMaxVelocity_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMaxVelocity_;

typedef struct {
	PacketHeader header;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetMaxVelocityResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetCurrentVelocity_;

typedef struct {
	PacketHeader header;
	uint16_t velocity;
} ATTRIBUTE_PACKED GetCurrentVelocityResponse_;

typedef struct {
	PacketHeader header;
	uint16_t acceleration;
	uint16_t deacceleration;
} ATTRIBUTE_PACKED SetSpeedRamping_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetSpeedRamping_;

typedef struct {
	PacketHeader header;
	uint16_t acceleration;
	uint16_t deacceleration;
} ATTRIBUTE_PACKED GetSpeedRampingResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED FullBrake_;

typedef struct {
	PacketHeader header;
	int32_t position;
} ATTRIBUTE_PACKED SetCurrentPosition_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetCurrentPosition_;

typedef struct {
	PacketHeader header;
	int32_t position;
} ATTRIBUTE_PACKED GetCurrentPositionResponse_;

typedef struct {
	PacketHeader header;
	int32_t position;
} ATTRIBUTE_PACKED SetTargetPosition_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetTargetPosition_;

typedef struct {
	PacketHeader header;
	int32_t position;
} ATTRIBUTE_PACKED GetTargetPositionResponse_;

typedef struct {
	PacketHeader header;
	int32_t steps;
} ATTRIBUTE_PACKED SetSteps_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetSteps_;

typedef struct {
	PacketHeader header;
	int32_t steps;
} ATTRIBUTE_PACKED GetStepsResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetRemainingSteps_;

typedef struct {
	PacketHeader header;
	int32_t steps;
} ATTRIBUTE_PACKED GetRemainingStepsResponse_;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED SetStepMode_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetStepMode_;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED GetStepModeResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED DriveForward_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED DriveBackward_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Stop_;

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
} ATTRIBUTE_PACKED GetCurrentConsumption_;

typedef struct {
	PacketHeader header;
	uint16_t current;
} ATTRIBUTE_PACKED GetCurrentConsumptionResponse_;

typedef struct {
	PacketHeader header;
	uint16_t current;
} ATTRIBUTE_PACKED SetMotorCurrent_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMotorCurrent_;

typedef struct {
	PacketHeader header;
	uint16_t current;
} ATTRIBUTE_PACKED GetMotorCurrentResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Enable_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED Disable_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED IsEnabled_;

typedef struct {
	PacketHeader header;
	bool enabled;
} ATTRIBUTE_PACKED IsEnabledResponse_;

typedef struct {
	PacketHeader header;
	uint16_t decay;
} ATTRIBUTE_PACKED SetDecay_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDecay_;

typedef struct {
	PacketHeader header;
	uint16_t decay;
} ATTRIBUTE_PACKED GetDecayResponse_;

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
	int32_t position;
} ATTRIBUTE_PACKED PositionReachedCallback_;

typedef struct {
	PacketHeader header;
	bool sync_rect;
} ATTRIBUTE_PACKED SetSyncRect_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED IsSyncRect_;

typedef struct {
	PacketHeader header;
	bool sync_rect;
} ATTRIBUTE_PACKED IsSyncRectResponse_;

typedef struct {
	PacketHeader header;
	uint32_t time_base;
} ATTRIBUTE_PACKED SetTimeBase_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetTimeBase_;

typedef struct {
	PacketHeader header;
	uint32_t time_base;
} ATTRIBUTE_PACKED GetTimeBaseResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAllData_;

typedef struct {
	PacketHeader header;
	uint16_t current_velocity;
	int32_t current_position;
	int32_t remaining_steps;
	uint16_t stack_voltage;
	uint16_t external_voltage;
	uint16_t current_consumption;
} ATTRIBUTE_PACKED GetAllDataResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetAllDataPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAllDataPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetAllDataPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint16_t current_velocity;
	int32_t current_position;
	int32_t remaining_steps;
	uint16_t stack_voltage;
	uint16_t external_voltage;
	uint16_t current_consumption;
} ATTRIBUTE_PACKED AllDataCallback_;

typedef struct {
	PacketHeader header;
	uint8_t state_new;
	uint8_t state_previous;
} ATTRIBUTE_PACKED NewStateCallback_;

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

static void stepper_callback_wrapper_under_voltage(Stepper *stepper, Packet *packet) {
	UnderVoltageCallbackFunction callback_function = (UnderVoltageCallbackFunction)stepper->registered_callbacks[STEPPER_CALLBACK_UNDER_VOLTAGE];
	void *user_data = stepper->registered_callback_user_data[STEPPER_CALLBACK_UNDER_VOLTAGE];
	UnderVoltageCallback_ *callback = (UnderVoltageCallback_ *)packet;

	callback->voltage = leconvert_uint16_from(callback->voltage);

	if (callback_function != NULL) {
		callback_function(callback->voltage, user_data);
	}
}

static void stepper_callback_wrapper_position_reached(Stepper *stepper, Packet *packet) {
	PositionReachedCallbackFunction callback_function = (PositionReachedCallbackFunction)stepper->registered_callbacks[STEPPER_CALLBACK_POSITION_REACHED];
	void *user_data = stepper->registered_callback_user_data[STEPPER_CALLBACK_POSITION_REACHED];
	PositionReachedCallback_ *callback = (PositionReachedCallback_ *)packet;

	callback->position = leconvert_int32_from(callback->position);

	if (callback_function != NULL) {
		callback_function(callback->position, user_data);
	}
}

static void stepper_callback_wrapper_all_data(Stepper *stepper, Packet *packet) {
	AllDataCallbackFunction callback_function = (AllDataCallbackFunction)stepper->registered_callbacks[STEPPER_CALLBACK_ALL_DATA];
	void *user_data = stepper->registered_callback_user_data[STEPPER_CALLBACK_ALL_DATA];
	AllDataCallback_ *callback = (AllDataCallback_ *)packet;

	callback->current_velocity = leconvert_uint16_from(callback->current_velocity);
	callback->current_position = leconvert_int32_from(callback->current_position);
	callback->remaining_steps = leconvert_int32_from(callback->remaining_steps);
	callback->stack_voltage = leconvert_uint16_from(callback->stack_voltage);
	callback->external_voltage = leconvert_uint16_from(callback->external_voltage);
	callback->current_consumption = leconvert_uint16_from(callback->current_consumption);

	if (callback_function != NULL) {
		callback_function(callback->current_velocity, callback->current_position, callback->remaining_steps, callback->stack_voltage, callback->external_voltage, callback->current_consumption, user_data);
	}
}

static void stepper_callback_wrapper_new_state(Stepper *stepper, Packet *packet) {
	NewStateCallbackFunction callback_function = (NewStateCallbackFunction)stepper->registered_callbacks[STEPPER_CALLBACK_NEW_STATE];
	void *user_data = stepper->registered_callback_user_data[STEPPER_CALLBACK_NEW_STATE];
	NewStateCallback_ *callback = (NewStateCallback_ *)packet;

	if (callback_function != NULL) {
		callback_function(callback->state_new, callback->state_previous, user_data);
	}
}

void stepper_create(Stepper *stepper, const char *uid, IPConnection *ipcon) {
	device_create(stepper, uid, ipcon, 2, 0, 0);

	stepper->response_expected[STEPPER_FUNCTION_SET_MAX_VELOCITY] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_MAX_VELOCITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_CURRENT_VELOCITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_SPEED_RAMPING] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_SPEED_RAMPING] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_FULL_BRAKE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_SET_CURRENT_POSITION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_CURRENT_POSITION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_TARGET_POSITION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_TARGET_POSITION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_STEPS] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_STEPS] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_REMAINING_STEPS] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_STEP_MODE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_STEP_MODE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_DRIVE_FORWARD] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_DRIVE_BACKWARD] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_STOP] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_STACK_INPUT_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_CURRENT_CONSUMPTION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_MOTOR_CURRENT] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_MOTOR_CURRENT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_ENABLE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_DISABLE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_IS_ENABLED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_DECAY] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_DECAY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_MINIMUM_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_MINIMUM_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_CALLBACK_UNDER_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	stepper->response_expected[STEPPER_CALLBACK_POSITION_REACHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_SET_SYNC_RECT] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_IS_SYNC_RECT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_TIME_BASE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_TIME_BASE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_ALL_DATA] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_SET_ALL_DATA_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_ALL_DATA_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_CALLBACK_ALL_DATA] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	stepper->response_expected[STEPPER_CALLBACK_NEW_STATE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_PROTOCOL1_BRICKLET_NAME] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_GET_CHIP_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	stepper->response_expected[STEPPER_FUNCTION_RESET] = DEVICE_RESPONSE_EXPECTED_FALSE;
	stepper->response_expected[STEPPER_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	stepper->callback_wrappers[STEPPER_CALLBACK_UNDER_VOLTAGE] = (void *)stepper_callback_wrapper_under_voltage;
	stepper->callback_wrappers[STEPPER_CALLBACK_POSITION_REACHED] = (void *)stepper_callback_wrapper_position_reached;
	stepper->callback_wrappers[STEPPER_CALLBACK_ALL_DATA] = (void *)stepper_callback_wrapper_all_data;
	stepper->callback_wrappers[STEPPER_CALLBACK_NEW_STATE] = (void *)stepper_callback_wrapper_new_state;
}

void stepper_destroy(Stepper *stepper) {
	device_destroy(stepper);
}

int stepper_get_response_expected(Stepper *stepper, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(stepper, function_id, ret_response_expected);
}

int stepper_set_response_expected(Stepper *stepper, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(stepper, function_id, response_expected);
}

int stepper_set_response_expected_all(Stepper *stepper, bool response_expected) {
	return device_set_response_expected_all(stepper, response_expected);
}

void stepper_register_callback(Stepper *stepper, uint8_t id, void *callback, void *user_data) {
	device_register_callback(stepper, id, callback, user_data);
}

int stepper_get_api_version(Stepper *stepper, uint8_t ret_api_version[3]) {
	return device_get_api_version(stepper, ret_api_version);
}

int stepper_set_max_velocity(Stepper *stepper, uint16_t velocity) {
	SetMaxVelocity_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_MAX_VELOCITY, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.velocity = leconvert_uint16_to(velocity);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_max_velocity(Stepper *stepper, uint16_t *ret_velocity) {
	GetMaxVelocity_ request;
	GetMaxVelocityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_MAX_VELOCITY, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_velocity = leconvert_uint16_from(response.velocity);



	return ret;
}

int stepper_get_current_velocity(Stepper *stepper, uint16_t *ret_velocity) {
	GetCurrentVelocity_ request;
	GetCurrentVelocityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_CURRENT_VELOCITY, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_velocity = leconvert_uint16_from(response.velocity);



	return ret;
}

int stepper_set_speed_ramping(Stepper *stepper, uint16_t acceleration, uint16_t deacceleration) {
	SetSpeedRamping_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_SPEED_RAMPING, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.acceleration = leconvert_uint16_to(acceleration);
	request.deacceleration = leconvert_uint16_to(deacceleration);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_speed_ramping(Stepper *stepper, uint16_t *ret_acceleration, uint16_t *ret_deacceleration) {
	GetSpeedRamping_ request;
	GetSpeedRampingResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_SPEED_RAMPING, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_acceleration = leconvert_uint16_from(response.acceleration);
	*ret_deacceleration = leconvert_uint16_from(response.deacceleration);



	return ret;
}

int stepper_full_brake(Stepper *stepper) {
	FullBrake_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_FULL_BRAKE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_set_current_position(Stepper *stepper, int32_t position) {
	SetCurrentPosition_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_CURRENT_POSITION, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.position = leconvert_int32_to(position);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_current_position(Stepper *stepper, int32_t *ret_position) {
	GetCurrentPosition_ request;
	GetCurrentPositionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_CURRENT_POSITION, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_position = leconvert_int32_from(response.position);



	return ret;
}

int stepper_set_target_position(Stepper *stepper, int32_t position) {
	SetTargetPosition_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_TARGET_POSITION, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.position = leconvert_int32_to(position);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_target_position(Stepper *stepper, int32_t *ret_position) {
	GetTargetPosition_ request;
	GetTargetPositionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_TARGET_POSITION, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_position = leconvert_int32_from(response.position);



	return ret;
}

int stepper_set_steps(Stepper *stepper, int32_t steps) {
	SetSteps_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_STEPS, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.steps = leconvert_int32_to(steps);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_steps(Stepper *stepper, int32_t *ret_steps) {
	GetSteps_ request;
	GetStepsResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_STEPS, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_steps = leconvert_int32_from(response.steps);



	return ret;
}

int stepper_get_remaining_steps(Stepper *stepper, int32_t *ret_steps) {
	GetRemainingSteps_ request;
	GetRemainingStepsResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_REMAINING_STEPS, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_steps = leconvert_int32_from(response.steps);



	return ret;
}

int stepper_set_step_mode(Stepper *stepper, uint8_t mode) {
	SetStepMode_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_STEP_MODE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.mode = mode;

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_step_mode(Stepper *stepper, uint8_t *ret_mode) {
	GetStepMode_ request;
	GetStepModeResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_STEP_MODE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_mode = response.mode;



	return ret;
}

int stepper_drive_forward(Stepper *stepper) {
	DriveForward_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_DRIVE_FORWARD, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_drive_backward(Stepper *stepper) {
	DriveBackward_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_DRIVE_BACKWARD, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_stop(Stepper *stepper) {
	Stop_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_STOP, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_stack_input_voltage(Stepper *stepper, uint16_t *ret_voltage) {
	GetStackInputVoltage_ request;
	GetStackInputVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_STACK_INPUT_VOLTAGE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int stepper_get_external_input_voltage(Stepper *stepper, uint16_t *ret_voltage) {
	GetExternalInputVoltage_ request;
	GetExternalInputVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_EXTERNAL_INPUT_VOLTAGE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int stepper_get_current_consumption(Stepper *stepper, uint16_t *ret_current) {
	GetCurrentConsumption_ request;
	GetCurrentConsumptionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_CURRENT_CONSUMPTION, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_current = leconvert_uint16_from(response.current);



	return ret;
}

int stepper_set_motor_current(Stepper *stepper, uint16_t current) {
	SetMotorCurrent_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_MOTOR_CURRENT, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.current = leconvert_uint16_to(current);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_motor_current(Stepper *stepper, uint16_t *ret_current) {
	GetMotorCurrent_ request;
	GetMotorCurrentResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_MOTOR_CURRENT, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_current = leconvert_uint16_from(response.current);



	return ret;
}

int stepper_enable(Stepper *stepper) {
	Enable_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_ENABLE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_disable(Stepper *stepper) {
	Disable_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_DISABLE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_is_enabled(Stepper *stepper, bool *ret_enabled) {
	IsEnabled_ request;
	IsEnabledResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_IS_ENABLED, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_enabled = response.enabled;



	return ret;
}

int stepper_set_decay(Stepper *stepper, uint16_t decay) {
	SetDecay_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_DECAY, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.decay = leconvert_uint16_to(decay);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_decay(Stepper *stepper, uint16_t *ret_decay) {
	GetDecay_ request;
	GetDecayResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_DECAY, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_decay = leconvert_uint16_from(response.decay);



	return ret;
}

int stepper_set_minimum_voltage(Stepper *stepper, uint16_t voltage) {
	SetMinimumVoltage_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_MINIMUM_VOLTAGE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.voltage = leconvert_uint16_to(voltage);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_minimum_voltage(Stepper *stepper, uint16_t *ret_voltage) {
	GetMinimumVoltage_ request;
	GetMinimumVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_MINIMUM_VOLTAGE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int stepper_set_sync_rect(Stepper *stepper, bool sync_rect) {
	SetSyncRect_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_SYNC_RECT, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.sync_rect = sync_rect;

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_is_sync_rect(Stepper *stepper, bool *ret_sync_rect) {
	IsSyncRect_ request;
	IsSyncRectResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_IS_SYNC_RECT, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_sync_rect = response.sync_rect;



	return ret;
}

int stepper_set_time_base(Stepper *stepper, uint32_t time_base) {
	SetTimeBase_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_TIME_BASE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.time_base = leconvert_uint32_to(time_base);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_time_base(Stepper *stepper, uint32_t *ret_time_base) {
	GetTimeBase_ request;
	GetTimeBaseResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_TIME_BASE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_time_base = leconvert_uint32_from(response.time_base);



	return ret;
}

int stepper_get_all_data(Stepper *stepper, uint16_t *ret_current_velocity, int32_t *ret_current_position, int32_t *ret_remaining_steps, uint16_t *ret_stack_voltage, uint16_t *ret_external_voltage, uint16_t *ret_current_consumption) {
	GetAllData_ request;
	GetAllDataResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_ALL_DATA, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_current_velocity = leconvert_uint16_from(response.current_velocity);
	*ret_current_position = leconvert_int32_from(response.current_position);
	*ret_remaining_steps = leconvert_int32_from(response.remaining_steps);
	*ret_stack_voltage = leconvert_uint16_from(response.stack_voltage);
	*ret_external_voltage = leconvert_uint16_from(response.external_voltage);
	*ret_current_consumption = leconvert_uint16_from(response.current_consumption);



	return ret;
}

int stepper_set_all_data_period(Stepper *stepper, uint32_t period) {
	SetAllDataPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_SET_ALL_DATA_PERIOD, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_all_data_period(Stepper *stepper, uint32_t *ret_period) {
	GetAllDataPeriod_ request;
	GetAllDataPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_ALL_DATA_PERIOD, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int stepper_get_protocol1_bricklet_name(Stepper *stepper, char port, uint8_t *ret_protocol_version, uint8_t ret_firmware_version[3], char ret_name[40]) {
	GetProtocol1BrickletName_ request;
	GetProtocol1BrickletNameResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_PROTOCOL1_BRICKLET_NAME, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}

	request.port = port;

	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_protocol_version = response.protocol_version;
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	strncpy(ret_name, response.name, 40);



	return ret;
}

int stepper_get_chip_temperature(Stepper *stepper, int16_t *ret_temperature) {
	GetChipTemperature_ request;
	GetChipTemperatureResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_CHIP_TEMPERATURE, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_temperature = leconvert_int16_from(response.temperature);



	return ret;
}

int stepper_reset(Stepper *stepper) {
	Reset_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_RESET, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, NULL);


	return ret;
}

int stepper_get_identity(Stepper *stepper, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), STEPPER_FUNCTION_GET_IDENTITY, stepper->ipcon, stepper);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(stepper, (Packet *)&request, (Packet *)&response);

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
