#include "monty.h"

/**
 * main - check input arguments
 * @ac: argument count
 * @av: array of arguments
 * Return: doesn't
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
		checkfile(av[1]);
	return (0);
}
