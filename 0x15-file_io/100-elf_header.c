#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* FUNCTION 1 */
void verify_elf(unsigned char *e_ident);
/* FUNCTION 2 */
void display_magic(unsigned char *e_ident);
/* FUNCTION 3 */
void display_class(unsigned char *e_ident);
/* FUNCTION 4 */
void display_data(unsigned char *e_ident);
/* FUNCTION 5 */
void display_version(unsigned char *e_ident);
/* FUNCTION 7 */
void display_abi(unsigned char *e_ident);
/* FUNCTION 6 */
void display_osabi(unsigned char *e_ident);
/* FUNCTION 8 */
void display_type(unsigned int elf_type, unsigned char *e_ident);
/* FUNCTION 9 */
void display_entry(unsigned long int elf_entry_point,
unsigned char *e_ident);
/* FUNCTION 10 */
void shut_down_elf(int ele_file);

/* FUNCTION 1 */

/**
 * verify_elf - Verifies whether a file is of the ELF file format.
 * @e_ident: A reference to an array holding the magic numbers
 * associated with ELF.
 *
 * Description: Exit with code 98 if the file is not in the ELF format.
 */
void verify_elf(unsigned char *e_ident)
{
	int position;

	for (position = 0; position < 4; position++)
	{
		if (e_ident[position] != 127 &&
		    e_ident[position] != 'E' &&
		    e_ident[position] != 'L' &&
		    e_ident[position] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/* FUNCTION 2 */

/**
 * display_magic - Displays the magic numbers from an ELF file_header.
 * @e_ident: A reference to an array holding the magic numbers
 * associated with ELF.
 *
 * Description: Spaces delimit the magic numbers.
 */
void display_magic(unsigned char *e_ident)
{
	int position;

	printf(" Magic: ");

	for (position = 0; position < EI_NIDENT; position++)
	{
		printf("%02x", e_ident[position]);

		if (position == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/* FUNCTION 3 */

/**
 * display_class - Displays the class information from an ELF file_header.
 * @e_ident: A reference to an array holding the ELF class
 * information.
 */
void display_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/* FUNCTION 4 */

/**
 * display_data - Displays the data information from an ELF file_header.
 * @e_ident: A reference to an array holding the ELF data
 * information.
 */
void display_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/* FUNCTION 5 */

/**
 * display_version - Displays the version information from an ELF
 * file_header.
 * @e_ident: A reference to an array holding the ELF version
 * information.
 */
void display_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/* FUNCTION 6 */

/**
 * display_osabi - Displays the OS/ABI information from an ELF file_header.
 * @e_ident: A reference to an array holding the ELF OS/ABI
 * information.
 */
void display_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
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
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/* FUNCTION 7 */

/**
 * display_abi - Displays the ABI version information from an ELF file_header.
 * @e_ident: Shows a reference to an array holding the ELF ABI version
 * information.
 */
void display_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/* FUNCTION 8 */

/**
 * display_type - Displays the type information from an ELF file_header.
 * @elf_type: The type of the ELF.
 * @e_ident: A reference to an array holding the ELF class information.
 */
void display_type(unsigned int elf_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		elf_type >>= 8;

	printf(" Type: ");

	switch (elf_type)
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
		printf("<unknown: %x>\n", elf_type);
	}
}

/* FUNCTION 9 */

/**
 * display_entry - Displays the entry point information from an ELF
 * file_header.
 * @elf_entry_point: The location of the ELF entry point.
 * @e_ident: A reference to an array holding the ELF class
 * information.
 */
void display_entry(unsigned long int elf_entry_point,
unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		elf_entry_point = ((elf_entry_point << 8) & 0xFF00FF00) |
			((elf_entry_point >> 8) & 0xFF00FF);
		elf_entry_point = (elf_entry_point << 16) | (elf_entry_point >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)elf_entry_point);

	else
		printf("%#lx\n", elf_entry_point);
}

/* FUNCTION 10 */

/**
 * shut_down_elf - Shuts down an ELF file.
 * @ele_file: The file descriptor associated with the ELF file.
 *
 * Description: Exit with code 98 if the file cannot be closed.
 */
void shut_down_elf(int ele_file)
{
	if (close(ele_file) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", ele_file);
		exit(98);
	}
}

/* main */

/**
 * main - Prints the information from the ELF file_header
 * at the beginning of an ELF file.
 * @argumentsc: The count of arguments provided to the program.
 * @argumentsv: A collection of pointers pointing to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exit with code 98 if the file is not an ELF file
 * or if the operation encounters an error.
 */
int main(int __attribute__((__unused__)) argumentsc, char *argumentsv[])
{
	Elf64_Ehdr *file_header;
	int x, y;

	x = open(argumentsv[1], O_RDONLY);
	if (x == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argumentsv[1]);
		exit(98);
	}
	file_header = malloc(sizeof(Elf64_Ehdr));
	if (file_header == NULL)
	{
		shut_down_elf(x);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argumentsv[1]);
		exit(98);
	}
	y = read(x, file_header, sizeof(Elf64_Ehdr));
	if (y == -1)
	{
		free(file_header);
		shut_down_elf(x);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argumentsv[1]);
		exit(98);
	}

	verify_elf(file_header->e_ident);
	printf("ELF Header:\n");
	display_magic(file_header->e_ident);
	display_class(file_header->e_ident);
	display_data(file_header->e_ident);
	display_version(file_header->e_ident);
	display_osabi(file_header->e_ident);
	display_abi(file_header->e_ident);
	display_type(file_header->e_type, file_header->e_ident);
	display_entry(file_header->e_entry, file_header->e_ident);

	free(file_header);
	shut_down_elf(x);
	return (0);
}
