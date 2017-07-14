#include "shell.h"

/**
 * link_dir - build a linked list of the PATH directories
 *
 * Return: a pointer to the head of the linked list
 */

dir_t **link_dir(dir_t **head)
{
	char *dirs;
	char *dir;

	dirs = _getenv("PATH");
	dir = strtok(dirs, ":");

	while (dir)
	{
		add_nodedir_end(head, dir);
		dir = strtok(NULL, ":");
	}
	return (head);
}
