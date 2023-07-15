#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

void error_exit(int exit_code, const char *message);
int main(int argc, char *argv[]);

void error_exit(int exit_code, const char *message);
void print_elf_header(Elf64_Ehdr *elf_header);
switch (elf_header->e_ident[EI_CLASS]);
switch (elf_header->e_ident[EI_DATA]);
switch (elf_header->e_ident[EI_OSABI]);
switch (elf_header->e_type);

int main(int argc, char *argv[]);

#endif /* MAIN_H */
