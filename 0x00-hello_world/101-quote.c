#include <unistd.h>
/**
 * main - 101-quote.c
 * description - Write a C program that prints exactly
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	write(2,
	      "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",
	      59);

	return (1);
}
