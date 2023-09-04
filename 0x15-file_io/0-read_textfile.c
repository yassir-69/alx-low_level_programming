#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Read the text file and output its contents to the standard output (STDOUT).
 * @filename: Reading a file of text.
 * @letters: The quantity of letters to be read.
 * Return: The actual number of bytes read and displayed.
 *   Zero is returned when the function encounters a failure or when the filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
    char *buffer;
	ssize_t hp;
	ssize_t o;
	ssize_t y;

	hp = open(filename, O_RDONLY);
	    if (hp == -1)
	    	return (0);
	buffer = malloc(sizeof(char) * letters);
	    y = read(hp, buffer, letters);
	    o = write(STDOUT_FILENO, buffer, y);

	free(buffer);
	close(hp);
	    return (o);

}
