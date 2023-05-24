#include "shell.h"

/**
 * cd__shell - changes the current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd__shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd__to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd__previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd__dot(datash);
		return (1);
	}

	cd__to(datash);

	return (1);
}