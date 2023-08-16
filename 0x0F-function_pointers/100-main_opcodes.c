#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints its own opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
void print_opcodes(char *address, int num_bytes) {
    for (int i = 0; i < num_bytes; i++) {
        printf("%02hhx", *(address + i));
        if (i < num_bytes - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    int num_bytes = atoi(argv[1]);
    if (num_bytes <= 0) {
        printf("Error\n");
        return 2;
    }

    print_opcodes((char *)&main, num_bytes);

    return 0;
}

