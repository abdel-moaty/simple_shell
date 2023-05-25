#include "main.h"

/**
 * nutshell - execute commands in a nutshell
 * @command: command
 * @program: program name
 * @env: environment
 * Return: Exit Status of Child Process, or -1 (Error)
 */
int nutshell(char *command, char *program, char **env)
{
	pid_t pid;
	int i, status, wordCount;
	char **arguments;

	command[strcspn(command, "\n")] = '\0';
	arguments = nutcracker(command, &wordCount);
	if (strcmp(arguments[0], "env") == 0)
	{
		i = 0;
		while (env[i] != NULL)
			printf("%s\n", env[i]), i++;
		status = 0;
	}
	else if (strcmp(arguments[0], "exit") == 0)
		status = -1;
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror(program);
			return (-1);
		}
		else if (pid == 0)
		{
			execvp(arguments[0], arguments), perror(program), exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				status = WEXITSTATUS(status);
			else
				status = -1;
		}
	}
	for (i = 0; i < wordCount; i++)
		free(arguments[i]);
	free(arguments);
	return (status);
}
