#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - creates a file with specified content
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t write_bytes;
	size_t content_length = 0;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[content_length] != '\0')
			content_length++;

		write_bytes = write(fd, text_content, content_length);
		if (write_bytes == -1 || (size_t)write_bytes != content_length)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
