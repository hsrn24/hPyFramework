#include "hFramework.h"
#include "hPython.h"
#include "hPyFramework.h"
#include <cstdio>

extern "C" {
#include "py/repl.h"
}

void qqq();
int hMain()
{
	sys.taskCreate(qqq, 2, 1000);
}

void qqq()
{
	sys.setLogDev(&Serial);
	hPython::init();
	
	pyRegister();
	
	// for(;;)
	{
		LED2.toggle();
		sys.delay_ms(50);
	}
	// hPython::eval("print('aaaa',2+4*9)");
	
	Serial.printf("> ");
	
	while (Serial.getRXwaiting())
		Serial.getch();
		
	char buff[128];
	unsigned int i = 0;
	while (1)
	{
		char ch = Serial.getch();
		Serial.printf("%c", ch);
		if (ch == 0x7f)
		{
			if (i > 0)
			{
				Serial.printf("\x08 \x08");
				i--;
			}
			continue;
		}
		if (i >= sizeof(buff))
			i = 0;
		if (ch == '\r')
		{
			Serial.printf("\n");
			ch = '\n';
		}
		buff[i] = ch;
		if (ch == '\n')
		{
			buff[i] = '\0';
			// Serial.printf("|%s|", buff);
			if (mp_repl_continue_with_input(buff))
			{
				buff[i] = '\n';
				i++;
				Serial.printf("# ");
			}
			else
			{
				i = 0;
				hPython::eval(buff);
				Serial.printf("> ");
				LED2.toggle();
			}
		}
		else
		{
			i++;
		}
		LED1.toggle();
	}
}




