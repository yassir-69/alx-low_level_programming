#include "main.h"

/**
 * append_text_to_file - Adds text to the conclusion of a file.
 * @filename: A reference to the filename.
 * @text_content: The text to append to the file's end.
 *
 * Return: If the function encounters an error or if the filename is NULL, it returns -1.
 *         If the file doesn't exist or if the user lacks write permissions, it returns -1.
 *         If not, then -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int z, x, the_len = 0;

	    if (filename == NULL)
	    	return (-1);

	    if (text_content != NULL)
	    {
	    	for (the_len = 0; text_content[the_len];)
	    		the_len++;
	    }

	z = open(filename, O_WRONLY | O_APPEND);
	x = write(z, text_content, the_len);

	    if (z == -1 || x == -1)
	    	return (-1);

	close(z);

	        return (1);
}
