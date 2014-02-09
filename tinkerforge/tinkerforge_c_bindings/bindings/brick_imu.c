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

#include "brick_imu.h"

#include <string.h>



typedef void (*AccelerationCallbackFunction)(int16_t, int16_t, int16_t, void *);

typedef void (*MagneticFieldCallbackFunction)(int16_t, int16_t, int16_t, void *);

typedef void (*AngularVelocityCallbackFunction)(int16_t, int16_t, int16_t, void *);

typedef void (*AllDataCallbackFunction)(int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, int16_t, void *);

typedef void (*OrientationCallbackFunction)(int16_t, int16_t, int16_t, void *);

typedef void (*QuaternionCallbackFunction)(float, float, float, float, void *);

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
} ATTRIBUTE_PACKED GetAcceleration_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED GetAccelerationResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMagneticField_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED GetMagneticFieldResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAngularVelocity_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED GetAngularVelocityResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAllData_;

typedef struct {
	PacketHeader header;
	int16_t acc_x;
	int16_t acc_y;
	int16_t acc_z;
	int16_t mag_x;
	int16_t mag_y;
	int16_t mag_z;
	int16_t ang_x;
	int16_t ang_y;
	int16_t ang_z;
	int16_t temperature;
} ATTRIBUTE_PACKED GetAllDataResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetOrientation_;

typedef struct {
	PacketHeader header;
	int16_t roll;
	int16_t pitch;
	int16_t yaw;
} ATTRIBUTE_PACKED GetOrientationResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetQuaternion_;

typedef struct {
	PacketHeader header;
	float x;
	float y;
	float z;
	float w;
} ATTRIBUTE_PACKED GetQuaternionResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetIMUTemperature_;

typedef struct {
	PacketHeader header;
	int16_t temperature;
} ATTRIBUTE_PACKED GetIMUTemperatureResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED LedsOn_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED LedsOff_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED AreLedsOn_;

typedef struct {
	PacketHeader header;
	bool leds;
} ATTRIBUTE_PACKED AreLedsOnResponse_;

typedef struct {
	PacketHeader header;
	uint8_t range;
} ATTRIBUTE_PACKED SetAccelerationRange_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAccelerationRange_;

typedef struct {
	PacketHeader header;
	uint8_t range;
} ATTRIBUTE_PACKED GetAccelerationRangeResponse_;

typedef struct {
	PacketHeader header;
	uint8_t range;
} ATTRIBUTE_PACKED SetMagnetometerRange_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMagnetometerRange_;

typedef struct {
	PacketHeader header;
	uint8_t range;
} ATTRIBUTE_PACKED GetMagnetometerRangeResponse_;

typedef struct {
	PacketHeader header;
	uint16_t speed;
} ATTRIBUTE_PACKED SetConvergenceSpeed_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetConvergenceSpeed_;

typedef struct {
	PacketHeader header;
	uint16_t speed;
} ATTRIBUTE_PACKED GetConvergenceSpeedResponse_;

typedef struct {
	PacketHeader header;
	uint8_t typ;
	int16_t data[10];
} ATTRIBUTE_PACKED SetCalibration_;

typedef struct {
	PacketHeader header;
	uint8_t typ;
} ATTRIBUTE_PACKED GetCalibration_;

typedef struct {
	PacketHeader header;
	int16_t data[10];
} ATTRIBUTE_PACKED GetCalibrationResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetAccelerationPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAccelerationPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetAccelerationPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetMagneticFieldPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMagneticFieldPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetMagneticFieldPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetAngularVelocityPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAngularVelocityPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetAngularVelocityPeriodResponse_;

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
	uint32_t period;
} ATTRIBUTE_PACKED SetOrientationPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetOrientationPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetOrientationPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetQuaternionPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetQuaternionPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetQuaternionPeriodResponse_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED AccelerationCallback_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED MagneticFieldCallback_;

typedef struct {
	PacketHeader header;
	int16_t x;
	int16_t y;
	int16_t z;
} ATTRIBUTE_PACKED AngularVelocityCallback_;

typedef struct {
	PacketHeader header;
	int16_t acc_x;
	int16_t acc_y;
	int16_t acc_z;
	int16_t mag_x;
	int16_t mag_y;
	int16_t mag_z;
	int16_t ang_x;
	int16_t ang_y;
	int16_t ang_z;
	int16_t temperature;
} ATTRIBUTE_PACKED AllDataCallback_;

typedef struct {
	PacketHeader header;
	int16_t roll;
	int16_t pitch;
	int16_t yaw;
} ATTRIBUTE_PACKED OrientationCallback_;

typedef struct {
	PacketHeader header;
	float x;
	float y;
	float z;
	float w;
} ATTRIBUTE_PACKED QuaternionCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED OrientationCalculationOn_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED OrientationCalculationOff_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED IsOrientationCalculationOn_;

typedef struct {
	PacketHeader header;
	bool orientation_calculation_on;
} ATTRIBUTE_PACKED IsOrientationCalculationOnResponse_;

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

static void imu_callback_wrapper_acceleration(IMU *imu, Packet *packet) {
	AccelerationCallbackFunction callback_function = (AccelerationCallbackFunction)imu->registered_callbacks[IMU_CALLBACK_ACCELERATION];
	void *user_data = imu->registered_callback_user_data[IMU_CALLBACK_ACCELERATION];
	AccelerationCallback_ *callback = (AccelerationCallback_ *)packet;

	callback->x = leconvert_int16_from(callback->x);
	callback->y = leconvert_int16_from(callback->y);
	callback->z = leconvert_int16_from(callback->z);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, callback->z, user_data);
	}
}

static void imu_callback_wrapper_magnetic_field(IMU *imu, Packet *packet) {
	MagneticFieldCallbackFunction callback_function = (MagneticFieldCallbackFunction)imu->registered_callbacks[IMU_CALLBACK_MAGNETIC_FIELD];
	void *user_data = imu->registered_callback_user_data[IMU_CALLBACK_MAGNETIC_FIELD];
	MagneticFieldCallback_ *callback = (MagneticFieldCallback_ *)packet;

	callback->x = leconvert_int16_from(callback->x);
	callback->y = leconvert_int16_from(callback->y);
	callback->z = leconvert_int16_from(callback->z);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, callback->z, user_data);
	}
}

static void imu_callback_wrapper_angular_velocity(IMU *imu, Packet *packet) {
	AngularVelocityCallbackFunction callback_function = (AngularVelocityCallbackFunction)imu->registered_callbacks[IMU_CALLBACK_ANGULAR_VELOCITY];
	void *user_data = imu->registered_callback_user_data[IMU_CALLBACK_ANGULAR_VELOCITY];
	AngularVelocityCallback_ *callback = (AngularVelocityCallback_ *)packet;

	callback->x = leconvert_int16_from(callback->x);
	callback->y = leconvert_int16_from(callback->y);
	callback->z = leconvert_int16_from(callback->z);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, callback->z, user_data);
	}
}

static void imu_callback_wrapper_all_data(IMU *imu, Packet *packet) {
	AllDataCallbackFunction callback_function = (AllDataCallbackFunction)imu->registered_callbacks[IMU_CALLBACK_ALL_DATA];
	void *user_data = imu->registered_callback_user_data[IMU_CALLBACK_ALL_DATA];
	AllDataCallback_ *callback = (AllDataCallback_ *)packet;

	callback->acc_x = leconvert_int16_from(callback->acc_x);
	callback->acc_y = leconvert_int16_from(callback->acc_y);
	callback->acc_z = leconvert_int16_from(callback->acc_z);
	callback->mag_x = leconvert_int16_from(callback->mag_x);
	callback->mag_y = leconvert_int16_from(callback->mag_y);
	callback->mag_z = leconvert_int16_from(callback->mag_z);
	callback->ang_x = leconvert_int16_from(callback->ang_x);
	callback->ang_y = leconvert_int16_from(callback->ang_y);
	callback->ang_z = leconvert_int16_from(callback->ang_z);
	callback->temperature = leconvert_int16_from(callback->temperature);

	if (callback_function != NULL) {
		callback_function(callback->acc_x, callback->acc_y, callback->acc_z, callback->mag_x, callback->mag_y, callback->mag_z, callback->ang_x, callback->ang_y, callback->ang_z, callback->temperature, user_data);
	}
}

static void imu_callback_wrapper_orientation(IMU *imu, Packet *packet) {
	OrientationCallbackFunction callback_function = (OrientationCallbackFunction)imu->registered_callbacks[IMU_CALLBACK_ORIENTATION];
	void *user_data = imu->registered_callback_user_data[IMU_CALLBACK_ORIENTATION];
	OrientationCallback_ *callback = (OrientationCallback_ *)packet;

	callback->roll = leconvert_int16_from(callback->roll);
	callback->pitch = leconvert_int16_from(callback->pitch);
	callback->yaw = leconvert_int16_from(callback->yaw);

	if (callback_function != NULL) {
		callback_function(callback->roll, callback->pitch, callback->yaw, user_data);
	}
}

static void imu_callback_wrapper_quaternion(IMU *imu, Packet *packet) {
	QuaternionCallbackFunction callback_function = (QuaternionCallbackFunction)imu->registered_callbacks[IMU_CALLBACK_QUATERNION];
	void *user_data = imu->registered_callback_user_data[IMU_CALLBACK_QUATERNION];
	QuaternionCallback_ *callback = (QuaternionCallback_ *)packet;

	callback->x = leconvert_float_from(callback->x);
	callback->y = leconvert_float_from(callback->y);
	callback->z = leconvert_float_from(callback->z);
	callback->w = leconvert_float_from(callback->w);

	if (callback_function != NULL) {
		callback_function(callback->x, callback->y, callback->z, callback->w, user_data);
	}
}

void imu_create(IMU *imu, const char *uid, IPConnection *ipcon) {
	device_create(imu, uid, ipcon, 2, 0, 1);

	imu->response_expected[IMU_FUNCTION_GET_ACCELERATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_MAGNETIC_FIELD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_ANGULAR_VELOCITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_ALL_DATA] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_ORIENTATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_QUATERNION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_IMU_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_LEDS_ON] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_LEDS_OFF] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_ARE_LEDS_ON] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_ACCELERATION_RANGE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_GET_ACCELERATION_RANGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_MAGNETOMETER_RANGE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_GET_MAGNETOMETER_RANGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_CONVERGENCE_SPEED] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_GET_CONVERGENCE_SPEED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_CALIBRATION] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_GET_CALIBRATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_ACCELERATION_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_ACCELERATION_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_MAGNETIC_FIELD_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_MAGNETIC_FIELD_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_ANGULAR_VELOCITY_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_ANGULAR_VELOCITY_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_ALL_DATA_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_ALL_DATA_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_ORIENTATION_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_ORIENTATION_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_SET_QUATERNION_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_QUATERNION_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_CALLBACK_ACCELERATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	imu->response_expected[IMU_CALLBACK_MAGNETIC_FIELD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	imu->response_expected[IMU_CALLBACK_ANGULAR_VELOCITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	imu->response_expected[IMU_CALLBACK_ALL_DATA] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	imu->response_expected[IMU_CALLBACK_ORIENTATION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	imu->response_expected[IMU_CALLBACK_QUATERNION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	imu->response_expected[IMU_FUNCTION_ORIENTATION_CALCULATION_ON] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_ORIENTATION_CALCULATION_OFF] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_IS_ORIENTATION_CALCULATION_ON] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_PROTOCOL1_BRICKLET_NAME] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_GET_CHIP_TEMPERATURE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	imu->response_expected[IMU_FUNCTION_RESET] = DEVICE_RESPONSE_EXPECTED_FALSE;
	imu->response_expected[IMU_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	imu->callback_wrappers[IMU_CALLBACK_ACCELERATION] = (void *)imu_callback_wrapper_acceleration;
	imu->callback_wrappers[IMU_CALLBACK_MAGNETIC_FIELD] = (void *)imu_callback_wrapper_magnetic_field;
	imu->callback_wrappers[IMU_CALLBACK_ANGULAR_VELOCITY] = (void *)imu_callback_wrapper_angular_velocity;
	imu->callback_wrappers[IMU_CALLBACK_ALL_DATA] = (void *)imu_callback_wrapper_all_data;
	imu->callback_wrappers[IMU_CALLBACK_ORIENTATION] = (void *)imu_callback_wrapper_orientation;
	imu->callback_wrappers[IMU_CALLBACK_QUATERNION] = (void *)imu_callback_wrapper_quaternion;
}

void imu_destroy(IMU *imu) {
	device_destroy(imu);
}

int imu_get_response_expected(IMU *imu, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(imu, function_id, ret_response_expected);
}

int imu_set_response_expected(IMU *imu, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(imu, function_id, response_expected);
}

int imu_set_response_expected_all(IMU *imu, bool response_expected) {
	return device_set_response_expected_all(imu, response_expected);
}

void imu_register_callback(IMU *imu, uint8_t id, void *callback, void *user_data) {
	device_register_callback(imu, id, callback, user_data);
}

int imu_get_api_version(IMU *imu, uint8_t ret_api_version[3]) {
	return device_get_api_version(imu, ret_api_version);
}

int imu_get_acceleration(IMU *imu, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z) {
	GetAcceleration_ request;
	GetAccelerationResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ACCELERATION, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_x = leconvert_int16_from(response.x);
	*ret_y = leconvert_int16_from(response.y);
	*ret_z = leconvert_int16_from(response.z);



	return ret;
}

int imu_get_magnetic_field(IMU *imu, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z) {
	GetMagneticField_ request;
	GetMagneticFieldResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_MAGNETIC_FIELD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_x = leconvert_int16_from(response.x);
	*ret_y = leconvert_int16_from(response.y);
	*ret_z = leconvert_int16_from(response.z);



	return ret;
}

int imu_get_angular_velocity(IMU *imu, int16_t *ret_x, int16_t *ret_y, int16_t *ret_z) {
	GetAngularVelocity_ request;
	GetAngularVelocityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ANGULAR_VELOCITY, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_x = leconvert_int16_from(response.x);
	*ret_y = leconvert_int16_from(response.y);
	*ret_z = leconvert_int16_from(response.z);



	return ret;
}

int imu_get_all_data(IMU *imu, int16_t *ret_acc_x, int16_t *ret_acc_y, int16_t *ret_acc_z, int16_t *ret_mag_x, int16_t *ret_mag_y, int16_t *ret_mag_z, int16_t *ret_ang_x, int16_t *ret_ang_y, int16_t *ret_ang_z, int16_t *ret_temperature) {
	GetAllData_ request;
	GetAllDataResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ALL_DATA, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_acc_x = leconvert_int16_from(response.acc_x);
	*ret_acc_y = leconvert_int16_from(response.acc_y);
	*ret_acc_z = leconvert_int16_from(response.acc_z);
	*ret_mag_x = leconvert_int16_from(response.mag_x);
	*ret_mag_y = leconvert_int16_from(response.mag_y);
	*ret_mag_z = leconvert_int16_from(response.mag_z);
	*ret_ang_x = leconvert_int16_from(response.ang_x);
	*ret_ang_y = leconvert_int16_from(response.ang_y);
	*ret_ang_z = leconvert_int16_from(response.ang_z);
	*ret_temperature = leconvert_int16_from(response.temperature);



	return ret;
}

int imu_get_orientation(IMU *imu, int16_t *ret_roll, int16_t *ret_pitch, int16_t *ret_yaw) {
	GetOrientation_ request;
	GetOrientationResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ORIENTATION, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_roll = leconvert_int16_from(response.roll);
	*ret_pitch = leconvert_int16_from(response.pitch);
	*ret_yaw = leconvert_int16_from(response.yaw);



	return ret;
}

int imu_get_quaternion(IMU *imu, float *ret_x, float *ret_y, float *ret_z, float *ret_w) {
	GetQuaternion_ request;
	GetQuaternionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_QUATERNION, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_x = leconvert_float_from(response.x);
	*ret_y = leconvert_float_from(response.y);
	*ret_z = leconvert_float_from(response.z);
	*ret_w = leconvert_float_from(response.w);



	return ret;
}

int imu_get_imu_temperature(IMU *imu, int16_t *ret_temperature) {
	GetIMUTemperature_ request;
	GetIMUTemperatureResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_IMU_TEMPERATURE, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_temperature = leconvert_int16_from(response.temperature);



	return ret;
}

int imu_leds_on(IMU *imu) {
	LedsOn_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_LEDS_ON, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_leds_off(IMU *imu) {
	LedsOff_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_LEDS_OFF, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_are_leds_on(IMU *imu, bool *ret_leds) {
	AreLedsOn_ request;
	AreLedsOnResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_ARE_LEDS_ON, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_leds = response.leds;



	return ret;
}

int imu_set_acceleration_range(IMU *imu, uint8_t range) {
	SetAccelerationRange_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_ACCELERATION_RANGE, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.range = range;

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_acceleration_range(IMU *imu, uint8_t *ret_range) {
	GetAccelerationRange_ request;
	GetAccelerationRangeResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ACCELERATION_RANGE, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_range = response.range;



	return ret;
}

int imu_set_magnetometer_range(IMU *imu, uint8_t range) {
	SetMagnetometerRange_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_MAGNETOMETER_RANGE, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.range = range;

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_magnetometer_range(IMU *imu, uint8_t *ret_range) {
	GetMagnetometerRange_ request;
	GetMagnetometerRangeResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_MAGNETOMETER_RANGE, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_range = response.range;



	return ret;
}

int imu_set_convergence_speed(IMU *imu, uint16_t speed) {
	SetConvergenceSpeed_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_CONVERGENCE_SPEED, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.speed = leconvert_uint16_to(speed);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_convergence_speed(IMU *imu, uint16_t *ret_speed) {
	GetConvergenceSpeed_ request;
	GetConvergenceSpeedResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_CONVERGENCE_SPEED, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_speed = leconvert_uint16_from(response.speed);



	return ret;
}

int imu_set_calibration(IMU *imu, uint8_t typ, int16_t data[10]) {
	SetCalibration_ request;
	int ret;
	int i;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_CALIBRATION, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.typ = typ;
	for (i = 0; i < 10; i++) request.data[i] = leconvert_int16_to(data[i]);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_calibration(IMU *imu, uint8_t typ, int16_t ret_data[10]) {
	GetCalibration_ request;
	GetCalibrationResponse_ response;
	int ret;
	int i;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_CALIBRATION, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.typ = typ;

	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	for (i = 0; i < 10; i++) ret_data[i] = leconvert_int16_from(response.data[i]);



	return ret;
}

int imu_set_acceleration_period(IMU *imu, uint32_t period) {
	SetAccelerationPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_ACCELERATION_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_acceleration_period(IMU *imu, uint32_t *ret_period) {
	GetAccelerationPeriod_ request;
	GetAccelerationPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ACCELERATION_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int imu_set_magnetic_field_period(IMU *imu, uint32_t period) {
	SetMagneticFieldPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_MAGNETIC_FIELD_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_magnetic_field_period(IMU *imu, uint32_t *ret_period) {
	GetMagneticFieldPeriod_ request;
	GetMagneticFieldPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_MAGNETIC_FIELD_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int imu_set_angular_velocity_period(IMU *imu, uint32_t period) {
	SetAngularVelocityPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_ANGULAR_VELOCITY_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_angular_velocity_period(IMU *imu, uint32_t *ret_period) {
	GetAngularVelocityPeriod_ request;
	GetAngularVelocityPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ANGULAR_VELOCITY_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int imu_set_all_data_period(IMU *imu, uint32_t period) {
	SetAllDataPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_ALL_DATA_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_all_data_period(IMU *imu, uint32_t *ret_period) {
	GetAllDataPeriod_ request;
	GetAllDataPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ALL_DATA_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int imu_set_orientation_period(IMU *imu, uint32_t period) {
	SetOrientationPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_ORIENTATION_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_orientation_period(IMU *imu, uint32_t *ret_period) {
	GetOrientationPeriod_ request;
	GetOrientationPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_ORIENTATION_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int imu_set_quaternion_period(IMU *imu, uint32_t period) {
	SetQuaternionPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_SET_QUATERNION_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_quaternion_period(IMU *imu, uint32_t *ret_period) {
	GetQuaternionPeriod_ request;
	GetQuaternionPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_QUATERNION_PERIOD, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int imu_orientation_calculation_on(IMU *imu) {
	OrientationCalculationOn_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_ORIENTATION_CALCULATION_ON, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_orientation_calculation_off(IMU *imu) {
	OrientationCalculationOff_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_ORIENTATION_CALCULATION_OFF, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_is_orientation_calculation_on(IMU *imu, bool *ret_orientation_calculation_on) {
	IsOrientationCalculationOn_ request;
	IsOrientationCalculationOnResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_IS_ORIENTATION_CALCULATION_ON, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_orientation_calculation_on = response.orientation_calculation_on;



	return ret;
}

int imu_get_protocol1_bricklet_name(IMU *imu, char port, uint8_t *ret_protocol_version, uint8_t ret_firmware_version[3], char ret_name[40]) {
	GetProtocol1BrickletName_ request;
	GetProtocol1BrickletNameResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_PROTOCOL1_BRICKLET_NAME, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}

	request.port = port;

	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_protocol_version = response.protocol_version;
	memcpy(ret_firmware_version, response.firmware_version, 3 * sizeof(uint8_t));
	strncpy(ret_name, response.name, 40);



	return ret;
}

int imu_get_chip_temperature(IMU *imu, int16_t *ret_temperature) {
	GetChipTemperature_ request;
	GetChipTemperatureResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_CHIP_TEMPERATURE, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_temperature = leconvert_int16_from(response.temperature);



	return ret;
}

int imu_reset(IMU *imu) {
	Reset_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_RESET, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, NULL);


	return ret;
}

int imu_get_identity(IMU *imu, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), IMU_FUNCTION_GET_IDENTITY, imu->ipcon, imu);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(imu, (Packet *)&request, (Packet *)&response);

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
