#include "hblk_crypto.h"

/**
 * create_array - malloc
 * @size: len
 * @c: char
 *
 * Return: pointer
 */
int *main(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);
	arr = (char *)malloc(sizeof(char) * size);
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		arr[i] = c;
	return (arr);
}
