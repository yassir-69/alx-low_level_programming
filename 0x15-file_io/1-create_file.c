#include "main.h"

/**
 * length_of_a_string - returns the length of a string or
 * Provides the size of a string
 * @string: The string for which the length is measured.
 * Return: The integer value representing the length of the string.
 */
int length_of_a_string(char *string)
{
int o = 0;
if (!string)
return (0);

while (*string++)
o++;
return (o);
}

/**
 * create_file - Generates or Creates The File.
 * @filename: A pointer referencing the filename to be generated.
 * @text_content: A pointer to a string intended for writing into the file.
 *
 * Return: Returns 1 when successful.
 * Returns -1 when failure.
 */
int create_file(const char *filename, char *text_content)
{
int fd;
ssize_t byte = 0, length = length_of_a_string(text_content);

if (!filename)
return (-1);

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

if (length)
byte = write(fd, text_content, length);
close(fd);
return (byte == length ? 1 : -1);
}
