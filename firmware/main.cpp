#include <hFramework.h>
#include <hPython.h>
#include <cstdio>
#include <hPyFramework.h>

hQueue<char> queue;

void qqq();
int hMain()
{
	while (Serial.getRXwaiting())
		Serial.getch();
		
	queue.init(1000);
	sys.taskCreate(qqq, 2, 2000);
	
	for (;;)
	{
		char q = Serial.getch();
		if (q == 3) // ^C
		{
			hPython::killVM();
		}
		else if (q == 4) // ^D
		{
		}
		else
		{
			queue.sendToBack(q);
		}
	}
}

void qqq()
{
	sys.setLogDev(&Serial);
	hPython::init();
	
	hPyFramework::pyRegister();
	
	// for(;;)
	{
		LED2.toggle();
		sys.delay_ms(50);
	}
	hPython::eval("hSens1.selectI2C()");
	hPython::eval("a=hSens1.getI2C()");
	hPython::eval("b=[0x42]");
	hPython::eval("c=[0]");
	
	Serial.printf("> ");
	
	char buff[2048];
	unsigned int i = 0;
	int specialState = 0;
	while (1)
	{
		char ch;
		queue.receive(ch);
		// Serial.printf("0x%02x\r\n", ch);
		// continue;
		if (ch == 0x7f)
		{
			if (i > 0)
			{
				Serial.printf("\x08 \x08");
				i--;
			}
			continue;
		}
		if (ch == 0x1b || ch == 0x3b)
		{
			specialState = 1;
			continue;
		}
		if (specialState == 1)
		{
			if (ch == 0x1b)
			{
				specialState = 1;
			}
			else
			{
				specialState = 2;
			}
			continue;
		}
		if (specialState == 2)
		{
			specialState = 0;
			continue;
		}
		Serial.printf("%c", ch);
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
			if (hPython::replContinueWithInput(buff))
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
				// LED2.toggle();
			}
		}
		else
		{
			i++;
		}
		// LED1.toggle();
	}
}




