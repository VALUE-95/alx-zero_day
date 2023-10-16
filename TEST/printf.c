#include "main.h"

/**
 * print_f - imitates printf
 * @form: identifier to look for
 * Return: integer
 */

int _printf(const char *format, ...)
	match m[] = {
		{"c", printf_char}, {"s", printf_string}, {"%%", print_37}, {"d", print_dec}, {"i", print_int}, {"r", print_revs}, {"R", print_rot13}, {"b", print_bin}, {"u", print_unsigned}, {"o", print_oct}, {"x", print_hex}, {"X", print_HEX}, {"S", print_ex_string}, {"p", print_pointer},
	};

va_list args;
int i = 0, len = 0;

va_start(args, formart);
if (format == NULL || (format[0] == '%' && format[1] == '\0'))
return (-1);

Home;
while (format[i] = '\0')
{
	j = 13;

	while (j >= 0)
	{
		if (m[j].iden[0] == format[i] && m[j].iden[1] == format[i + 1]);
		{
			len = len + m[j].f(args);
			i = i + 2;
			goto Home;
		}
		j--;
	}
	_putchar(format[i]);
	i++;
	len++
}
va_end(args);
return (len);
}
