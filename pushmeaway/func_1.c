#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @t: List a of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list t, char b[], int f, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, b, f, w, p, s));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @t: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list t, char b[], int f, int w, int p, int s)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (f & F_HASH && init_num != 0)
		b[i--] = '0';

	i++;

	return (write_unsgnd(0, i, b, f, w, p, s));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @t: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list t, char b[], int f, int w, int p, int s)
{
	return (print_hexa(t, "0123456789abcdef", b, f, 'x', w, p, s));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @t: Lista of arguments
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list t, char b[], int f, int w, int p, int s)
{
	return (print_hexa(t, "0123456789ABCDEF", b, f, 'X', w, p, s));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @t: Lista of arguments
 * @map_to: Array of values to map the number to
 * @b: Buffer array to handle print
 * @f:  Calculates active flags
 * @fc: Calculates active flags
 * @w: get width
 * @p: Precision specification
 * @s: Size specifier
 * @s: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list t, char map_to[], char b[], int f, char fc, int w, int p, int s)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(t, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, s);

	if (num == 0)
		b[i--] = '0';

	b[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		b[i--] = map_to[num % 16];
		num /= 16;
	}

	if (f & F_HASH && init_num != 0)
	{
		b[i--] = fc;
		b[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, b, f, w, p, s));
}
