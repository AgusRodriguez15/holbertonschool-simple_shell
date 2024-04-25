#include "shellmans.h"
/**
 * tokenizar - 2d array
 * @str: take the string that is going to be tokenized
 * Return: Nothing.
 */
char **tokenizar(char *str)
{
	char *token, *tok, *t, *a, **ar, *delim = " ";
	int cantToks = 0, i = 0, b = 0;

	a = strdup(str);
	if (a == NULL)
		return (NULL);
	tok = strtok(a, delim);
	while (tok != NULL)
	{
		cantToks++;
		tok = strtok(NULL, delim);
	}
	ar = malloc((cantToks + 1) * sizeof(char *));
	if (ar == NULL)
	{
		free(a);
		return (NULL);
	}
	t = strdup(str);
	if (t == NULL)
		return (NULL);
	token = strtok(t, delim);
	while (token != NULL)
	{
		ar[i] = strdup(token);
		if (ar[i] == NULL)
		{
			for (b = 0; b < i; b++)
				free(ar[b]);
			free(a), free(t), free(ar);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
	}
	ar[i] = NULL;
	free(a), free(t);
	return (ar);
}
