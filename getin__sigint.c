#include "shell.h"

/**
 * getin__sigint - Handle the crtl + c call in prompt.
 * @sig: Signal handler.
 */
void getin__sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
