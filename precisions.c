#include "main.h"

/**
 * get_precision - Act as Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int precision = 0;

	if (format[*i] == '.')
	{
		(*i)++;

		if (isdigit(format[*i]))
		{
			precision = atoi(&format[*i]);

			while (isdigit(format[*i]))
				(*i)++;
		}
		else if (format[*i] == '*')
		{
			precision = va_arg(list, int);
			(*i)++;
		}
		else
		{
			precision = 0;
		}
	}
	return (precision);
}

