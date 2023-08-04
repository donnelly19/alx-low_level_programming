#include "main.h"
#include <stdio.h>
/**
 * get_endianness - checks the endianness of the system
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
	unsigned int num = 1;
	unsigned char *ptr;

	ptr = (unsigned char *)&num;
	return (*ptr == 1);
}
