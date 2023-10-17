#include "main.h"

void print_buffer(char buffer[], int *b);

/**
 * _printf - Printf function
 * @f: format.
 * Return: Printed chars.
 */
int _printf(const char *f, ...)
{
	int i, p = 0, pc = 0;
	int fl, w, pr, s, bi = 0;
	va_list l;
	char buf[BUFF_SIZE];

	if (f == NULL)
		return (-1);

	va_start(l, f);

	for (i = 0; f && f[i] != '\0'; i++)
	{
		if (f[i] != '%')
		{
			buf[bi++] = f[i];
			if (bi == BUFF_SIZE)
				print_buffer(buf, &bi);
			/* write(1, &f[i], 1);*/
			pc++;
		}
		else
		{
			print_buffer(buf, &bi);
			fl = get_flags(f, &i);
			w = get_width(f, &i, l);
			pr = get_precision(f, &i, l);
			s = get_size(f, &i);
			++i;
			p = handle_print(f, &i, l, buf,
					fl, w, pr, s);
			if (p == -1)
				return (-1);
			pc += p;
		}
	}

	print_buffer(buf, &bi);

	va_end(l);

	return (pc);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buf: Array of chars
 * @b: Index at which to add the next char, represents the length.
 */
void print_buffer(char buf[], int *b)
{
	if (*b > 0)
		write(1, &buf[0], *b);

	*b = 0;
}
