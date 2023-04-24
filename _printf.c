#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format
 * Return: Number of charatcters printed
 */

int _printf(const char *format, ...)
{
	int x, printed = 0, print_ch = 0;
	int flg, w, p, size, bu = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
	return (-1);

	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[bu++] = format[x];
			if (bu == BUFF_SIZE)
				print_buffer(buffer, &bu);
			/* write(1, &format[x], 1);*/
			print_ch++;
		}
		else
		{
			print_buffer(buffer, &bu);
			flg = get_flg(format, &x);
			w = get_w(format, &x, list);
			p = get_p(format, &x, list);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buffer,
				flg, w, p, size);
			if (printed == -1)
				return (-1);
			print_ch += printed;
		}
	}

	print_buffer(buffer, &bu);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
