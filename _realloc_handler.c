#include "main.h"

/**
 * _realloc_handler - reallocates a memory
 * @ptr: memory previously allocated
 * @o_size: size, allocated ptr
 * @n_size: new size, memory block
 * Return: ptr otherwise NULL
 */

void *_realloc_handler(void *ptr, unsigned int o_size, unsigned int n_size)
{
	void *n_ptr;

	if (ptr == NULL)
		return (malloc(n_size));

	if (n_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (n_size == o_size)
		return (ptr);

	n_ptr = malloc(n_size);
	if (n_ptr == NULL)
		return (NULL);

	if (n_size < o_size)
		_memcpy_handler(n_ptr, ptr, n_size);
	else
		_memcpy_handler(n_ptr, ptr, o_size);

	free(ptr);
	return (n_ptr);
}

