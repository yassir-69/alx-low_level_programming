#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

void check_elf(unsigned char *eo_oident);
void print_magic(unsigned char *eo_oident);
void print_class(unsigned char *eo_oident);
void print_data(unsigned char *eo_oident);
void print_version(unsigned char *eo_oident);
void print_osabi(unsigned char *eo_oident);
void print_abi(unsigned char *eo_oident);
void print_type(unsigned int e_type, unsigned char *eo_oident);
void print_entry(unsigned long int e_entry, unsigned char *eo_oident);
void close_elf(int elf_o);

/**
 * check_elf - Verifies whether a file is an ELF (Executable and Linkable Format) file.
 * @e_ident: A reference to an array that holds the ELF magic numbers.
 *
 * Description: If the file is not in the ELF format, exit with code 98.
 */
void check_elf(unsigned char *eo_oident)
{
	int ind_ex;

	    for (ind_ex = 0; ind_ex < 4; ind_ex++)
	    {
	    	if (eo_oident[ind_ex] != 127 &&
	    	    eo_oident[ind_ex] != 'E' &&
	    	    eo_oident[ind_ex] != 'L' &&
	    	    eo_oident[ind_ex] != 'F')
	    	{
	    		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
	    		exit(98);
	    	}
	    }
}
/**
 * print_magic - Displays the magic numbers found in an ELF header.
 * @eo_oident: A reference to an array that holds the ELF magic number values.
 *
 * Description: The magic numbers are delimited by spaces.
 */
void print_magic(unsigned char *eo_oident)
{
	int ind_ex;

	printf(" Magic: ");

	for (ind_ex = 0; ind_ex < EI_NIDENT; ind_ex++)
	{
		printf("%02x", eo_oident[ind_ex]);

		if (ind_ex == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Displays the ELF header's class.
 * @eo_oident: A reference to an array that holds the ELF header's class information.
 */
void print_class(unsigned char *eo_oident)
{
	printf(" Class: ");

	switch (eo_oident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", eo_oident[EI_CLASS]);
	}
}

/**
 * print_data - Displays the data type of an ELF header.
 * @eo_oident: A reference to an array that holds the ELF header's data information.
 */
void print_data(unsigned char *eo_oident)
{
	printf(" Data: ");

	switch (eo_oident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", eo_oident[EI_CLASS]);
	}
}

/**
 *  * print_version - Displays the version of an ELF header.
 *   * @eo_oident: A reference to an array that contains the ELF header's version information.
 *    */
void print_version(unsigned char *eo_oident)
{
	 printf(" Version: %d",
			  eo_oident[EI_VERSION]);

	switch (eo_oident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Displays the OS/ABI information of an ELF header.
 * @eo_oident: A reference to an array that holds the OS/ABI information of an ELF header.
 */
void print_osabi(unsigned char *eo_oident)
{
	printf(" OS/ABI: ");

	switch (eo_oident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", eo_oident[EI_OSABI]);
	}
}

/**
 * print_abi - Displays the ABI version of an ELF header.
 * @eo_oident: A reference to an array that contains the ELF header's ABI version information.
 */
void print_abi(unsigned char *eo_oident)
{
	printf(" ABI Version: %d\n",
		eo_oident[EI_ABIVERSION]);
}

/**
 * print_type - Displays the type of an ELF header.
 * @e_type: The type of ELF.
 * @eo_oident: A reference to an array that holds the type information of an ELF header.
 */
void print_type(unsigned int e_type, unsigned char *eo_oident)
{
	if (eo_oident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Displays the entry point of an ELF header.
 * @e_entry: The address where the ELF entry point is located.
 * @eo_oident: A reference to an array that holds the address of the ELF entry point.
 */
void print_entry(unsigned long int e_entry, unsigned char *eo_oident)
{
	printf(" Entry point address: ");

	if (eo_oident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (eo_oident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}



/**
 * close_elf - Shuts down an ELF file.
 * @elf_o: The file descriptor associated with the ELF file.
 *
 * Description: If it's not possible to close the file, exit with code 98.
 */
void close_elf(int elf_o)
{
	if (close(elf_o) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf_o);
		exit(98);
	}
}

/**
 * main - Shows the details present in the
 * ELF header located at the beginning of an ELF file.
 * @ar_gc: The count of arguments provided to the program.
 * @ar_gv: A collection of pointers to the program's arguments.
 *
 * Return: Zero indicates success.
 *
 * Description: If the file is not in the ELF format or
 * If the function encounters an error, exit with code 98.
 */
int main(int __attribute__((__unused__)) ar_gc, char *ar_gv[])
{
	Elf64_Ehdr *header;
	int x, y;

	o = open(ar_gv[1], O_RDONLY);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", ar_gv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", ar_gv[1]);
		exit(98);
	}
	y = read(x, header, sizeof(Elf64_Ehdr));
	if (y == -1)
	{
		free(header);
		close_elf(x);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", ar_gv[1]);
		exit(98);
	}

	check_elf(header->eo_oident);
	printf("ELF Header:\n");
	print_magic(header->eo_oident);
	print_class(header->eo_oident);
	print_data(header->eo_oident);
	print_version(header->eo_oident);
	print_osabi(header->eo_oident);
	print_abi(header->eo_oident);
	print_type(header->e_type, header->eo_oident);
	print_entry(header->e_entry, header->eo_oident);

	free(header);
	close_elf(x);
	return (0);
}
