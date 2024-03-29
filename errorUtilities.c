#include "shell.h"

/**
 * _erratoi - This func converts a string to an integer.
 * @s: The string to be converted.
 *
 * Return: 0 if no numbers in the string, converted number otherwise,
 * -1 on error.
 */
int _erratoi(char *s)
{
	/*Declaration*/
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
			return (-1);
		}
		else
			return (-1);
		}
			return (result);
}

/**
 * print_error - This prints an error message.
 * @info: The parameter & return info struct.
 * @estr: String containing specified error type.
 *
 * Return: Void.
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - This func prints a decimal (integer) number (base 10).
 * @input: The input.
 * @fd: The file descriptor to write to.
 *
 * Return: Number of characters printed.
 */
int print_d(int input, int fd)
{
	/*Declarations*/
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;

	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
	if (_abs_ / i)
		{
		__putchar('0' + current / i);
		count++;
		}
		current %= i;
	}

		__putchar('0' + current);
		count++;

	return (count);
}

/**
 * convert_number - This converter function, a clone of itoa.
 * @num: Number.
 * @base: Base.
 * @flags: Argument flags.
 *
 * Return: This function returns  String.
 */
char *convert_number(long int num, int base, int flags)
{
	/*Declarations*/
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}

	array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - This  func replaces the first instance of '#' with '\0'.
 * @buf: Address of the string to modify.
 *
 * Return: Void.
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
		buf[i] = '\0';
		break;
		}
}
