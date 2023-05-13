#include "main.h"

/**
 * nutty - display a prompt
 */
void nutty(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("nutshell$ ");
	}
}
