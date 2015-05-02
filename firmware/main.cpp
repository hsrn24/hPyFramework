#include <hFramework.h>
#include <hPython.h>
#include <cstdio>

hQueue<char> queue;
void register_hPyFramework();
void register_hPySensors();

void pythonTask();
int hMain()
{
	while (Serial.getRXwaiting())
		Serial.getch();
		
	queue.init(1000);
	sys.taskCreate(pythonTask, 2, 2000);
	
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

void pythonTask()
{
	sys.setLogDev(&Serial);
	hPython::init();
	
	register_hPyFramework();
	register_hPySensors();
	
	Serial.printf("> ");
	
	char buff[2048];
	unsigned int i = 0;
	int specialState = 0;
	while (1)
	{
		char ch;
		queue.receive(ch);
		// Serial.printf("0x%02x\r\n", ch);
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
			}
		}
		else
		{
			i++;
		}
	}
}




