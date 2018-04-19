/*
 * Copyright (c) 2018 Yubico AB. All rights reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */

#include "fido/err.h"

const char *
fido_strerr(int n)
{
	switch (n) {
	case FIDO_ERR_SUCCESS:
		return "FIDO_ERR_SUCCESS";
	case FIDO_ERR_INVALID_COMMAND:
		return "FIDO_ERR_INVALID_COMMAND";
	case FIDO_ERR_INVALID_PARAMETER:
		return "FIDO_ERR_INVALID_PARAMETER";
	case FIDO_ERR_INVALID_LENGTH:
		return "FIDO_ERR_INVALID_LENGTH";
	case FIDO_ERR_INVALID_SEQ:
		return "FIDO_ERR_INVALID_SEQ";
	case FIDO_ERR_TIMEOUT:
		return "FIDO_ERR_TIMEOUT";
	case FIDO_ERR_CHANNEL_BUSY:
		return "FIDO_ERR_CHANNEL_BUSY";
	case FIDO_ERR_LOCK_REQUIRED:
		return "FIDO_ERR_LOCK_REQUIRED";
	case FIDO_ERR_INVALID_CHANNEL:
		return "FIDO_ERR_INVALID_CHANNEL";
	case FIDO_ERR_CBOR_UNEXPECTED_TYPE:
		return "FIDO_ERR_UNEXPECTED_TYPE";
	case FIDO_ERR_INVALID_CBOR:
		return "FIDO_ERR_INVALID_CBOR";
	case FIDO_ERR_MISSING_PARAMETER:
		return "FIDO_ERR_MISSING_PARAMETER";
	case FIDO_ERR_LIMIT_EXCEEDED:
		return "FIDO_ERR_LIMIT_EXCEEDED";
	case FIDO_ERR_UNSUPPORTED_EXTENSION:
		return "FIDO_ERR_UNSUPPORTED_EXTENSION";
	case FIDO_ERR_CREDENTIAL_EXCLUDED:
		return "FIDO_ERR_CREDENTIAL_EXCLUDED";
	case FIDO_ERR_PROCESSING:
		return "FIDO_ERR_PROCESSING";
	case FIDO_ERR_INVALID_CREDENTIAL:
		return "FIDO_ERR_INVALID_CREDENTIAL";
	case FIDO_ERR_USER_ACTION_PENDING:
		return "FIDO_ERR_ACTION_PENDING";
	case FIDO_ERR_OPERATION_PENDING:
		return "FIDO_ERR_OPERATION_PENDING";
	case FIDO_ERR_NO_OPERATIONS:
		return "FIDO_ERR_NO_OPERATIONS";
	case FIDO_ERR_UNSUPPORTED_ALGORITHM:
		return "FIDO_ERR_UNSUPPORTED_ALGORITHM";
	case FIDO_ERR_OPERATION_DENIED:
		return "FIDO_ERR_OPERATION_DENIED";
	case FIDO_ERR_KEY_STORE_FULL:
		return "FIDO_ERR_STORE_FULL";
	case FIDO_ERR_NOT_BUSY:
		return "FIDO_ERR_NOT_BUSY";
	case FIDO_ERR_NO_OPERATION_PENDING:
		return "FIDO_ERR_OPERATION_PENDING";
	case FIDO_ERR_UNSUPPORTED_OPTION:
		return "FIDO_ERR_UNSUPPORTED_OPTION";
	case FIDO_ERR_INVALID_OPTION:
		return "FIDO_ERR_INVALID_OPTION";
	case FIDO_ERR_KEEPALIVE_CANCEL:
		return "FIDO_ERR_KEEPALIVE_CANCEL";
	case FIDO_ERR_NO_CREDENTIALS:
		return "FIDO_ERR_NO_CREDENTIALS";
	case FIDO_ERR_USER_ACTION_TIMEOUT:
		return "FIDO_ERR_ACTION_TIMEOUT";
	case FIDO_ERR_NOT_ALLOWED:
		return "FIDO_ERR_NOT_ALLOWED";
	case FIDO_ERR_PIN_INVALID:
		return "FIDO_ERR_PIN_INVALID";
	case FIDO_ERR_PIN_BLOCKED:
		return "FIDO_ERR_PIN_BLOCKED";
	case FIDO_ERR_PIN_AUTH_INVALID:
		return "FIDO_ERR_AUTH_INVALID";
	case FIDO_ERR_PIN_AUTH_BLOCKED:
		return "FIDO_ERR_AUTH_BLOCKED";
	case FIDO_ERR_PIN_NOT_SET:
		return "FIDO_ERR_NOT_SET";
	case FIDO_ERR_PIN_REQUIRED:
		return "FIDO_ERR_PIN_REQUIRED";
	case FIDO_ERR_PIN_POLICY_VIOLATION:
		return "FIDO_ERR_POLICY_VIOLATION";
	case FIDO_ERR_PIN_TOKEN_EXPIRED:
		return "FIDO_ERR_TOKEN_EXPIRED";
	case FIDO_ERR_REQUEST_TOO_LARGE:
		return "FIDO_ERR_TOO_LARGE";
	case FIDO_ERR_ACTION_TIMEOUT:
		return "FIDO_ERR_ACTION_TIMEOUT";
	case FIDO_ERR_UP_REQUIRED:
		return "FIDO_ERR_UP_REQUIRED";
	case FIDO_ERR_ERR_OTHER:
		return "FIDO_ERR_OTHER";
	case FIDO_ERR_SPEC_LAST:
		return "FIDO_ERR_SPEC_LAST";
	case FIDO_ERR_TX:
		return "FIDO_ERR_TX";
	case FIDO_ERR_RX:
		return "FIDO_ERR_RX";
	case FIDO_ERR_RX_NOT_CBOR:
		return "FIDO_ERR_RX_NOT_CBOR";
	case FIDO_ERR_RX_INVALID_CBOR:
		return "FIDO_ERR_RX_INVALID_CBOR";
	case FIDO_ERR_INVALID_PARAM:
		return "FIDO_ERR_INVALID_PARAM";
	case FIDO_ERR_INVALID_SIG:
		return "FIDO_ERR_INVALID_SIG";
	case FIDO_ERR_INVALID_ARGUMENT:
		return "FIDO_ERR_INVALID_ARGUMENT";
	case FIDO_ERR_DEVICE_OPEN:
		return "FIDO_ERR_DEVICE_OPEN";
	case FIDO_ERR_DEVICE_CLOSED:
		return "FIDO_ERR_DEVICE_CLOSED";
	case FIDO_ERR_INTERNAL:
		return "FIDO_ERR_INTERNAL";
	default:
		return "FIDO_ERR_UNKNOWN";
	}
}