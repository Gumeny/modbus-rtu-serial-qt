#ifndef GLOBAL_H
#define GLOBAL_H

extern void *device_handle;
extern bool wait_for_write, com_reading_started;
extern int bytes_to_wait_for, bytes_written;

enum Mcp2221ErrorCodes
{
    NO_ERR = 0,
    ERR_UNKNOWN_ERROR = -1,
    ERR_CMD_FAILED = -2,
    ERR_INAVID_HANDLE = -3,
    ERR_INVALID_PARAMETER = -4,
    ERR_DEVICE_NOT_FOUND = -103
};

#endif // GLOBAL_H
