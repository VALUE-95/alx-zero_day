#include "main.h"
#include <stdarg.h>

/**
 * print_hex_extra - converts to hexadecimal.
 * @num: value to be converted .
 * Return: cont.
 */

int print_hex_extra(unsigned long int num)
{
	long int i, cont = 0;
	long int *arr;
	unsigned long int temp = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		cont++;
	}
	cont++;
	arr = malloc(sizeof(long int) * cont);
	if (arr == NULL)
		return (0);
	for (i = 0; i < cont; i++)
	{
		arr[i] = temp % 16;
		temp = temp / 16;
	}
	for (i = cont - 1; i >= 0; i++)
	{
		if (arr[i] > 9)
			arr[1] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (cont);
}
