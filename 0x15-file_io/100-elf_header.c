#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_elf_header(Elf64_Ehdr *elf_header)
{
    int i; /* Declare variable outside the for loop (compatible with C90) */
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             ");
    switch (elf_header->e_ident[EI_CLASS])
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
    switch (elf_header->e_ident[EI_DATA])
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
    printf("  Version:                           %d (current)\n", elf_header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (elf_header->e_ident[EI_OSABI])
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
            printf("<unknown: %d>\n", elf_header->e_ident[EI_OSABI]);
    }
    printf("  ABI Version:                       %d\n", elf_header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (elf_header->e_type)
    {
        case ET_NONE:
            printf("NONE (Unknown type)\n");
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
            printf("<unknown>\n");
    }
    printf("  Entry point address:               0x%lx\n", elf_header->e_entry);
}

int main(int argc, char *argv[])
{
    int fd;
    Elf64_Ehdr elf_header;

    /* Check if the correct number of arguments is provided */
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(97);
    }

    /* Open the ELF file */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
        exit(98);
    }

    /* Read the ELF header */
    if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    /* Print the ELF header information */
    print_elf_header(&elf_header);

    /* Close the file descriptor */
    if (close(fd) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close file %s\n", argv[1]);
        exit(100);
    }

    return 0;
}
