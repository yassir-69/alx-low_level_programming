#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *Generate_buffer(char *fl);
void Conclude_file(int fld);

/**
 * Generate_buffer - Reserves a buffer of 1024 bytes.
 * @fl: The file buffer's name, where characters are stored.
 *
 * Return: A reference to the recently allocated memory space.
 */
char *Generate_buffer(char *fl)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", fl);
		exit(99);
	}

	return (buf);
}

/**
 * Conclude_file - Shuts down file descriptors.
 * @fld: The file descriptor that is intended to be shut down.
 */
void Conclude_file(int fld)
{
	int h;

	h = close(fld);

	if (h == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fld);
		exit(100);
	}
}

/**
 * main - Duplicates the content of one file into another file.
 * @argumentsc: The count of arguments provided to the program.
 * @argumentsv: A collection of pointers pointing to the arguments,
 * arranged in an array.
 *
 * Return: Indicates success with a return value of 0.
 *
 * Description: Exit with code 97 in case of an incorrect argument count.
 * Exit with code 98 if file_from doesn't exist or is unreadable.
 * Exit with code 99 if file_to cannot be generated or written to.
 * Exit with code 100 if it's not possible to close either file_to
 * or file_from.
 */
int main(int argumentsc, char *argumentsv[])
{
	int org_from, in, rea, zwri;
	char *buf;

	if (argumentsc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = Generate_buffer(argumentsv[2]);
	org_from = open(argumentsv[1], O_RDONLY);
	rea = read(org_from, buf, 1024);
	in = open(argumentsv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (org_from == -1 || rea == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argumentsv[1]);
			free(buf);
			exit(98);
		}

		zwri = write(in, buf, rea);
		if (in == -1 || zwri == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argumentsv[2]);
			free(buf);
			exit(99);
		}

		rea = read(org_from, buf, 1024);
		in = open(argumentsv[2], O_WRONLY | O_APPEND);

	} while (rea > 0);

	free(buf);
	Conclude_file(org_from);
	Conclude_file(in);

	return (0);
}
