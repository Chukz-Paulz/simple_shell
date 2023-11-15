#include "shell.h"

/**
 * printMessage - This prints a message
 * Betty would be proud
 */
void printMessage(void)
{
	/* Declaration */
	char *message = "Betty would be proud";
	int i;

	for (i = 0; message[i] != '\0'; i++)
	{
		/*Prints the message*/
		_putchar(message[i]);
	}
	_putchar('\n');
}
