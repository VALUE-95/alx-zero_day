#include "main.h"
#include <stdarg.h>

/**
 * print_oct - converts to octal.
 * @val: variable argument.
 * Return: cont.
 */

int print_oct(va_list val)
{
	int i, cont = 0;
	int *arr;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	while (num / 8 != 0)
	{
		num = num / 8;
		cont++;
	}
	cont++;
	arr = malloc(sizeof(int) * cont);
	if (arr == NULL)
		return (NULL);
			for (i = 0; i < cont; i++)
			{
				arr[i] = temp % 8;
				temp = temp / 8;
			}
	for (i = cont - 1; i >= 0; i--)
		_putchar(arr[i] + '0');
	free(arr);
	return (cont);
}
