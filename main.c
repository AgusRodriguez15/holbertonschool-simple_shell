#include "shellmans.h"
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char *str;
	char **arr_toks;
	size_t x = 0;
	pid_t child_pid;
	int status;
	extern char **environ;

	while (1)
	{
    	printf("$shellmans ");
	
	if (getline(&str, &x, stdin) == -1)
                return 0;
	str[strlen(str) - 1] = '\0';
	arr_toks = tokenizar(str);

	if (strcmp(str, "exit\n") == 0)
	{
		free(str);
		break;
	}
	child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error");
			return (1);
		}

		if (child_pid == 0)
		{
			if (execve(arr_toks[0], arr_toks, environ) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
			wait(&status);
	}
	return (0);
}
