#include "main.h"

/**
 * _memcpy_handler - copies information between void pointers
 * @newptr: destination pointer
 * @ptr: source pointer
 * @size: size of the new pointer
 */

void _memcpy_handler(void *newptr, const void *ptr, unsigned int size)
{
	char *c_ptr = (char *)ptr, *c_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		c_newptr[i] = c_ptr[i];
	}
}

