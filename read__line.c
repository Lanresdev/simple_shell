#include "shell.h"

/**
 * read__line - This reads the input string.
 *
 * @i_eof: This returns value of getline function
 * Return: input string
 */
char *read__line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
