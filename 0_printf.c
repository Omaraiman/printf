#include "main.h"
/**
 * _printf - A function that prints a data
 * @format: The format string to use
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list my_list;

	if (format == NULL)
		return (-1);
	va_start(my_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			counter++;
		}
		else
		{
			format++;
			if (*format == '\0')
				return (-1);
			handle_format_specifier(*format, my_list, &counter);
		}
		format++;
	}
	va_end(my_list);
	return (counter);
}
