#include "shell.h"

int _strlen(char *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (!s)
		return (len);
	while (*(s + i) != '\0')
	{
		len += 1;
		i++;
	}
	return (len);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) && *(s2 + i) && (*(s1 + i) == *(s2 + i)))
		i++;
	return (*(s1 + i) - *(s2 + i));
}

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char *_strdup(char *src)
{
	int c, len;
	char a;
	char *dest;

	for (len = 0; src[len] != '\0'; len++)
	{
	}
	dest = malloc(sizeof(char) * (len + 2));
	for (c = 0; src[c] != '\0'; c++)
	{
		a = src[c];
		dest[c] = a;
	}
	dest[c] = '\0';
	return (dest);
}

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	do
	{
		if (*s == '-')
			sign *= -1;

		else if (*s >= '0' && *s <= '9')
			num = (num * 10) + (*s - '0');

		else if (num > 0)
			break;

	} while (*s++);

	return (num * sign);
}

ssize_t _puts(char *str)
{
	ssize_t num, len;

	num = _strlen(str);
	len = write(STDOUT_FILENO, str, num);
	if (len != num)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (len);
}
