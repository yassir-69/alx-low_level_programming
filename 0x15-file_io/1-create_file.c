#include "main.h"

/**
 * create_file - Generates or Creates The File.
 * @filename: A pointer referencing the filename to be generated.
 * @text_content: A pointer to a string intended for writing into the file.
 *
 * Return: In case of failure, the function returns -1.
 * Alternatively, it returns 1.
 */
int create_file(const char *filename, char *text_content)
{
	int length, zwri, hp = 0;

if (filename == NULL)
	return (-1);

if (text_content != NULL)
{
	for (length = 0; text_content[length];)
		length++;
}
	hp = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	zwri = write(hp, text_content, length);
if (hp == -1 || zwri == -1)
	return (-1);

close(hp);
return (1);
}
