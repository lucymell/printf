#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar_c - prints a character.
 * @c: character input.
 * Return: int, bytes written.
 */

int _putchar_c(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * _putchar - prints a character.
 * @a: va_list input.
 * Return: int, bytes written.
 */

int _putchar(va_list a)
{
	char c;

	c = va_arg(a, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_str - prints a string.
 * @a: input string.
 * Return: int, bytes written.
 */

int print_str(va_list a)
{
	int n;
	char *s;

	s = va_arg(a, char *);
	n = 0;
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
		n++;
	}
	return (n);
}

/**
 * print_uint - prints unsigned int.
 * @n: int input.
 * Return: int, bytes written.
 */

int print_uint(unsigned int n)
{
	static int count;
	int digit;

	count = 0;
	if (n / 10 != 0)
	{
		count++;
		print_uint(n / 10);
	}
	digit = ((n % 10) + '0');
	write(1, &digit, 1);
	return (count);
}

/**
 * print_int - prints int.
 * @a: input.
 * Return: int, bytes written.
 */

int print_int(va_list a)
{
	char sign;
	int n, count;

	n = va_arg(a, int);
	count = 0;
	sign = '-';
	if (n < 0)
	{
		write(1, &sign, 1);
		n = -n;
		count++;
	}
	count += print_uint((unsigned int) n);
	return (count);
}
