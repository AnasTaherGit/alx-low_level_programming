#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_elf_header - Print ELF header information
 * @header: pointer to the ELF header structure
 */
void print_elf_header(Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	printf(header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32\n" : "ELF64\n");
	printf("  Data:                              ");
	printf(header->e_ident[EI_DATA] == ELFDATA2LSB ?
	 "2's complement, little endian\n" : "2's complement, big endian\n");
	printf("  Version:                           ");
	printf("%d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	printf(header->e_ident[EI_OSABI] == ELFOSABI_SYSV ?
	 "UNIX - System V\n" : "<unknown: %x>\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       ");
	printf("%d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	if (header->e_type == ET_NONE)
		printf("NONE (No file type)\n");
	else if (header->e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (header->e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (header->e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (header->e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", header->e_type);
	printf("  Entry point address:               ");
	printf("0x%lx\n", header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: argument count
 * @argv: array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t read_len;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}

	read_len = read(fd, &header, sizeof(header));
	if (read_len < 0)
	{
		fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}
	if (read_len < (ssize_t)sizeof(header) ||
		header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "Error, %s is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}
	print_elf_header(&header);
	if (close(fd) < 0)
	{
		fprintf(stderr, "Error: Can't close file descriptor %d\n", fd);
		exit(98);
	}
	return (0);
}
