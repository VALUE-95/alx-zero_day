#include "main.h"

/**
 * _printf - imitates printf
 * @format: identifier to look for
 * Return: integer
 */

int _printf(const char *format, ...)
{
	match m[] = {
		{"c", printf_char}, {"s", printf_string}, {"%%", print_37},
		{"d", print_dec}, {"i", print_int}, {"r", print_rev_str},
		{"R", print_rot13}, {"b", print_bin}, {"u", print_unsigned},
		{"o", print_oct}, {"x", print_hex}, {"X", print_HEX},
		{"S", print_ex_str}, {"p", print_pointer},
	};

	va_list args;
	int i = 0, len = 0, j = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Home:

	while (format[i] != '\0')
	{
		j = 13;

		while (j >= 0)
		{
			if (m[j].iden[0] == format[i] && m[j].iden[1] == format[i + 1])
			{
				len += m[j].f(args);
				i += 2;
				goto Home;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		len++;
	}
	va_end(args);
	return (len);
}
