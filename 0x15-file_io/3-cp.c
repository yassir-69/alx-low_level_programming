#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

char *create_buffer(void);
void close_file(int hp);

/**
 * create_buffer - Reserves memory for a buffer of 1024 bytes.
 *
 * Return: A reference to the freshly allocated buffer.
 */
char *create_buffer(void)
{
    char *buf = malloc(sizeof(char) * 1024);

        if (buf == NULL)
        {
            fprintf(stderr, "Error: Can't allocate memory\n");
            exit(99);
        }

        return (buf);
}

/**
 * close_file - Shuts down file descriptors.
 * @hp: The file descriptor that needs to be shut down.
 */
void close_file(int hp)
{
    int result = close(hp);

        if (result == -1)
        {
            fprintf(stderr, "Error: Can't close fd %d\n", hp);
            exit(100);
        }
}

int main(int argc, char *argv[])
{
    int hp_from, hp_to, bytes_read, bytes_written;
    char *buf;

        if (argc != 3)
        {
            fprintf(stderr, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
        }

    buf = create_buffer();
    hp_from = open(argv[1], O_RDONLY);

        if (hp_from == -1)
        {
            fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
            free(buf);
            exit(98);
        }

    hp_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

        if (hp_to == -1)
        {
            fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
            free(buf);
            exit(99);
        }

        while ((bytes_read = read(hp_from, buf, 1024)) > 0)
        {
            bytes_written = write(hp_to, buf, bytes_read);

            if (bytes_written == -1)
            {
                fprintf(stderr, "Error: Can't write to %s\n", argv[2]);
                free(buf);
                exit(99);
            }
        }

    free(buf);
    close_file(hp_from);
    close_file(hp_to);

        return (0);
}
