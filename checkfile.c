#include "monty.h"

/**
 * checkfile - checks file status
 * @str: filename
 * Return: doesn't
 */
int checkfile(char *str)
{
	FILE *fd;

	fd = fopen(str, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str),
			exit(EXIT_FAILURE); }
	else
	{
		checkline(fd, str); }
	return (0);
}
