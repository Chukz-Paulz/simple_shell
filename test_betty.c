#include "shell.h"

/**
 * custom_main - entry point for custom_main
 *
 * Return: 0 on success, 1 on error
 */
int custom_main(void)
{
    /* Call printMessage function */
	printMessage();

	return 0;
}

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
		__putchar(message[i]);
	}
	__putchar('\n');
}
