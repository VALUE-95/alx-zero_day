#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @f: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */

int get_width(const char *f, int *i, va_list list)
{
	int c;
	int w = 0;

	for (c = *i + 1; f[c] != '\0'; c++)
	{
		if (is_digit(f[c]))
		{
			w *= 10;
			w += f[c] - '0';
		}
		else if (f[c] == '*')
		{
			c++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = c - 1;

	return (w);
}
