#include "main.h"
#include <stdarg.h>

/**
 * print_ex_str - prints exclusive string.
 * @val: value.
 * Return: number of characters printed.
 */

int print_ex_str(va_list val)
{
	char *s;
	int i, len = 0;
	int VALUE;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			VALUE = s[i];
			if (VALUE < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_HEX_extra(VALUE);
		}
		else
		{

			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}
