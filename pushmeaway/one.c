#include "main.h"

/*
 * is_printable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/*
 * append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @b: Array of chars.
 * @i: Index at which to start appending.
 * @a: ASCII CODE.
 * Return: Always 3
 */
int append_hexa_code(char a, char b[], int i)
{
	char map[] = "0123456789ABCDEF";

	if (a < 0)
		a *= -1;

	b[i++] = '\\';
	b[i++] = 'x';

	b[i++] = map[a / 16];
	b[i] = map[a % 16];

	return (3);
}

/*
 * is_digit - Verifies if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/*
 * convert_size_number - Casts a number to the specified size
 * @n: Number to be casted.
 * @s: Number indicating the type to be casted.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int n, int s)
{
	if (s == S_LONG)
		return (n);
	else if (s == S_SHORT)
		return ((short)n);

	return ((int)n);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @n: Number to be casted
 * @s: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int n, int s)
{
	if (s == S_LONG)
		return (n);
	else if (s == S_SHORT)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
