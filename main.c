#include "shellmans.h"
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char *str, **arr_toks;
	size_t x = 0;
	pid_t child_pid;
	int status;

	while (1)
	{
		if(isatty(STDIN_FILENO))	
		printf("$shellmans ");
		if (getline(&str, &x, stdin) == -1)
		{
			free(str);
			return (0);
		}
			str[strlen(str) - 1] = '\0';
			arr_toks = tokenizar(str);
	if (strcmp(str, "exit") == 0)
	{
		free(str);
		break;
	}
	child_pid = fork();
		if (child_pid == -1)
		{
			free(str);
			perror("Error");
			return (1);
		}

		if (child_pid == 0)
		{
			free(str);
			if (execve(arr_toks[0], arr_toks, environ) == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
			free(str);
			wait(&status);
	}
	return (0);
}
