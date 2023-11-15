#include "shell.h"

/**
 * interactive - the return value true if shell is in interactive mode
 * @info: struct address
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *is_delim - checks if a character is a delimiter
 * @q: the char to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char q, char *delim)
{
	for (; *delim; delim++)
	{
	if (*delim == q)
	{
		return (1);
		}
	}
	return (0);
}

/**
 * is_alphabetic - will check the alphabetic character
 * @q: The character to check
 * Return: 1 if q is alphabetic, 0 otherwise
 */
int is_alphabetic(int q)
{
	return ((q >= 'a' && q <= 'z') || (q >= 'A' && q <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in the string, converted number otherwise
 */
int _atoi(char *s)
{
	int k = 0, sign = 1, flag = 0, output = 0;

	for (k = 0; s[k] != '\0' && flag != 2; k++)
	{
		if (s[k] == '-')
		{
			sign *= -1;
		}
			if (s[k] >= '0' && s[k] <= '9')
			{
				flag = 1;
				output *= 10;
				output += (s[k] - '0');
			} else if (flag == 1)
			{
			flag = 2;
		}
	}
	/*Returns output*/
	return ((sign == -1) ? -output : output);
}

