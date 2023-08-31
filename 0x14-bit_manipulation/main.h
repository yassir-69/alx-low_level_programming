#ifndef BITMANIPULATION_H
#define BITMANIPULATION_H

void print_binary(unsigned long int n);
unsigned int binary_to_uint(const char *b);
int set_bit(unsigned long int *n, unsigned int index);
int get_bit(unsigned long int n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int clear_bit(unsigned long int *n, unsigned int index);
int get_endianness(void);

#endif /* BITMANIPULATION_H */
