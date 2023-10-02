#include "main.h"

/**
 * append_text_to_file - Adds text to the conclusion of a file.
 * @filename: A pointer pointing to the file's name.
 * @text_content: The string to append to the end of the file.
 *
 * Return: In case of function failure or a NULL filename, it returns -1.
 * If the file is non-existent or the user lacks write permissions,
 * it returns -1.
 * Alternatively, it returns 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int x = 0, y = 0, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	x = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0664);
	y = write(x, text_content, length);

	if (x == -1 || y == -1)
		return (-1);

	close(x);

	return (1);
}
