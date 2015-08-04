#include <hFramework.h>
#include <hPython.h>
#include <cstdio>

hQueue<char> queue;
void register_hPyFramework();
void register_hPySensors();

void pythonTask();
int hMain()
{
	while (Serial.available())
		Serial.getch();

	queue.init(1000);
	sys.taskCreate(pythonTask, 2, 2000);

	for (;;)
	{
		char q = Serial.getch();
		if (q == 3) // ^C
		{
			Python.killVM();
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
	Python.init();
<<<<<<< HEAD

=======
	
>>>>>>> devel
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
		if (ch == 0x01)
		{
			char d;
			uint32_t len = 0;
			queue.receive(d);
			len |= ((uint32_t)d << 0);
			queue.receive(d);
			len |= ((uint32_t)d << 8);
			queue.receive(d);
			len |= ((uint32_t)d << 16);
			queue.receive(d);
			len |= ((uint32_t)d << 24);

			char *str = (char*)sys.malloc(len);
			for (uint32_t i = 0; i < len; i++)
			{
				queue.receive(d);
				str[i] = d;
			}
			str[len] = 0;
			Python.eval(str);
			sys.free(str);
			i = 0;
			continue;
		}

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
			if (Python.replContinueWithInput(buff))
			{
				buff[i] = '\n';
				i++;
				Serial.printf("# ");
			}
			else
			{
				i = 0;
				Python.evalSingle(buff);
				Serial.printf("> ");
			}
		}
		else
		{
			i++;
		}
	}
}




