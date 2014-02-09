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

#include "bricklet_analog_out.h"

#include <string.h>



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
	uint16_t voltage;
} ATTRIBUTE_PACKED SetVoltage_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetVoltage_;

typedef struct {
	PacketHeader header;
	uint16_t voltage;
} ATTRIBUTE_PACKED GetVoltageResponse_;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED SetMode_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMode_;

typedef struct {
	PacketHeader header;
	uint8_t mode;
} ATTRIBUTE_PACKED GetModeResponse_;

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

void analog_out_create(AnalogOut *analog_out, const char *uid, IPConnection *ipcon) {
	device_create(analog_out, uid, ipcon, 2, 0, 0);

	analog_out->response_expected[ANALOG_OUT_FUNCTION_SET_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	analog_out->response_expected[ANALOG_OUT_FUNCTION_GET_VOLTAGE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	analog_out->response_expected[ANALOG_OUT_FUNCTION_SET_MODE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	analog_out->response_expected[ANALOG_OUT_FUNCTION_GET_MODE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	analog_out->response_expected[ANALOG_OUT_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

}

void analog_out_destroy(AnalogOut *analog_out) {
	device_destroy(analog_out);
}

int analog_out_get_response_expected(AnalogOut *analog_out, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(analog_out, function_id, ret_response_expected);
}

int analog_out_set_response_expected(AnalogOut *analog_out, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(analog_out, function_id, response_expected);
}

int analog_out_set_response_expected_all(AnalogOut *analog_out, bool response_expected) {
	return device_set_response_expected_all(analog_out, response_expected);
}

void analog_out_register_callback(AnalogOut *analog_out, uint8_t id, void *callback, void *user_data) {
	device_register_callback(analog_out, id, callback, user_data);
}

int analog_out_get_api_version(AnalogOut *analog_out, uint8_t ret_api_version[3]) {
	return device_get_api_version(analog_out, ret_api_version);
}

int analog_out_set_voltage(AnalogOut *analog_out, uint16_t voltage) {
	SetVoltage_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ANALOG_OUT_FUNCTION_SET_VOLTAGE, analog_out->ipcon, analog_out);

	if (ret < 0) {
		return ret;
	}

	request.voltage = leconvert_uint16_to(voltage);

	ret = device_send_request(analog_out, (Packet *)&request, NULL);


	return ret;
}

int analog_out_get_voltage(AnalogOut *analog_out, uint16_t *ret_voltage) {
	GetVoltage_ request;
	GetVoltageResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ANALOG_OUT_FUNCTION_GET_VOLTAGE, analog_out->ipcon, analog_out);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(analog_out, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_voltage = leconvert_uint16_from(response.voltage);



	return ret;
}

int analog_out_set_mode(AnalogOut *analog_out, uint8_t mode) {
	SetMode_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ANALOG_OUT_FUNCTION_SET_MODE, analog_out->ipcon, analog_out);

	if (ret < 0) {
		return ret;
	}

	request.mode = mode;

	ret = device_send_request(analog_out, (Packet *)&request, NULL);


	return ret;
}

int analog_out_get_mode(AnalogOut *analog_out, uint8_t *ret_mode) {
	GetMode_ request;
	GetModeResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ANALOG_OUT_FUNCTION_GET_MODE, analog_out->ipcon, analog_out);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(analog_out, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_mode = response.mode;



	return ret;
}

int analog_out_get_identity(AnalogOut *analog_out, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), ANALOG_OUT_FUNCTION_GET_IDENTITY, analog_out->ipcon, analog_out);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(analog_out, (Packet *)&request, (Packet *)&response);

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
