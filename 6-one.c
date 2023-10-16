#include "main.h"
#include <stdarg.h>

/**
 * print_pointer - prints a pointer.
 * @val: value.
 * Return: int.
 */

int print_pointer(va_list val)
{
	void *p;
	char *s = "(nil)";
	long int y;
	int i, z;

	p = va_arg(val, void*);
	if (p == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
			_putchar(s[i]);
		return (i);
	}
	y = (unsigned long int)p;
	_putchar('0');
	_putchar('x');
	z = print_hex_extra(y);
	return (z + 2);
}
