#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - function to ouput characters according to format
 * @format: character string composed of zero or more directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && (++i))
		{
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				count++, write(1, &c, 1);

			}
			else if (format[i] == 's')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
					s = "(null)";
				while (*s)
					count++, write(1, s++, 1);
			}
			else if (format[i] == '%')
				count++, write(1, &format[i], 1);
			else
				count += 2, write(1, "%%", 1), write(1, &format[i], 1);
		}
		else
			count++, write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
