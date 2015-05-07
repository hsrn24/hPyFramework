#include "myFTDI.h"

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

#include <libusb.h>
#include <ftdi.h>
#include <ftdi_i.h>

#define BOOT0 0
#define RST   1

uint32_t getTicks();

static uint8_t vals;
static int speed;
static ftdi_context* m_ftdi = 0;

int setPin(int pin, int value)
{
	vals &= ~(1 << pin);
	vals |= (1 << (pin + 4)) | (value << pin);
	return ftdi_set_bitmode(m_ftdi, vals, BITMODE_CBUS);
}

bool uart_open(int speed, bool showErrors)
{
	int ret;
	
	if (m_ftdi)
	{
		uart_close();
	}
	m_ftdi = ftdi_new();
	
	if ((ret = ftdi_usb_open(m_ftdi, 0x0403, 0x6015)) < 0)
	{
		if (showErrors)
			fprintf(stderr, "unable to open m_ftdi device: %d (%s)\n", ret, ftdi_get_error_string(m_ftdi));
		ftdi_free(m_ftdi);
		m_ftdi = 0;
		return 0;
	}
	
	m_ftdi->usb_read_timeout = 1000;
	m_ftdi->usb_write_timeout = 1000;
	libusb_set_auto_detach_kernel_driver(m_ftdi->usb_dev, 1);
	ftdi_read_data_set_chunksize(m_ftdi, 4096);
	::speed = speed;
	
	ftdi_set_line_property(m_ftdi, BITS_8, STOP_BIT_1, NONE);
	ftdi_setflowctrl(m_ftdi, SIO_DISABLE_FLOW_CTRL);
	
	ftdi_disable_bitbang(m_ftdi);
#ifdef WIN32
	ftdi_set_baudrate(m_ftdi, speed * 4);
#else
	ftdi_set_baudrate(m_ftdi, speed);
#endif
	
	return m_ftdi;
}
int uart_check_gpio()
{
	int r;
	r = ftdi_read_eeprom(m_ftdi);
	ftdi_eeprom_decode(m_ftdi, 0);
	int p1 = m_ftdi->eeprom->cbus_function[0];
	int p2 = m_ftdi->eeprom->cbus_function[1];
	const int IOMODE = 8;
	if (p1 != IOMODE || p2 != IOMODE)
	{
		m_ftdi->eeprom->cbus_function[0] = IOMODE;
		m_ftdi->eeprom->cbus_function[1] = IOMODE;
		ftdi_eeprom_build(m_ftdi);
		ftdi_write_eeprom(m_ftdi);
		return 1;
	}
	return 0;
}
int uart_reset()
{
	setPin(BOOT0, 1);
	usleep(10000);
	setPin(RST, 1);
	usleep(100000);
	setPin(RST, 0);
	usleep(100000);
	
	ftdi_set_line_property(m_ftdi, BITS_8, STOP_BIT_1, EVEN);
	ftdi_setflowctrl(m_ftdi, SIO_DISABLE_FLOW_CTRL);
	
	ftdi_disable_bitbang(m_ftdi);
#ifdef WIN32
	ftdi_set_baudrate(m_ftdi, speed * 4);
#else
	ftdi_set_baudrate(m_ftdi, speed);
#endif
}
bool uart_isOpened()
{
	return m_ftdi != 0;
}
int uart_tx(const void* data, int len)
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
int uart_rx_any(void* data, int len)
{
	uint8_t* _data = (uint8_t*)data;
	
	int rread = ftdi_read_data(m_ftdi, _data, len);
	if (rread < 0)
		return -1;
		
	return rread;
}
int uart_rx(void* data, int len, uint32_t timeout_ms)
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
void uart_reset_normal()
{
	int ret;
	
	setPin(BOOT0, 0);
	usleep(10000);
	setPin(RST, 1);
	usleep(100000);
	setPin(RST, 0);
	
	ftdi_set_line_property(m_ftdi, BITS_8, STOP_BIT_1, NONE);
	ftdi_setflowctrl(m_ftdi, SIO_DISABLE_FLOW_CTRL);
	
	ftdi_disable_bitbang(m_ftdi);
#ifdef WIN32
	ftdi_set_baudrate(m_ftdi, speed * 4);
#else
	ftdi_set_baudrate(m_ftdi, speed);
#endif
}
void uart_close()
{
	int ret;
	
	if (!m_ftdi)
		return;
		
	// libusb_attach_kernel_driver(m_ftdi->usb_dev, m_ftdi->interface);
	if ((ret = ftdi_usb_close(m_ftdi)) < 0)
		fprintf(stderr, "unable to close m_ftdi device: %d (%s)\n", ret, ftdi_get_error_string(m_ftdi));
		
	ftdi_free(m_ftdi);
	
	m_ftdi = 0;
}
