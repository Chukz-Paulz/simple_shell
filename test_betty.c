#include "shell.h"

/**
 * printMessage - This prints a message
 * I want to make betty proud!
 */
void printMessage(void)
{
	/* Declaration */
	char *message = "I want make betty proud";
	int i;

	for (i = 0; message[i] != '\0'; i++)
	{
		/*Prints the message*/
		_putchar(message[i]);
	}
	_putchar('\n');
}
