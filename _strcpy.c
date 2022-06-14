#include "shell.h"
/**
 * _strcpy - Copies the string pointed to by src, including the
 * terminating null byte, to the buffer pointed by des.
 *
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 * Return: Pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);

}
