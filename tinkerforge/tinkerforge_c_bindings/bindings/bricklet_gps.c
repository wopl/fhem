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

#include "bricklet_gps.h"

#include <string.h>



typedef void (*CoordinatesCallbackFunction)(uint32_t, char, uint32_t, char, uint16_t, uint16_t, uint16_t, uint16_t, void *);

typedef void (*StatusCallbackFunction)(uint8_t, uint8_t, uint8_t, void *);

typedef void (*AltitudeCallbackFunction)(uint32_t, uint32_t, void *);

typedef void (*MotionCallbackFunction)(uint32_t, uint32_t, void *);

typedef void (*DateTimeCallbackFunction)(uint32_t, uint32_t, void *);

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
} ATTRIBUTE_PACKED GetCoordinates_;

typedef struct {
	PacketHeader header;
	uint32_t latitude;
	char ns;
	uint32_t longitude;
	char ew;
	uint16_t pdop;
	uint16_t hdop;
	uint16_t vdop;
	uint16_t epe;
} ATTRIBUTE_PACKED GetCoordinatesResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetStatus_;

typedef struct {
	PacketHeader header;
	uint8_t fix;
	uint8_t satellites_view;
	uint8_t satellites_used;
} ATTRIBUTE_PACKED GetStatusResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAltitude_;

typedef struct {
	PacketHeader header;
	uint32_t altitude;
	uint32_t geoidal_separation;
} ATTRIBUTE_PACKED GetAltitudeResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMotion_;

typedef struct {
	PacketHeader header;
	uint32_t course;
	uint32_t speed;
} ATTRIBUTE_PACKED GetMotionResponse_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDateTime_;

typedef struct {
	PacketHeader header;
	uint32_t date;
	uint32_t time;
} ATTRIBUTE_PACKED GetDateTimeResponse_;

typedef struct {
	PacketHeader header;
	uint8_t restart_type;
} ATTRIBUTE_PACKED Restart_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetCoordinatesCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetCoordinatesCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetCoordinatesCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetStatusCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetStatusCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetStatusCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetAltitudeCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetAltitudeCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetAltitudeCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetDateTimeCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetDateTimeCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetDateTimeCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED SetMotionCallbackPeriod_;

typedef struct {
	PacketHeader header;
} ATTRIBUTE_PACKED GetMotionCallbackPeriod_;

typedef struct {
	PacketHeader header;
	uint32_t period;
} ATTRIBUTE_PACKED GetMotionCallbackPeriodResponse_;

typedef struct {
	PacketHeader header;
	uint32_t latitude;
	char ns;
	uint32_t longitude;
	char ew;
	uint16_t pdop;
	uint16_t hdop;
	uint16_t vdop;
	uint16_t epe;
} ATTRIBUTE_PACKED CoordinatesCallback_;

typedef struct {
	PacketHeader header;
	uint8_t fix;
	uint8_t satellites_view;
	uint8_t satellites_used;
} ATTRIBUTE_PACKED StatusCallback_;

typedef struct {
	PacketHeader header;
	uint32_t altitude;
	uint32_t geoidal_separation;
} ATTRIBUTE_PACKED AltitudeCallback_;

typedef struct {
	PacketHeader header;
	uint32_t course;
	uint32_t speed;
} ATTRIBUTE_PACKED MotionCallback_;

typedef struct {
	PacketHeader header;
	uint32_t date;
	uint32_t time;
} ATTRIBUTE_PACKED DateTimeCallback_;

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

static void gps_callback_wrapper_coordinates(GPS *gps, Packet *packet) {
	CoordinatesCallbackFunction callback_function = (CoordinatesCallbackFunction)gps->registered_callbacks[GPS_CALLBACK_COORDINATES];
	void *user_data = gps->registered_callback_user_data[GPS_CALLBACK_COORDINATES];
	CoordinatesCallback_ *callback = (CoordinatesCallback_ *)packet;

	callback->latitude = leconvert_uint32_from(callback->latitude);
	callback->longitude = leconvert_uint32_from(callback->longitude);
	callback->pdop = leconvert_uint16_from(callback->pdop);
	callback->hdop = leconvert_uint16_from(callback->hdop);
	callback->vdop = leconvert_uint16_from(callback->vdop);
	callback->epe = leconvert_uint16_from(callback->epe);

	if (callback_function != NULL) {
		callback_function(callback->latitude, callback->ns, callback->longitude, callback->ew, callback->pdop, callback->hdop, callback->vdop, callback->epe, user_data);
	}
}

static void gps_callback_wrapper_status(GPS *gps, Packet *packet) {
	StatusCallbackFunction callback_function = (StatusCallbackFunction)gps->registered_callbacks[GPS_CALLBACK_STATUS];
	void *user_data = gps->registered_callback_user_data[GPS_CALLBACK_STATUS];
	StatusCallback_ *callback = (StatusCallback_ *)packet;

	if (callback_function != NULL) {
		callback_function(callback->fix, callback->satellites_view, callback->satellites_used, user_data);
	}
}

static void gps_callback_wrapper_altitude(GPS *gps, Packet *packet) {
	AltitudeCallbackFunction callback_function = (AltitudeCallbackFunction)gps->registered_callbacks[GPS_CALLBACK_ALTITUDE];
	void *user_data = gps->registered_callback_user_data[GPS_CALLBACK_ALTITUDE];
	AltitudeCallback_ *callback = (AltitudeCallback_ *)packet;

	callback->altitude = leconvert_uint32_from(callback->altitude);
	callback->geoidal_separation = leconvert_uint32_from(callback->geoidal_separation);

	if (callback_function != NULL) {
		callback_function(callback->altitude, callback->geoidal_separation, user_data);
	}
}

static void gps_callback_wrapper_motion(GPS *gps, Packet *packet) {
	MotionCallbackFunction callback_function = (MotionCallbackFunction)gps->registered_callbacks[GPS_CALLBACK_MOTION];
	void *user_data = gps->registered_callback_user_data[GPS_CALLBACK_MOTION];
	MotionCallback_ *callback = (MotionCallback_ *)packet;

	callback->course = leconvert_uint32_from(callback->course);
	callback->speed = leconvert_uint32_from(callback->speed);

	if (callback_function != NULL) {
		callback_function(callback->course, callback->speed, user_data);
	}
}

static void gps_callback_wrapper_date_time(GPS *gps, Packet *packet) {
	DateTimeCallbackFunction callback_function = (DateTimeCallbackFunction)gps->registered_callbacks[GPS_CALLBACK_DATE_TIME];
	void *user_data = gps->registered_callback_user_data[GPS_CALLBACK_DATE_TIME];
	DateTimeCallback_ *callback = (DateTimeCallback_ *)packet;

	callback->date = leconvert_uint32_from(callback->date);
	callback->time = leconvert_uint32_from(callback->time);

	if (callback_function != NULL) {
		callback_function(callback->date, callback->time, user_data);
	}
}

void gps_create(GPS *gps, const char *uid, IPConnection *ipcon) {
	device_create(gps, uid, ipcon, 2, 0, 0);

	gps->response_expected[GPS_FUNCTION_GET_COORDINATES] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_STATUS] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_ALTITUDE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_MOTION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_DATE_TIME] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_RESTART] = DEVICE_RESPONSE_EXPECTED_FALSE;
	gps->response_expected[GPS_FUNCTION_SET_COORDINATES_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_COORDINATES_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_SET_STATUS_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_STATUS_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_SET_ALTITUDE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_ALTITUDE_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_SET_DATE_TIME_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_DATE_TIME_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_FUNCTION_SET_MOTION_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_TRUE;
	gps->response_expected[GPS_FUNCTION_GET_MOTION_CALLBACK_PERIOD] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;
	gps->response_expected[GPS_CALLBACK_COORDINATES] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	gps->response_expected[GPS_CALLBACK_STATUS] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	gps->response_expected[GPS_CALLBACK_ALTITUDE] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	gps->response_expected[GPS_CALLBACK_MOTION] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	gps->response_expected[GPS_CALLBACK_DATE_TIME] = DEVICE_RESPONSE_EXPECTED_ALWAYS_FALSE;
	gps->response_expected[GPS_FUNCTION_GET_IDENTITY] = DEVICE_RESPONSE_EXPECTED_ALWAYS_TRUE;

	gps->callback_wrappers[GPS_CALLBACK_COORDINATES] = (void *)gps_callback_wrapper_coordinates;
	gps->callback_wrappers[GPS_CALLBACK_STATUS] = (void *)gps_callback_wrapper_status;
	gps->callback_wrappers[GPS_CALLBACK_ALTITUDE] = (void *)gps_callback_wrapper_altitude;
	gps->callback_wrappers[GPS_CALLBACK_MOTION] = (void *)gps_callback_wrapper_motion;
	gps->callback_wrappers[GPS_CALLBACK_DATE_TIME] = (void *)gps_callback_wrapper_date_time;
}

void gps_destroy(GPS *gps) {
	device_destroy(gps);
}

int gps_get_response_expected(GPS *gps, uint8_t function_id, bool *ret_response_expected) {
	return device_get_response_expected(gps, function_id, ret_response_expected);
}

int gps_set_response_expected(GPS *gps, uint8_t function_id, bool response_expected) {
	return device_set_response_expected(gps, function_id, response_expected);
}

int gps_set_response_expected_all(GPS *gps, bool response_expected) {
	return device_set_response_expected_all(gps, response_expected);
}

void gps_register_callback(GPS *gps, uint8_t id, void *callback, void *user_data) {
	device_register_callback(gps, id, callback, user_data);
}

int gps_get_api_version(GPS *gps, uint8_t ret_api_version[3]) {
	return device_get_api_version(gps, ret_api_version);
}

int gps_get_coordinates(GPS *gps, uint32_t *ret_latitude, char *ret_ns, uint32_t *ret_longitude, char *ret_ew, uint16_t *ret_pdop, uint16_t *ret_hdop, uint16_t *ret_vdop, uint16_t *ret_epe) {
	GetCoordinates_ request;
	GetCoordinatesResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_COORDINATES, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_latitude = leconvert_uint32_from(response.latitude);
	*ret_ns = response.ns;
	*ret_longitude = leconvert_uint32_from(response.longitude);
	*ret_ew = response.ew;
	*ret_pdop = leconvert_uint16_from(response.pdop);
	*ret_hdop = leconvert_uint16_from(response.hdop);
	*ret_vdop = leconvert_uint16_from(response.vdop);
	*ret_epe = leconvert_uint16_from(response.epe);



	return ret;
}

int gps_get_status(GPS *gps, uint8_t *ret_fix, uint8_t *ret_satellites_view, uint8_t *ret_satellites_used) {
	GetStatus_ request;
	GetStatusResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_STATUS, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_fix = response.fix;
	*ret_satellites_view = response.satellites_view;
	*ret_satellites_used = response.satellites_used;



	return ret;
}

int gps_get_altitude(GPS *gps, uint32_t *ret_altitude, uint32_t *ret_geoidal_separation) {
	GetAltitude_ request;
	GetAltitudeResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_ALTITUDE, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_altitude = leconvert_uint32_from(response.altitude);
	*ret_geoidal_separation = leconvert_uint32_from(response.geoidal_separation);



	return ret;
}

int gps_get_motion(GPS *gps, uint32_t *ret_course, uint32_t *ret_speed) {
	GetMotion_ request;
	GetMotionResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_MOTION, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_course = leconvert_uint32_from(response.course);
	*ret_speed = leconvert_uint32_from(response.speed);



	return ret;
}

int gps_get_date_time(GPS *gps, uint32_t *ret_date, uint32_t *ret_time) {
	GetDateTime_ request;
	GetDateTimeResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_DATE_TIME, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_date = leconvert_uint32_from(response.date);
	*ret_time = leconvert_uint32_from(response.time);



	return ret;
}

int gps_restart(GPS *gps, uint8_t restart_type) {
	Restart_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_RESTART, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}

	request.restart_type = restart_type;

	ret = device_send_request(gps, (Packet *)&request, NULL);


	return ret;
}

int gps_set_coordinates_callback_period(GPS *gps, uint32_t period) {
	SetCoordinatesCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_SET_COORDINATES_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(gps, (Packet *)&request, NULL);


	return ret;
}

int gps_get_coordinates_callback_period(GPS *gps, uint32_t *ret_period) {
	GetCoordinatesCallbackPeriod_ request;
	GetCoordinatesCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_COORDINATES_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int gps_set_status_callback_period(GPS *gps, uint32_t period) {
	SetStatusCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_SET_STATUS_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(gps, (Packet *)&request, NULL);


	return ret;
}

int gps_get_status_callback_period(GPS *gps, uint32_t *ret_period) {
	GetStatusCallbackPeriod_ request;
	GetStatusCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_STATUS_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int gps_set_altitude_callback_period(GPS *gps, uint32_t period) {
	SetAltitudeCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_SET_ALTITUDE_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(gps, (Packet *)&request, NULL);


	return ret;
}

int gps_get_altitude_callback_period(GPS *gps, uint32_t *ret_period) {
	GetAltitudeCallbackPeriod_ request;
	GetAltitudeCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_ALTITUDE_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int gps_set_date_time_callback_period(GPS *gps, uint32_t period) {
	SetDateTimeCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_SET_DATE_TIME_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(gps, (Packet *)&request, NULL);


	return ret;
}

int gps_get_date_time_callback_period(GPS *gps, uint32_t *ret_period) {
	GetDateTimeCallbackPeriod_ request;
	GetDateTimeCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_DATE_TIME_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int gps_set_motion_callback_period(GPS *gps, uint32_t period) {
	SetMotionCallbackPeriod_ request;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_SET_MOTION_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}

	request.period = leconvert_uint32_to(period);

	ret = device_send_request(gps, (Packet *)&request, NULL);


	return ret;
}

int gps_get_motion_callback_period(GPS *gps, uint32_t *ret_period) {
	GetMotionCallbackPeriod_ request;
	GetMotionCallbackPeriodResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_MOTION_CALLBACK_PERIOD, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

	if (ret < 0) {
		return ret;
	}
	*ret_period = leconvert_uint32_from(response.period);



	return ret;
}

int gps_get_identity(GPS *gps, char ret_uid[8], char ret_connected_uid[8], char *ret_position, uint8_t ret_hardware_version[3], uint8_t ret_firmware_version[3], uint16_t *ret_device_identifier) {
	GetIdentity_ request;
	GetIdentityResponse_ response;
	int ret;

	ret = packet_header_create(&request.header, sizeof(request), GPS_FUNCTION_GET_IDENTITY, gps->ipcon, gps);

	if (ret < 0) {
		return ret;
	}


	ret = device_send_request(gps, (Packet *)&request, (Packet *)&response);

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
