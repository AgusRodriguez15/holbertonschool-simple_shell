#include "shellmans.h"
/**
 * tokenizar - 2d array
 * @str: take the string that is going to be tokenized
 * Return: Nothing.
 */
char **tokenizar(char *str)
{
	char *token, *tok, *t, *dup, **ar, *delim = " ";
	int cantToks = 0, i = 0, b = 0;

	dup = strdup(str);
	if (dup == NULL)
		return (NULL);
	tok = strtok(dup, delim);
	while (tok != NULL)
	{
		cantToks++;
		tok = strtok(NULL, delim);
	}
	free(dup);
	ar = malloc((cantToks + 1) * sizeof(char *));
	if (ar == NULL)
	{
		free(dup);
		return (NULL);
	}
	dup = strdup(str);
	if (dup == NULL)
		return (NULL);
	token = strtok(t, delim);
	while (token != NULL)
	{
		ar[i] = strdup(token);
		if (ar[i] == NULL)
		{
			for (b = 0; b < i; b++)
				free(ar[b]);
			free(dup), free(dup), free(ar);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
	}
	ar[i] = NULL;
	free(dup);;
	return (ar);
}
