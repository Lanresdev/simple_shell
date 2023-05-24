#include "shell.h"

/**
 * exec__line - finds builtins and commands.
 *
 * @datash: data relevant args
 * Return: 1 on success.
 */
int exec__line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get__builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
