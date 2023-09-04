#include "main.h"

/**
 * create_file - Generates a new file.
 * @filename: A reference to the filename for creating the file.
 * @text_content: A reference to a string for writing to the file.
 *
 * Return: In case of failure, it returns - -1.
 *         If not, then -1.
 */
int create_file(const char *filename, char *text_content)
{
	int hp, o, the_len = 0;

	    if (filename == NULL)
	    	return (-1);

	    if (text_content != NULL)
	    {
	    	for (the_len = 0; text_content[the_len];)
	    		the_len++;
	    }

	hp = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	o = write(hp, text_content, the_len);

	    if (hp == -1 || o == -1)
	    	return (-1);

	close(hp);

	        return (1);
}
