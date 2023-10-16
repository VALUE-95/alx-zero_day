#include "main.h"
#include <stdarg.h>

/**
 * print_rot13 - convert to rot13.
 * @val: parameters.
 * Return: cont.
 */

int print_rot13(va_list val)
{
	int i, j, cont = 0;
	int k = 0;
	char *s = va_arg(val, char*);
	char a[] = {"abcdefghijklmnopqrstuvwxyz"};
	char b[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; a[j] && !k; j++)
		{
			if (s[i] == a[j])
			{
				_putchar(b[j]);
				cont++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(s[i]);
			cont++;
		}
	}
	return (cont);
}
