#include "main.h"
#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

/**
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int counter = 0, counter_arg = 0, i = 0;

	char types_of_arg[] = {'c', 's', 'd', 'i'};

	char argument_char = '\0';
	char *argument_string = NULL;
	/*int argument_int = 0;*/
	int validOperation = 0;
	int size = 0;

	char buffer[1024];

	va_list parameters_to_execute;

	va_start(parameters_to_execute, format);
	
	for (counter = 0; format[counter] != '\0'; counter++)
	{
		counter_arg = 0;

		if (format[counter] != '%')
		{
			buffer[size] = format[counter];
			size++;
			continue;
		}
		while (types_of_arg[counter_arg] != '\0')
		{
			if (format[counter + 1] != '\0' && format[counter + 1] == types_of_arg[counter_arg])
			{
				if (format[counter + 1] == 'c')
				{
					argument_char = (char) va_arg(parameters_to_execute, int);
					counter += 1;
					buffer[size] = argument_char;
				}

				if (format[counter + 1] == 's')
				{
					argument_string = va_arg(parameters_to_execute, char*);
					while (argument_string[i] != '\0')
					{
						buffer[size] = argument_string[i];
						size++;
						i++;
					}
				}

				validOperation = 1;
				break;
			}
			
			validOperation = 0;
			counter_arg++;
		}
		
		if (!validOperation)
			buffer[size] = format[counter];
	}

	va_end(parameters_to_execute);

	write(1, buffer, size);

	return(size);
}
