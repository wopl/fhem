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

#include "bricklet_piezo_buzzer.h"

#include <string.h>



typedef void (*BeepFinishedCallbackFunction)(void *);

typedef void (*MorseCodeFinishedCallbackFunction)(void *);

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
	uint32_t duration;
} ATTRIBUTE_PACKED Beep_;

typedef struct {
	PacketHeader header;
	char morse[60];
} ATTRIBUTE_PACKED MorseCode_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED BeepFinishedCallback_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED MorseCodeFinishedCallback_;

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

static void piezo_buzzer_callback_wrapper_beep_finished(PiezoBuzzer *piezo_buzzer, Packet *packet) {
	BeepFinishedCallbackFunction callback_function = (BeepFinishedCallbackFunction)piezo_buzzer->registered_callbacks[PIEZO_BUZZER_CALLBACK_BEEP_FINISHED];
	void *user_data = piezo_buzzer->registered_callback_user_data[PIEZO_BUZZER_CALLBACK_BEEP_FINISHED];
	(void)packet;

	if (callback_function != NULL) {
		callback_function(user_data);
	}
}

static void piezo_buzzer_callback_wrapper_morse_code_finished(PiezoBuzzer *piezo_buzzer, Packet *packet) {
	MorseCodeFinishedCallbackFunction callback_function = (MorseCodeFinishedCallbackFunction)piezo_buzzer->registered_callbacks[PIEZO_BUZZER_CALLBACK_MORSE_CODE_FINISHED];
	void *user_data = piezo_buzzer->registered_callback_user_data[PIEZO_BUZZER_CALLBACK_MORSE_CODE_FINISHED];
	(void)packet;

	if (callback_function != NULL) {
		callback_function(user_data);
	}
}

void piezo_buzzer_create(PiezoBuzzer *piezo_buzzer, const char *uid, IPConnection *ipcon) {
	device_create(piezo_buzzer, uid, ipcon, 2, 0, 0);

	piezo_buzzer->response_expected[PIEZO_BUZZER_FUNCTION_BEEP] = DEVICE_RESPONSE_EXPECTED_FALSE;
	piezo_buzzer->response_expected[PIEZO_BUZZER_FUNCTION_MORSE_CODE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	piezo_buzzer->response_expected[PIEZO_BUZZER_CALLBACK_BEEP_FINISHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	piezo_buzzer->response_expected[PIEZO_BUZZER_CALLBACK_MORSE_CODE_FINISHED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	piezo_buzzer->response_expected[PIEZO_BUZZER_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	piezo_buzzer->callback_wrappers[PIEZO_BUZZER_CALLBACK_BEEP_FINISHED] = (void *)piezo_buzzer_callback_wrapper_beep_finished;
	piezo_buzzer->callback_wrappers[PIEZO_BUZZER_CALLBACK_MORSE_CODE_FINISHED] = (void *)piezo_buzzer_callback_wrapper_morse_code_finished;
}

void piezo_buzzer_destroy(PiezoBuzzer *piezo_buzzer) {
	device_destroy(piezo_buzzer);
}

int piezo_buzzer_get_response_expected(PiezoBuzzer *piezo_buzzer, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(piezo_buzzer, function_id, ret_response_expected);
}

int piezo_buzzer_set_response_expected(PiezoBuzzer *piezo_buzzer, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(piezo_buzzer, function_id, response_expected);
}

int piezo_buzzer_set_response_expected_all(PiezoBuzzer *piezo_buzzer, bool response_expected) {
	return device_set_response_expected_all(piezo_buzzer, response_expected);
}

void piezo_buzzer_register_callback(PiezoBuzzer *piezo_buzzer, uint8_t id, void *callback, void *user_data) {
	device_register_callback(piezo_buzzer, id, callback, user_data);
}

int piezo_buzzer_get_api_version(PiezoBuzzer *piezo_buzzer, uint8_t ret_api_version[3]) {
	return device_get_api_version(piezo_buzzer, ret_api_version);
}

int piezo_buzzer_beep(PiezoBuzzer *piezo_buzzer, uint32_t duration) {
	Beep_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), PIEZO_BUZZER_FUNCTION_BEEP, piezo_buzzer->ipcon, piezo_buzzer);

	if (ret < 0) {
		return ret;
	}

	request.duration = leconvert_uint32_to(duration);

	ret = device_send_request(piezo_buzzer, (Packet *)&request, NULL);


	return ret;
}

int piezo_buzzer_morse_code(PiezoBuzzer *piezo_buzzer, const char morse[60]) {
	MorseCode_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), PIEZO_BUZZER_FUNCTION_MORSE_CODE, piezo_buzzer->ipcon, piezo_buzzer);

	if (ret < 0) {
		return ret;
	}

	strncpy(request.morse, morse, 60);


	ret = device_send_request(piezo_buzzer, (Packet *)&request, NULL);


	return ret;
}

int piezo_buzzer_get_identity(PiezoBuzzer *piezo_buzzer, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), PIEZO_BUZZER_FUNCTION_GET_IDENTITY, piezo_buzzer->ipcon, piezo_buzzer);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(piezo_buzzer, (Packet *)&request, (Packet *)&response);

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
