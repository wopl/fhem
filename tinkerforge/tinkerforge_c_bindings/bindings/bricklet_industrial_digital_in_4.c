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

#include "bricklet_industrial_digital_in_4.h"

#include <string.h>



typedef void (*InterruptCallbackFunction)(uint16_t, uint16_t, void *);

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
} ATTRIBUTE_PACKED GetValue_;

typedef struct {
	PacketHeader header;
	uint16_t value_mask;
} ATTRIBUTE_PACKED GetValueResponse_;

typedef struct {
	PacketHeader header;
	char group[4];
} ATTRIBUTE_PACKED SetGroup_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetGroup_;

typedef struct {
	PacketHeader header;
	char group[4];
} ATTRIBUTE_PACKED GetGroupResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAvailableForGroup_;

typedef struct {
	PacketHeader header;
	uint8_t available;
} ATTRIBUTE_PACKED GetAvailableForGroupResponse_;

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
	uint16_t interrupt_mask;
} ATTRIBUTE_PACKED SetInterrupt_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetInterrupt_;

typedef struct {
	PacketHeader header;
	uint16_t interrupt_mask;
} ATTRIBUTE_PACKED GetInterruptResponse_;

typedef struct {
	PacketHeader header;
	uint16_t interrupt_mask;
	uint16_t value_mask;
} ATTRIBUTE_PACKED InterruptCallback_;

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

static void industrial_digital_in_4_callback_wrapper_interrupt(IndustrialDigitalIn4 *industrial_digital_in_4, Packet *packet) {
	InterruptCallbackFunction callback_function = (InterruptCallbackFunction)industrial_digital_in_4->registered_callbacks[INDUSTRIAL_DIGITAL_IN_4_CALLBACK_INTERRUPT];
	void *user_data = industrial_digital_in_4->registered_callback_user_data[INDUSTRIAL_DIGITAL_IN_4_CALLBACK_INTERRUPT];
	InterruptCallback_ *callback = (InterruptCallback_ *)packet;

	callback->interrupt_mask = leconvert_uint16_from(callback->interrupt_mask);
	callback->value_mask = leconvert_uint16_from(callback->value_mask);

	if (callback_function != NULL) {
		callback_function(callback->interrupt_mask, callback->value_mask, user_data);
	}
}

void industrial_digital_in_4_create(IndustrialDigitalIn4 *industrial_digital_in_4, const char *uid, IPConnection *ipcon) {
	device_create(industrial_digital_in_4, uid, ipcon, 2, 0, 0);

	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_VALUE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_SET_GROUP] = DEVICE_RESPONSE_EXPECTED_FALSE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_GROUP] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_AVAILABLE_FOR_GROUP] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_SET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_DEBOUNCE_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_SET_INTERRUPT] = DEVICE_RESPONSE_EXPECTED_TRUE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_INTERRUPT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_CALLBACK_INTERRUPT] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	industrial_digital_in_4->response_expected[INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	industrial_digital_in_4->callback_wrappers[INDUSTRIAL_DIGITAL_IN_4_CALLBACK_INTERRUPT] = (void *)industrial_digital_in_4_callback_wrapper_interrupt;
}

void industrial_digital_in_4_destroy(IndustrialDigitalIn4 *industrial_digital_in_4) {
	device_destroy(industrial_digital_in_4);
}

int industrial_digital_in_4_get_response_expected(IndustrialDigitalIn4 *industrial_digital_in_4, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(industrial_digital_in_4, function_id, ret_response_expected);
}

int industrial_digital_in_4_set_response_expected(IndustrialDigitalIn4 *industrial_digital_in_4, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(industrial_digital_in_4, function_id, response_expected);
}

int industrial_digital_in_4_set_response_expected_all(IndustrialDigitalIn4 *industrial_digital_in_4, bool response_expected) {
	return device_set_response_expected_all(industrial_digital_in_4, response_expected);
}

void industrial_digital_in_4_register_callback(IndustrialDigitalIn4 *industrial_digital_in_4, uint8_t id, void *callback, void *user_data) {
	device_register_callback(industrial_digital_in_4, id, callback, user_data);
}

int industrial_digital_in_4_get_api_version(IndustrialDigitalIn4 *industrial_digital_in_4, uint8_t ret_api_version[3]) {
	return device_get_api_version(industrial_digital_in_4, ret_api_version);
}

int industrial_digital_in_4_get_value(IndustrialDigitalIn4 *industrial_digital_in_4, uint16_t *ret_value_mask) {
	GetValue_ request;
	GetValueResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_VALUE, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_value_mask = leconvert_uint16_from(response.value_mask);



	return ret;
}

int industrial_digital_in_4_set_group(IndustrialDigitalIn4 *industrial_digital_in_4, char group[4]) {
	SetGroup_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_SET_GROUP, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}

	memcpy(request.group, group, 4 * sizeof(char));

	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, NULL);


	return ret;
}

int industrial_digital_in_4_get_group(IndustrialDigitalIn4 *industrial_digital_in_4, char ret_group[4]) {
	GetGroup_ request;
	GetGroupResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_GROUP, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	memcpy(ret_group, response.group, 4 * sizeof(char));



	return ret;
}

int industrial_digital_in_4_get_available_for_group(IndustrialDigitalIn4 *industrial_digital_in_4, uint8_t *ret_available) {
	GetAvailableForGroup_ request;
	GetAvailableForGroupResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_AVAILABLE_FOR_GROUP, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_available = response.available;



	return ret;
}

int industrial_digital_in_4_set_debounce_period(IndustrialDigitalIn4 *industrial_digital_in_4, uint32_t debounce) {
	SetDebouncePeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_SET_DEBOUNCE_PERIOD, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}

	request.debounce = leconvert_uint32_to(debounce);

	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, NULL);


	return ret;
}

int industrial_digital_in_4_get_debounce_period(IndustrialDigitalIn4 *industrial_digital_in_4, uint32_t *ret_debounce) {
	GetDebouncePeriod_ request;
	GetDebouncePeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_DEBOUNCE_PERIOD, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_debounce = leconvert_uint32_from(response.debounce);



	return ret;
}

int industrial_digital_in_4_set_interrupt(IndustrialDigitalIn4 *industrial_digital_in_4, uint16_t interrupt_mask) {
	SetInterrupt_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_SET_INTERRUPT, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}

	request.interrupt_mask = leconvert_uint16_to(interrupt_mask);

	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, NULL);


	return ret;
}

int industrial_digital_in_4_get_interrupt(IndustrialDigitalIn4 *industrial_digital_in_4, uint16_t *ret_interrupt_mask) {
	GetInterrupt_ request;
	GetInterruptResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_INTERRUPT, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_interrupt_mask = leconvert_uint16_from(response.interrupt_mask);



	return ret;
}

int industrial_digital_in_4_get_identity(IndustrialDigitalIn4 *industrial_digital_in_4, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), INDUSTRIAL_DIGITAL_IN_4_FUNCTION_GET_IDENTITY, industrial_digital_in_4->ipcon, industrial_digital_in_4);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(industrial_digital_in_4, (Packet *)&request, (Packet *)&response);

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
