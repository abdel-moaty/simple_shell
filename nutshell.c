#include "main.h"

/**
 * nutshell - execute commands in a nutshell
 * @command: command
 * @program: program name
 * Return: Exit Status of Child Process, or -1 (Error)
 */
int nutshell(char *command, char *program, char **env)
{
	pid_t pid;
	int i, status;
	char *args[2];

	command[strcspn(command, "\n")] = '\0';
	if (strcmp(command, "env") == 0)
	{
		i = 0;
		while (env[i] != NULL)
		{
			printf("%s\n", env[i]);
			i++;
		}
		return (0);
	}
	pid = fork();
	if (pid == -1)
	{
		perror(program);
		return (-1);
	}
	else if (pid == 0)
	{
		args[0] = command;
		args[1] = NULL;
		execve(command, args, env);
		perror(program);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		return (-1);
	}
}
