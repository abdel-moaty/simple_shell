#include "main.h"

/**
 * walnut - read commands
 * Return: Command Read from Standard Input
 */
char *walnut(void)
{
	char *command;
	size_t buffer_size;

	command = NULL;
	buffer_size = 0;
	if (getline(&command, &buffer_size, stdin) == -1)
	{
		free(command);
		return (NULL);
	}
	return (command);
}
