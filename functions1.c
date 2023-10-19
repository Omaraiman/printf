#include "main.h"

/**
 * handle_unintger - A function that handles an unsigned integer from a va_list
 * @my_list: The va_list from which to get the unsigned integer
 * @counter: integer counter
 */
void handle_unintger(va_list my_list, int *counter)
{
	char bufr[40];
	unsigned int uninger = (unsigned int)va_arg(my_list, unsigned int);
	int ptr = 0;
		int i = 0;

	if (uninger == 0)
	{
		bufr[ptr++] = '0';
	}

	while (uninger)
	{
		char crnt = (uninger % 10) + '0';

		bufr[ptr++] = crnt;
		uninger = uninger / 10;
	}

	for (; i < ptr / 2; i++)
	{
		char fnum = bufr[i];
		char snum = bufr[ptr - i - 1];

		bufr[i] = snum, bufr[ptr - i - 1] = fnum;
	}

	write(1, bufr, ptr);
	*counter += ptr;
}

/**
 * handle_octal - A function that handles an octal number from a va_list
 * @my_list: The va_list from which to get the octal number
 * @counter: A pointer to the counter to increment
 */
void handle_octal(va_list my_list, int *counter)
{
	unsigned int number = va_arg(my_list, unsigned int);
	char bufr[33];
	int i = 0;
	int j = 0;
	char count;

	if (number == 0)
	{
		write(1, "0", 1);
		(*counter)++;
		return;
	}

	while (number)
	{
		bufr[i++] = (number % 8) + '0';
		number = number / 8;
	}

	for (; j < i / 2; j++)
	{
		count = bufr[j];

		bufr[j] = bufr[i - j - 1];
		bufr[i - j - 1] = count;
	}

	write(1, bufr, i);
	*counter += i;
}

/**
 * handle_hex - A function that handles a hexadecimal number from a va_list
 * @my_list: The va_list from which to get the hexadecimal number
 * @counter: A pointer to the counter to increment
 * @uppercase: A flag to determine
 */
void handle_hex(va_list my_list, int *counter, int uppercase)
{
	unsigned int number = va_arg(my_list, unsigned int);
	char bufr[33];
	int i = 0;
	char count;
	int j = 0;

	if (number == 0)
	{
		write(1, "0", 1);
		(*counter)++;
		return;
	}

	while (number)
	{
		count = number % 16;

		if (count < 10)
			bufr[i++] = count + '0';
		else
			bufr[i++] = count - 10 + (uppercase ? 'A' : 'a');

		number = number / 16;
	}

	for (; j < i / 2; j++)
	{
		count = bufr[j];

		bufr[j] = bufr[i - j - 1];
		bufr[i - j - 1] = count;
	}

	write(1, bufr, i);
	*counter += i;
}
/**
 * handle_format_specifier - a function handle format specifier
 * @my_list: The va_list
 * @counter: A pointer to the counter
 * @format: pointer for loop
 */
void handle_format_specifier(char format, va_list my_list, int *counter)
{
	if (format == '%')
		handle_percent(counter);
	else if (format == 'c')
		handle_char(my_list, counter);
	else if (format == 's')
		handle_string(my_list, counter);
	else if (format == 'd' || format == 'i')
		*counter += handle_intger(my_list);
	else if (format == 'b')
		handle_binary(my_list, counter);
	else if (format == 'u')
		handle_unintger(my_list, counter);
	else if (format == 'o')
		handle_octal(my_list, counter);
	else if (format == 'x')
		handle_hex(my_list, counter, 0);
	else if (format == 'X')
		handle_hex(my_list, counter, 1);
	else
	{
		write(1, "%", 1);
		write(1, &format, 1);
		*counter += 2;
	}
}
