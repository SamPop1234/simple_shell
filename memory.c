#include "shell.h"

/**
 * bfree - frees pointer also NULL the address
 * @ptr: the pointer address freed
 *
 * Return: 1 if freed, otherwise 0.
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
