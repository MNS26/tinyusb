#ifndef _TUSB_PTP_H_
#define _TUSB_PTP_H_

#include "common/tusb_common.h"

#ifdef __cplusplus
 extern "C" {
#endif

typedef enum {
  PTP_SUBCLASS_STILL_IMAGE = 1
} ptp_subclass_type_t;

/// PTP Interface Protocol
typedef enum
{
  PTP_ITF_PROTOCOL_NONE = 0
} ptp_interface_protocol_enum_t;

typedef enum {
  PTP_PROTOCOL_BOT = 1
} ptp_protocol_type_t;

typedef enum {
  PTP_CONTAINER_TYPE_UNDEFINED = 0x00,
  PTP_CONTAINER_TYPE_COMMAND = 0x01,
  PTP_CONTAINER_TYPE_DATA = 0x02,
  PTP_CONTAINER_TYPE_RESPNSE = 0x03,
  PTP_CONTAINER_TYPE_EVENT = 0x04,
} ptp_container_type_t;

//typedef enum {
//  PTP_CONTAINER_LENGTH_OFFSET = 0x00,
//  PTP_CONTAINER_TYPE_OFFSET = 0x04,
//  PTP_CONTAINER_CODE_OFFSET = 0x06,
//  PTP_CONTAINER_TRANSACTION_ID_OFFSET = 0x08,
//  PTP_CONTAINER_PARAMETER_OFFSET = 0x0C,
//  PTP_CONTAINER_HEADER_SIZE = 0x0C,
//} tud_ptp_container_offset_t;

typedef enum {
  PTP_REQ_CANCEL = 0x64,
  PTP_REQ_GET_EXTENDED_EVENT_DATA = 0x65,
  PTP_REQ_DEVICE_RESET = 0x66,
  PTP_REQ_GET_DEVICE_STATUS = 0x67,
} ptp_request_t;


typedef enum {
  PTP_OPERATION_GET_DEVICE_INFO              = 0x1001,
  PTP_OPERATION_OPEN_SESSION                 = 0x1002,
  PTP_OPERATION_CLOSE_SESSION                = 0x1003,
  PTP_OPERATION_GET_STORAGE_IDS              = 0x1004,
  PTP_OPERATION_GET_STORAGE_INFO             = 0x1005,
  PTP_OPERATION_GET_NUM_OBJECTS              = 0x1006,
  PTP_OPERATION_GET_OBJECT_HANDLES           = 0x1007,
  PTP_OPERATION_GET_OBJECT_INFO              = 0x1008,
  PTP_OPERATION_GET_OBJECT                   = 0x1009,
  PTP_OPERATION_GET_THUMB                    = 0x100A,
  PTP_OPERATION_DELETE_OBJECT                = 0x100B,
  PTP_OPERATION_SEND_OBJECT_INFO             = 0x100C,
  PTP_OPERATION_SEND_OBJECT                  = 0x100D,
  PTP_OPERATION_INITIATE_CAPTURE             = 0x100E,
  PTP_OPERATION_FORMAT_STORE                 = 0x100F,
  PTP_OPERATION_RESET_DEVICE                 = 0x1010,
  PTP_OPERATION_SELF_TEST                    = 0x1011,
  PTP_OPERATION_SET_OBJECT_PROTECTION        = 0x1012,
  PTP_OPERATION_POWER_DOWN                   = 0x1013,
  PTP_OPERATION_GET_DEVICE_PROP_DESC         = 0x1014,
  PTP_OPERATION_GET_DEVICE_PROP_VALUE        = 0x1015,
  PTP_OPERATION_SET_DEVICE_PROP_VALUE        = 0x1016,
  PTP_OPERATION_RESET_DEVICE_PROP_VALUE      = 0x1017,
  PTP_OPERATION_TERMINATE_OPEN_CAPTURE       = 0x1018,
  PTP_OPERATION_MOVE_OBJECT                  = 0x1019,
  PTP_OPERATION_COPY_OBJECT                  = 0x101A,
  PTP_OPERATION_GET_PARTIAL_OBJECT           = 0x101B,
  PTP_OPERATION_INITIATE_OPEN_CAPTURE        = 0x101C,
  PTP_OPERATION_GET_OBJECT_PROPS_SUPPORTED   = 0x9801,
  PTP_OPERATION_GET_OBJECT_PROP_DESC         = 0x9802,
  PTP_OPERATION_GET_OBJECT_PROP_VALUE        = 0x9803,
  PTP_OPERATION_SET_OBJECT_PROP_VALUE        = 0x9804,
  PTP_OPERATION_GET_OBJECT_PROP_LIST         = 0x9805,
  PTP_OPERATION_SET_OBJECT_PROP_LIST         = 0x9806,
  PTP_OPERATION_GET_INTERDEPENDENT_PROP_DESC = 0x9807,
  PTP_OPERATION_SEND_OBJECT_PROP_LIST        = 0x9808,
  PTP_OPERATION_GET_OBJECT_REFERENCES        = 0x9810,
  PTP_OPERATION_SET_OBJECT_REFERENCES        = 0x9811,
  PTP_OPERATION_SKIP                         = 0x9820
} ptp_operation_codes_t;

typedef enum{
  PTP_PROPERTY_STORAGE_ID        = 0xDC01,
  PTP_PROPERTY_OBJECT_FORMAT     = 0xDC02,
  PTP_PROPERTY_PROTECTION_STATUS = 0xDC03,
  PTP_PROPERTY_OBJECT_SIZE       = 0xDC04,
  PTP_PROPERTY_OBJECT_FILE_NAME  = 0xDC07,
  PTP_PROPERTY_DATE_CREATED      = 0xDC08,
  PTP_PROPERTY_DATE_MODIFIED     = 0xDC09,
  PTP_PROPERTY_PARENT_OBJECT     = 0xDC0B,
  PTP_PROPERTY_PERSISTENT_UID    = 0xDC41,
  PTP_PROPERTY_NAME              = 0xDC44
} ptp_property_codes_t;

typedef enum {
  PTP_EVENT_UNDEFINED                 = 0x4000,
  PTP_EVENT_CANCEL_TRANSACTION        = 0x4001,
  PTP_EVENT_OBJECT_ADDED              = 0x4002,
  PTP_EVENT_OBJECT_REMOVED            = 0x4003,
  PTP_EVENT_STORE_ADDED               = 0x4004,
  PTP_EVENT_STORE_REMOVED             = 0x4005,
  PTP_EVENT_DEVICE_PROP_CHANGED       = 0x4006,
  PTP_EVENT_OBJECT_INFO_CHANGED       = 0x4007,
  PTP_EVENT_DEVICE_INFO_CHANGED       = 0x4008,
  PTP_EVENT_REQUEST_OBJECT_TRANSFER   = 0x4009,
  PTP_EVENT_STORE_FULL                = 0x400A,
  PTP_EVENT_DEVICE_RESET              = 0x400B,
  PTP_EVENT_STORAGE_INFO_CHANGED      = 0x400C,
  PTP_EVENT_CAPTURE_COMPLETE          = 0x400D,
  PTP_EVENT_UNREPORTED_STATUS         = 0x400E,
  PTP_EVENT_OBJECT_PROP_CHANGED       = 0xC801,
  PTP_EVENT_OBJECT_PROP_DESC_CHANGED  = 0xC802,
  PTP_EVENT_OBJECT_REFERENCES_CHANGED = 0xC803,
} ptp_event_codes_t;

typedef enum {
  PTP_RESPONSE_UNDEFINED                                = 0x2000,
  PTP_RESPONSE_OK                                       = 0x2001,
  PTP_RESPONSE_GENERAL_ERROR                            = 0x2002,
  PTP_RESPONSE_SESSION_NOT_OPEN                         = 0x2003,
  PTP_RESPONSE_INVALID_TRANSACTION_ID                   = 0x2004,
  PTP_RESPONSE_OPERATION_NOT_SUPPORTED                  = 0x2005,
  PTP_RESPONSE_PARAMETER_NOT_SUPPORTED                  = 0x2006,
  PTP_RESPONSE_INCOMPLETE_TRANSFER                      = 0x2007,
  PTP_RESPONSE_INVALID_STORAGE_ID                       = 0x2008,
  PTP_RESPONSE_INVALID_OBJECT_HANDLE                    = 0x2009,
  PTP_RESPONSE_DEVICE_PROP_NOT_SUPPORTED                = 0x200A,
  PTP_RESPONSE_INVALID_OBJECT_FORMAT_CODE               = 0x200B,
  PTP_RESPONSE_STORAGE_FULL                             = 0x200C,
  PTP_RESPONSE_OBJECT_WRITE_PROTECTED                   = 0x200D,
  PTP_RESPONSE_STORE_READ_ONLY                          = 0x200E,
  PTP_RESPONSE_ACCESS_DENIED                            = 0x200F,
  PTP_RESPONSE_NO_THUMBNAIL_PRESENT                     = 0x2010,
  PTP_RESPONSE_SELF_TEST_FAILED                         = 0x2011,
  PTP_RESPONSE_PARTIAL_DELETION                         = 0x2012,
  PTP_RESPONSE_STORE_NOT_AVAILABLE                      = 0x2013,
  PTP_RESPONSE_SPECIFICATION_BY_FORMAT_UNSUPPORTED      = 0x2014,
  PTP_RESPONSE_NO_VALID_OBJECT_INFO                     = 0x2015,
  PTP_RESPONSE_INVALID_CODE_FORMAT                      = 0x2016,
  PTP_RESPONSE_UNKNOWN_VENDOR_CODE                      = 0x2017,
  PTP_RESPONSE_CAPTURE_ALREADY_TERMINATED               = 0x2018,
  PTP_RESPONSE_DEVICE_BUSY                              = 0x2019,
  PTP_RESPONSE_INVALID_PARENT_OBJECT                    = 0x201A,
  PTP_RESPONSE_INVALID_DEVICE_PROP_FORMAT               = 0x201B,
  PTP_RESPONSE_INVALID_DEVICE_PROP_VALUE                = 0x201C,
  PTP_RESPONSE_INVALID_PARAMETER                        = 0x201D,
  PTP_RESPONSE_SESSION_ALREADY_OPEN                     = 0x201E,
  PTP_RESPONSE_TRANSACTION_CANCELLED                    = 0x201F,
  PTP_RESPONSE_SPECIFICATION_OF_DESTINATION_UNSUPPORTED = 0x2020,
  PTP_RESPONSE_INVALID_OBJECT_PROP_CODE                 = 0xA801,
  PTP_RESPONSE_INVALID_OBJECT_PROP_FORMAT               = 0xA802,
  PTP_RESPONSE_INVALID_OBJECT_PROP_VALUE                = 0xA803,
  PTP_RESPONSE_INVALID_OBJECT_REFERENCE                 = 0xA804,
  PTP_RESPONSE_GROUP_NOT_SUPPORTED                      = 0xA805,
  PTP_RESPONSE_INVALID_DATASET                          = 0xA806,
  PTP_RESPONSE_SPECIFICATION_BY_GROUP_UNSUPPORTED       = 0xA807,
  PTP_RESPONSE_SPECIFICATION_BY_DEPTH_UNSUPPORTED       = 0xA808,
  PTP_RESPONSE_OBJECT_TOO_LARGE                         = 0xA809,
  PTP_RESPONSE_OBJECT_PROP_NOT_SUPPORTED                = 0xA80A
} ptp_response_codes_t;

typedef struct TU_ATTR_PACKED {
  uint16_t cancel_code;
  uint32_t transaction_id;
} ptp_cancel_request_t;

// To hold the parameters
typedef struct TU_ATTR_PACKED {
  uint16_t size; ///< represents the byte size of the pointer
  void* value;
} extended_event_parameters_t;

typedef struct TU_ATTR_PACKED {
  uint16_t event_code;
  uint32_t transaction_id;
  uint16_t num_of_parameters;
  extended_event_parameters_t* parameters;
} ptp_get_extended_event_t;

// Device Status Data
typedef struct TU_ATTR_PACKED {
  uint16_t length;
  uint16_t code;
  void* parameters[];
} ptp_dsd_t;

// Generic Container
typedef struct TU_ATTR_PACKED
{
  uint32_t container_length;
  uint32_t container_type;
  uint16_t code;
  uint32_t transaction_id;
  uint32_t* payload[];
} ptp_generic_container_t;

// Command/Response Block Payload
// length can be determined by doing (length container - 12)/4
//typedef struct TU_ATTR_PACKED {
//  union{};
//  uint32_t paramter[];
//} ptp_cbp_t, ptp_rbp_t;


#ifdef __cplusplus
 } 
#endif 
#endif /* _TUSB_PTP_H_ */