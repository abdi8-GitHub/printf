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
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] == '.')
	{
		curr_i++;
		if (isdigit(format[curr_i]))
		{
			precision = 0;

			while (isdigit(format[curr_i])
			{
				precision = precision * 10 + (format[curr_i] - '0');
				curr_i++;
			}
		}
		else if (format[curr_i] == '*')
		{
			precision = va_arg(list, int);
			curr_i++;
		}
		else
		{
			precision = 0;
		}
	}
	*i = curr_i;
	return (precision);
}

