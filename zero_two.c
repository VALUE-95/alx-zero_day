#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * printf_string - prints a string.
 * @val: argument.
 * Return: the length of the string.
 */

int printf_string(va_list val)
{
	char *str;
	int i;
	int length;

	str = va_arg(val, char *);

	if (str == NULL)
	{
		str = "(null)";
		length = str_len(str);
		for (i = 0; i < length; i++)
			_putchar(str[i]);
		return (length);
	}
	else
	{
		length = str_len(str);
		for (i = 0; i < length; i++)
			_putchar(str[i]);
		return (length);
	}
}
