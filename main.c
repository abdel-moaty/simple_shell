#include "main.h"

/**
 * main - display a prompt and wait for the user to type a command
 * @ac: number of arguments
 * @av: NULL terminated array of strings
 * @env: NULL terminated array of strings
 * Return: Always 0 (Success)
 */
int main(int ac, char **av, char **env)
{
	char *command;
	int status, interactive;

	(void)ac;
	status = 0;
	interactive = isatty(STDIN_FILENO);
	do {
		nutty();
		command = walnut();
		if (command == NULL)
		{
			if (interactive)
			{
				printf("\n");
			}
			break;
		}
		status = nutshell(command, av[0], env);
		free(command);
	} while (status != -1);
	return (0);
}
