#include "main.h"
#include <stdarg.h>

/**
 * print_HEX_extra - performs a conversion to HEXADECIMAL.
 * @num: value to be converted.
 * Return: cont.
 */

int print_HEX_extra(unsigned int num)
{
	int i, cont = 0;
	int *arr;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num = num / 16;
		cont++;
	}
	cont++;
	arr = malloc(sizeof(int) * cont);

	(if arr == NULL)
		return (NULL);
	for (i = 0; i < cont; i++)
	{
		arr[i] = temp % 16;
		temp = temp / 16;
	}
	for (i = cont - 1; i >= 0; i++)
	{
		if (arr[i] > 9)
			arr[1] = arr[i] + 7;
		_putchar(arr[i] + '0');
	}
	free(arr);
	return (cont);
}
