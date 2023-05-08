#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void error_and_exit(char *message, int error_code, char *file_name);

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, exit with specified error code on failure
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd;
	ssize_t read_bytes, write_bytes;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_and_exit("Usage: cp file_from file_to", 97, "");

	src_fd = open(argv[1], O_RDONLY);
	if (src_fd == -1)
		error_and_exit("Error: Can't read from file ", 98, argv[1]);

	dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC,
				   S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (dest_fd == -1)
		error_and_exit("Error: Can't write to ", 99, argv[2]);

	while ((read_bytes = read(src_fd, buffer, BUFFER_SIZE)) > 0)
	{
		write_bytes = write(dest_fd, buffer, read_bytes);
		if (write_bytes == -1 || write_bytes != read_bytes)
			error_and_exit("Error: Can't write to ", 99, argv[2]);
	}

	if (read_bytes == -1)
		error_and_exit("Error: Can't read from file ", 98, argv[1]);

	if (close(src_fd) == -1)
		error_and_exit("Error: Can't close fd ", 100, "");

	if (close(dest_fd) == -1)
		error_and_exit("Error: Can't close fd ", 100, "");

	return (0);
}

/**
 * error_and_exit - prints an error message and
 *  exits with a specified error code
 * @message: error message to print
 * @error_code: exit code
 * @file_name: name of the file associated with the error
 */
void error_and_exit(char *message, int error_code, char *file_name)
{
	dprintf(STDERR_FILENO, "%s%s\n", message, file_name);
	exit(error_code);
}
