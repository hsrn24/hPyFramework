#include "FTDI.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#include <libusb.h>
#include <ftdi_i.h>

uint32_t getTicks();

FTDI::FTDI()
{
	m_ftdi =0;
}

bool FTDI::open(int speed, EParity parity, EStopBits stopbits)
{
	int ret;

	if(m_ftdi)
		close();

	m_ftdi = ftdi_new();
	
	if ((ret = ftdi_usb_open(m_ftdi, 0x0403, 0x6015)) < 0)
	{
		//if (showErrors)
		//	fprintf(stderr, "unable to open m_ftdi device: %d (%s)\n", ret, ftdi_get_error_string(m_ftdi));
		ftdi_free(m_ftdi);
		return false;
	}
	
	m_ftdi->usb_read_timeout = 1000;
	m_ftdi->usb_write_timeout = 1000;
	libusb_set_auto_detach_kernel_driver(m_ftdi->usb_dev, 1);
	ftdi_read_data_set_chunksize(m_ftdi, 4096);
	m_speed = speed;

	ftdi_stopbits_type sb;
	switch(stopbits)
	{
		case One: sb = STOP_BIT_1; break;
		case OneHalf: sb = STOP_BIT_15; break;
		case Two: sb = STOP_BIT_2; break;
	}
	ftdi_parity_type pa;
	switch(parity)
	{
		case None: pa = NONE; break;
		case Odd: pa = ODD; break;
		case Even: pa = EVEN; break;
	}

	ftdi_set_line_property(m_ftdi, BITS_8, sb, pa);
	ftdi_setflowctrl(m_ftdi, SIO_DISABLE_FLOW_CTRL);
	
	ftdi_disable_bitbang(m_ftdi);
#ifdef WIN32
	ftdi_set_baudrate(m_ftdi, speed * 4);
#else
	ftdi_set_baudrate(m_ftdi, speed);
#endif

	return true;
}
void FTDI::close()
{
	int ret;

	if (!m_ftdi)
		return;

	if ((ret = ftdi_usb_close(m_ftdi) < 0))
		fprintf(stderr, "unable to close m_ftdi device: %d (%s)\n", ret, ftdi_get_error_string(m_ftdi));

	ftdi_free(m_ftdi);

	m_ftdi = 0;
}

int FTDI::write(const void* data, int len)
{
	uint8_t* _data = (uint8_t*)data;
	while (len)
	{
		int written = ftdi_write_data(m_ftdi, _data, len);
		if (written < 0)
			return -1;
		len -= written;
		_data += written;
	}
	return 0;
}
int FTDI::read(void* data, int len, int timeout_ms)
{
	uint8_t* _data = (uint8_t*)data;
	int r = 0;
	uint32_t start = getTicks();

	while (len && getTicks() - start < timeout_ms)
	{
		int rread = ftdi_read_data(m_ftdi, _data, len);
		if (rread < 0)
			return -1;

		len -= rread;
		_data += rread;
		r += rread;
	}
	return r;
}
int FTDI::readAny(void* data, int len)
{
	uint8_t* _data = (uint8_t*)data;

	int rread = ftdi_read_data(m_ftdi, _data, len);
	if (rread < 0)
		return -1;

	return rread;
}
