# modbus-rtu-serial-qt
Desktop application for sending and receiving ModBus RTU strings through serial port.

App is written in C++ using Qt framework.

GOALS:

-sending and receiving strings in different formats (ASCII, binary, octal, decimal, hexadecimal)
-serial port settings (baudrate, parity etc.)
-CRC16 calculation and auto-append to string, that is being send
-history of sent strings
-auto-repeat sending with given interval
