#include "main.h"

/**
 * _reallocdp_handler - reallocates a memory block
 * @ptr: dmemory previously allocated
 * @o_size: allocated
 * @n_size: new memory block
 * Return: ptr otherwise NULL
 */

char **_reallocdp_handler(char **ptr, unsigned int o_size, unsigned int n_size)
{
	char **n_ptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * n_size));

	if (n_size == o_size)
		return (ptr);

	n_ptr = malloc(sizeof(char *) * n_size);
	if (n_ptr == NULL)
		return (NULL);

	for (i = 0; i < o_size; i++)
		n_ptr[i] = ptr[i];

	free(ptr);

	return (n_ptr);
}
