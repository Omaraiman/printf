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
			if (*format == '%')
				handle_percent(&counter);
			else if (*format == 'c')
				handle_char(my_list, &counter);
			else if (*format == 's')
				handle_string(my_list, &counter);
			else if (*format == 'd' || *format == 'i')
			counter += handle_intger(my_list);
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				counter += 2;
			}
		}
		format++;
	}
	va_end(my_list);
	return (counter);
}
