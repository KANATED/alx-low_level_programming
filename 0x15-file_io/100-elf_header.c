#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_elf_info - Prints information from the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void print_elf_info(Elf64_Ehdr *header) {
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x\n", header->e_ident[0], header->e_ident[1], header->e_ident[2], header->e_ident[3]);
    printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
    printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            %s\n", header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Other");
    printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("  Type:                              %s\n", header->e_type == ET_REL ? "REL (Relocatable file)" : "Other");
    printf("  Entry point address:               0x%lx\n", header->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 98;
    }

    Elf64_Ehdr elf_header;
    ssize_t bytes_read = read(fd, &elf_header, sizeof(elf_header));

    // Check if the read operation was successful and if it's an ELF file
    if (bytes_read != sizeof(elf_header) || elf_header.e_ident[EI_MAG0] != ELFMAG0 || elf_header.e_ident[EI_MAG1] != ELFMAG1 || elf_header.e_ident[EI_MAG2] != ELFMAG2 || elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: Not an ELF file\n");
        close(fd);
        return 98;
    }

    // Print information from the ELF header
    print_elf_info(&elf_header);

    close(fd);
    return 0;
}
