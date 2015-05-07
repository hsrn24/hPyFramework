#ifndef FTDI_H
#define FTDI_H

#include <ftdi.h>

class FTDI
{
public:
	FTDI();

	bool open(int speed);
	void close();

	int write(const void* data, int len);
	int read(void* data, int len, int timeout_ms = 2000);
	int readAny(void* data, int len);

private:
	ftdi_context* m_ftdi;
	int m_speed;
};

#endif // FTDI_H
