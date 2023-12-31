#include "main.h"
/**
 * handle_char - A function that handles a character from a va_list
 * @my_list: The va_list from which to get the character
 * @counter: A pointer to the counter to increment
 */
void handle_char(va_list my_list, int *counter)
{
	char character = va_arg(my_list, int);

	write(1, &character, 1);
	(*counter)++;
}
/**
 * handle_string - A function that handles a string from a va_list
 * @my_list: The va_list from which to get the string
 * @counter: A pointer to the counter to increment
 */
void handle_string(va_list my_list, int *counter)
{
	int i = 0;
	char *strings = va_arg(my_list, char*);

	if (strings == NULL)
	{
		strings = "(null)";
	}
	while (strings[i] != '\0')
	{
		write(1, &strings[i], 1);
		i++;
	}

	*counter += i;
}
/**
 * handle_intger - handel intger numper
 *  @my_list: The va_list from which to get the string
 * Return: Number of characters printed
*/
int handle_intger(va_list my_list)
{
	char bufr[1024], crnt;
	int integer = va_arg(my_list,  int);
	int ptr = 0;
	int is_neg = 0;
	int i, digit;

	if (integer < 0)
	{
		bufr[ptr++] = '-';
		is_neg = 1;
	}
	if (integer == 0)
	{
		bufr[ptr++] = '0';
	}

	while (integer)
	{
		digit = integer % 10;

		if (is_neg)
			digit = -digit;
		crnt = digit + '0';

		bufr[ptr++] = crnt;
		integer = integer / 10;
	}
	i = is_neg;

	for (; i < (ptr + is_neg) / 2; i++)
	{
		char fnum = bufr[i];
		char snum = bufr[ptr - i - !(is_neg)];

		bufr[i] = snum, bufr[ptr - i - !(is_neg)] = fnum;
	}
	write(1, bufr, ptr);

	return (ptr);
}
/**
 * handle_percent - A function that handles the percent character
 * @counter: A pointer to the counter to increment
 */
void handle_percent(int *counter)
{
	char percent = '%';

	write(1, &percent, 1);
	(*counter) += 1;
}
/**
 * handle_binary - A function that handles a binary number from a va_list
 * @my_list: The va_list from which to get the binary number
 * @counter: A pointer to the counter to increment
 */
void handle_binary(va_list my_list, int *counter)
{
	unsigned int numper = va_arg(my_list, unsigned int);
	char binary[33];
	int i = 0;
	char temp;
	int j = 0;

	if (numper == 0)
	{
		write(1, "0", 1);
		(*counter)++;
		return;
	}

	while (numper)
	{
		binary[i++] = (numper % 2) + '0';
		numper = numper / 2;
	}

	for (; j < i / 2; j++)
	{
		temp = binary[j];

		binary[j] = binary[i - j - 1];
		binary[i - j - 1] = temp;
	}

	write(1, binary, i);
	*counter += i;
}
