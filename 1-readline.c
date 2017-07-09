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

	w_prpt = write(STDOUT_FILENO, "$ ", 2);
	if (w_prpt == -1)
		perror("Error: cannot display prompt\n");
	usr_comd = getline(&buf, &size, stdin);
	if (usr_comd == -1)
		perror("Error: cannot read line\n");
	w_comd = write(STDOUT_FILENO, buf, size);
	if ((size_t) w_comd != size)
		perror("Error: cannot display input\n");
	free(buf);
	return (0);
}