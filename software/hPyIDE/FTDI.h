#ifndef FTDI_H
#define FTDI_H

#include <ftdi.h>

class FTDI
{
public:
	enum EParity { None, Odd, Even };
	enum EStopBits { One, OneHalf, Two };
	FTDI();

	bool open(int speed, EParity parity, EStopBits stopbits);
	void close();

	int write(const void* data, int len);
	int read(void* data, int len, int timeout_ms = 2000);
	int readAny(void* data, int len);

private:
	ftdi_context* m_ftdi;
	int m_speed;
};

#endif // FTDI_H
