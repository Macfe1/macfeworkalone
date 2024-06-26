#include "main.h"
#include <unistd.h>

/**
 * pr_string - function to pass a string to the buffer
 *
 * @lis_arg: list of parameters
 * @start_point: point in the buffer to know where to continue
 * @buffer: where we paste the new parameter
 *
 * Return: the number of characters passed to the buffer
 */
int pr_string(va_list lis_arg, int start_point, char *buffer)
{
	int counter_i = 0;
	char *argument_string = va_arg(lis_arg, char*);

	if (argument_string == NULL)
		argument_string = "(null)";

	while (argument_string[counter_i] != '\0')
	{
		buffer[start_point++] = argument_string[counter_i++];
	}

	return (counter_i);
}
