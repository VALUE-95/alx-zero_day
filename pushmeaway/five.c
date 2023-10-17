#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @f: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *f, int *i)
{
	int c = *i + 1;
	int s = 0;

	if (f[c] == 'l')
		s = S_LONG;
	else if (f[c] == 'h')
		s = S_SHORT;

	if (s == 0)
		*i = c - 1;
	else
		*i = c;

	return (s);
}
