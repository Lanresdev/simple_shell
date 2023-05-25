#include "shell.h"

/**
 * bfree - this frees a pointer
 * @ptr: address of the pointer  to be  freed
 * Return: 1 if it will be  freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
