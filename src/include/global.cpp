#include <include\global.h>

void *device_handle = nullptr;
bool wait_for_write = false, com_reading_started = false;
int bytes_to_wait_for = 0, bytes_written = 0;
