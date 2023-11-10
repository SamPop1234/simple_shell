#include "shell.h"

/**
 * mfree - frees a pointer and NULLs the address
 * @ptr: pointer to be freed
 *
 * Return: 1 if successfully freed, else 0.
 */
int mfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
