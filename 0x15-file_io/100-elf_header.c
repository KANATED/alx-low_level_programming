#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

#define ERR_EXIT 98

void print_error(const char *msg)
{
    dprintf(STDERR_FILENO, "%s\n", msg);
    exit(ERR_EXIT);
}

void print_elf_header(const Elf64_Ehdr *header)
{
    int i;
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
        printf("%02x ", header->e_ident[i]);
    printf("\n");

    printf("  Class:                             ");
    switch (header->e_ident[EI_CLASS])
    {
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown>\n");
    }

    printf("  Data:                              ");
    switch (header->e_ident[EI_DATA])
    {
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown>\n");
    }

    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

    printf("  OS/ABI:                            ");
    switch (header->e_ident[EI_OSABI])
    {
    case ELFOSABI_SYSV:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    default:
        printf("<unknown: %02x>\n", header->e_ident[EI_OSABI]);
    }

    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

    printf("  Type:                              ");
    switch (header->e_type)
    {
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    default:
        printf("<unknown>\n");
    }

    printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr elf_header;
    ssize_t bytes_read;

    if (argc != 2)
        print_error("Usage: elf_header elf_filename");

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        print_error("Error opening the file");

    bytes_read = read(fd, &elf_header, sizeof(elf_header));
    if (bytes_read == -1)
        print_error("Error reading the file");

    if (bytes_read != sizeof(elf_header))
        print_error("Invalid ELF file");

    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3)
        print_error("Not an ELF file");

    print_elf_header(&elf_header);

    close(fd);
    return 0;
}
