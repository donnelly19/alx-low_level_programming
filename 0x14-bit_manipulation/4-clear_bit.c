#include "main.h"
#include <stdio.h>
/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: pointer to unsigned long int
 * @index: index of the bit to be cleared
 * Return: 1 if it worked, or -1 if an error occured
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	i = 1UL << index;
	if (index >= sizeof(unsigned long int) * 8)
		return (-1);
	*n &= ~i;
	return (1);
}
