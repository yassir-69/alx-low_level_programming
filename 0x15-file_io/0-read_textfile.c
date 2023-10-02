#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Read the contents of a text file and
 * output them to the standard output (STDOUT).
 * @filename: The file containing text is being read.
 * @letters: The count of letters that need to be read.
 * Return: w- With the effective count of bytes read and displayed.
 * Zero is returned in case of function failure or when the filename
 * is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;
ssize_t lre;
ssize_t hp;
ssize_t zwri;

	hp = open(filename, O_RDONLY);
	if (hp == -1)
	return (0);

	buffer = malloc(sizeof(char) * letters);
	lre = read(hp, buffer, letters);
	zwri = write(STDOUT_FILENO, buffer, lre);
	free(buffer);
	close(hp);
	return (zwri);
}
