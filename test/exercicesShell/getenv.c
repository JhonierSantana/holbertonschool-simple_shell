#include "shell.h"

/**
 * _getenv - Extracts an env variable from environ
 * @name: Variable name
 * Return: Pointer to variable name, or NULL if variable hasn't be found
 */

char *_getenv(char *name)
{
	char *extractenv;
	int difference, i, envlen;

	for (i = 0; environ[i]; i++)
	{
		envlen = _strlen(environ[i]);
		extractenv = malloc(sizeof(*extractenv) * (envlen + 1));
		if (extractenv == NULL)
			return (NULL);
		extractenv = _strcpy(extractenv, environ[i]);
		extractenv = strtok(extractenv, "=");
		difference = _strcmp(name, extractenv);
		if (difference == 0)
		{
			free(extractenv);
			return (environ[i]);
		}
		else
			free(extractenv);
	}
	return (NULL);
}
