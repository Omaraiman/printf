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
*/
void handle_intger(va_list my_list)
{
	char bufr[40];
	int integer = va_arg(my_list,  int);
	int ptr = 0;
	int is_neg = 0;
	int i;

	if (integer < 0)
	{
		bufr[ptr++] = '-';
		integer = -integer;
		is_neg = 1;
	}
	if (integer == 0)
	{
		bufr[ptr++] = '0';
	}

	while (integer)
	{
		char crnt = (integer % 10) + '0';

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
