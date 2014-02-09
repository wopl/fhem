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

#include "bricklet_lcd_16x2.h"

#include <string.h>



typedef void (*ButtonPressedCallbackFunction)(uint8_t, void *);

typedef void (*ButtonReleasedCallbackFunction)(uint8_t, void *);

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
	uint8_t line;
	uint8_t position;
	char text[16];
} ATTRIBUTE_PACKED WriteLine_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED ClearDisplay_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED BacklightOn_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED BacklightOff_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED IsBacklightOn_;

typedef struct {
	PacketHeader header;
	bool backlight;
} ATTRIBUTE_PACKED IsBacklightOnResponse_;

typedef struct {
	PacketHeader header;
	bool cursor;
	bool blinking;
} ATTRIBUTE_PACKED SetConfig_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetConfig_;

typedef struct {
	PacketHeader header;
	bool cursor;
	bool blinking;
} ATTRIBUTE_PACKED GetConfigResponse_;

typedef struct {
	PacketHeader header;
	uint8_t button;
} ATTRIBUTE_PACKED IsButtonPressed_;

typedef struct {
	PacketHeader header;
	bool pressed;
} ATTRIBUTE_PACKED IsButtonPressedResponse_;

typedef struct {
	PacketHeader header;
	uint8_t button;
} ATTRIBUTE_PACKED ButtonPressedCallback_;

typedef struct {
	PacketHeader header;
	uint8_t button;
} ATTRIBUTE_PACKED ButtonReleasedCallback_;

typedef struct {
	PacketHeader header;
	uint8_t index;
	uint8_t character[8];
} ATTRIBUTE_PACKED SetCustomCharacter_;

typedef struct {
	PacketHeader header;
	uint8_t index;
} ATTRIBUTE_PACKED GetCustomCharacter_;

typedef struct {
	PacketHeader header;
	uint8_t character[8];
} ATTRIBUTE_PACKED GetCustomCharacterResponse_;

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

static void lcd_16x2_callback_wrapper_button_pressed(LCD16x2 *lcd_16x2, Packet *packet) {
	ButtonPressedCallbackFunction callback_function = (ButtonPressedCallbackFunction)lcd_16x2->registered_callbacks[LCD_16X2_CALLBACK_BUTTON_PRESSED];
	void *user_data = lcd_16x2->registered_callback_user_data[LCD_16X2_CALLBACK_BUTTON_PRESSED];
	ButtonPressedCallback_ *callback = (ButtonPressedCallback_ *)packet;

	if (callback_function != NULL) {
		callback_function(callback->button, user_data);
	}
}

static void lcd_16x2_callback_wrapper_button_released(LCD16x2 *lcd_16x2, Packet *packet) {
	ButtonReleasedCallbackFunction callback_function = (ButtonReleasedCallbackFunction)lcd_16x2->registered_callbacks[LCD_16X2_CALLBACK_BUTTON_RELEASED];
	void *user_data = lcd_16x2->registered_callback_user_data[LCD_16X2_CALLBACK_BUTTON_RELEASED];
	ButtonReleasedCallback_ *callback = (ButtonReleasedCallback_ *)packet;

	if (callback_function != NULL) {
		callback_function(callback->button, user_data);
	}
}

void lcd_16x2_create(LCD16x2 *lcd_16x2, const char *uid, IPConnection *ipcon) {
	device_create(lcd_16x2, uid, ipcon, 2, 0, 0);

	lcd_16x2->response_expected[LCD_16X2_FUNCTION_WRITE_LINE] = DEVICE_RESPONSE_EXPECTED_FALSE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_CLEAR_DISPLAY] = DEVICE_RESPONSE_EXPECTED_FALSE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_BACKLIGHT_ON] = DEVICE_RESPONSE_EXPECTED_FALSE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_BACKLIGHT_OFF] = DEVICE_RESPONSE_EXPECTED_FALSE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_IS_BACKLIGHT_ON] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_SET_CONFIG] = DEVICE_RESPONSE_EXPECTED_FALSE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_GET_CONFIG] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_IS_BUTTON_PRESSED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	lcd_16x2->response_expected[LCD_16X2_CALLBACK_BUTTON_PRESSED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	lcd_16x2->response_expected[LCD_16X2_CALLBACK_BUTTON_RELEASED] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_SET_CUSTOM_CHARACTER] = DEVICE_RESPONSE_EXPECTED_FALSE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_GET_CUSTOM_CHARACTER] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	lcd_16x2->response_expected[LCD_16X2_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	lcd_16x2->callback_wrappers[LCD_16X2_CALLBACK_BUTTON_PRESSED] = (void *)lcd_16x2_callback_wrapper_button_pressed;
	lcd_16x2->callback_wrappers[LCD_16X2_CALLBACK_BUTTON_RELEASED] = (void *)lcd_16x2_callback_wrapper_button_released;
}

void lcd_16x2_destroy(LCD16x2 *lcd_16x2) {
	device_destroy(lcd_16x2);
}

int lcd_16x2_get_response_expected(LCD16x2 *lcd_16x2, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(lcd_16x2, function_id, ret_response_expected);
}

int lcd_16x2_set_response_expected(LCD16x2 *lcd_16x2, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(lcd_16x2, function_id, response_expected);
}

int lcd_16x2_set_response_expected_all(LCD16x2 *lcd_16x2, bool response_expected) {
	return device_set_response_expected_all(lcd_16x2, response_expected);
}

void lcd_16x2_register_callback(LCD16x2 *lcd_16x2, uint8_t id, void *callback, void *user_data) {
	device_register_callback(lcd_16x2, id, callback, user_data);
}

int lcd_16x2_get_api_version(LCD16x2 *lcd_16x2, uint8_t ret_api_version[3]) {
	return device_get_api_version(lcd_16x2, ret_api_version);
}

int lcd_16x2_write_line(LCD16x2 *lcd_16x2, uint8_t line, uint8_t position, const char text[16]) {
	WriteLine_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_WRITE_LINE, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}

	request.line = line;
	request.position = position;
	strncpy(request.text, text, 16);


	ret = device_send_request(lcd_16x2, (Packet *)&request, NULL);


	return ret;
}

int lcd_16x2_clear_display(LCD16x2 *lcd_16x2) {
	ClearDisplay_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_CLEAR_DISPLAY, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(lcd_16x2, (Packet *)&request, NULL);


	return ret;
}

int lcd_16x2_backlight_on(LCD16x2 *lcd_16x2) {
	BacklightOn_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_BACKLIGHT_ON, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(lcd_16x2, (Packet *)&request, NULL);


	return ret;
}

int lcd_16x2_backlight_off(LCD16x2 *lcd_16x2) {
	BacklightOff_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_BACKLIGHT_OFF, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(lcd_16x2, (Packet *)&request, NULL);


	return ret;
}

int lcd_16x2_is_backlight_on(LCD16x2 *lcd_16x2, bool *ret_backlight) {
	IsBacklightOn_ request;
	IsBacklightOnResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_IS_BACKLIGHT_ON, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(lcd_16x2, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_backlight = response.backlight;



	return ret;
}

int lcd_16x2_set_config(LCD16x2 *lcd_16x2, bool cursor, bool blinking) {
	SetConfig_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_SET_CONFIG, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}

	request.cursor = cursor;
	request.blinking = blinking;

	ret = device_send_request(lcd_16x2, (Packet *)&request, NULL);


	return ret;
}

int lcd_16x2_get_config(LCD16x2 *lcd_16x2, bool *ret_cursor, bool *ret_blinking) {
	GetConfig_ request;
	GetConfigResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_GET_CONFIG, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(lcd_16x2, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_cursor = response.cursor;
	*ret_blinking = response.blinking;



	return ret;
}

int lcd_16x2_is_button_pressed(LCD16x2 *lcd_16x2, uint8_t button, bool *ret_pressed) {
	IsButtonPressed_ request;
	IsButtonPressedResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_IS_BUTTON_PRESSED, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}

	request.button = button;

	ret = device_send_request(lcd_16x2, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_pressed = response.pressed;



	return ret;
}

int lcd_16x2_set_custom_character(LCD16x2 *lcd_16x2, uint8_t index, uint8_t character[8]) {
	SetCustomCharacter_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_SET_CUSTOM_CHARACTER, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}

	request.index = index;
	memcpy(request.character, character, 8 * sizeof(uint8_t));

	ret = device_send_request(lcd_16x2, (Packet *)&request, NULL);


	return ret;
}

int lcd_16x2_get_custom_character(LCD16x2 *lcd_16x2, uint8_t index, uint8_t ret_character[8]) {
	GetCustomCharacter_ request;
	GetCustomCharacterResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_GET_CUSTOM_CHARACTER, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}

	request.index = index;

	ret = device_send_request(lcd_16x2, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	memcpy(ret_character, response.character, 8 * sizeof(uint8_t));



	return ret;
}

int lcd_16x2_get_identity(LCD16x2 *lcd_16x2, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), LCD_16X2_FUNCTION_GET_IDENTITY, lcd_16x2->ipcon, lcd_16x2);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(lcd_16x2, (Packet *)&request, (Packet *)&response);

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
