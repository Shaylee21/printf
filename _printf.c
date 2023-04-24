#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format
 *
 * Return: Number of charatcters printed
 *
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int c = 0;

	if (format == NULL)
		return (-1);

	va_start(arg, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += print_char(arg);
				break;
			case 's':
				count += print_string(arg);
				break;
			case '%':
				count += print_percent();
				break;
			default:
				count += print_invalid(*format);
				break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(arg)
		return (count);
}

