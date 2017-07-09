#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * main - entry point
 *
 * Return: 0 if successful
 */

int main(void)
{
	ssize_t w_prpt, w_comd, usr_comd;
	size_t size;
	char *buf;

	buf = NULL; /* getline()  mallocs memory with appropriate size
		     * when buf == NULL
		     */

	if (write(STDOUT_FILENO, "$ ", 2) == -1)
	{
		perror("Error: cannot display prompt\n");
		return (-1);
	}

	if (getline(&buf, &size, stdin) == -1)
	{
		perror("Error: cannot read line\n");
		return (-1);
	}

	w_comd = write(STDOUT_FILENO, buf, size);
	if ((size_t) w_comd != size)
	{
		perror("Error: cannot display input\n");
		free(buf);
		return (-1);
	}
	free(buf);
	return (0);
}
