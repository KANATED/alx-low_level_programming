#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * error_exit - Prints an error message and exits with the given exit code.
 * @exit_code: The exit code to return.
 * @message: The error message to print.
 */
void error_exit(int exit_code, const char *message)
{
    dprintf(STDERR_FILENO, "%s\n", message);
    exit(exit_code);
}

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, or an exit code on failure.
 */
int main(int argc, char *argv[])
{
    int fd_from, fd_to, bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

    if (argc != 3)
        error_exit(97, "Usage: cp file_from file_to");

    fd_from = open(argv[1], O_RDONLY);
    if (fd_from == -1)
        error_exit(98, "Error: Can't read from file");

    fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
    if (fd_to == -1)
        error_exit(99, "Error: Can't write to file");

    while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
    {
        bytes_written = write(fd_to, buffer, bytes_read);
        if (bytes_written == -1 || bytes_written != bytes_read)
            error_exit(99, "Error: Can't write to file");
    }

    if (bytes_read == -1)
        error_exit(98, "Error: Can't read from file");

    if (close(fd_from) == -1)
        error_exit(100, "Error: Can't close fd");

    if (close(fd_to) == -1)
        error_exit(100, "Error: Can't close fd");

    return 0;
}
