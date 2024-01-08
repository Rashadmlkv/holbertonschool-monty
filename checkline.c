#include "monty.h"
/**
 * checkline - parses line & pushes into checkop & execute if success
 * @fd: file description
 * Return: doesn't
 */
int checkline(FILE *fd)
{
	int i = 0;
	size_t max = 0;
	char *token = NULL;

	for (i = 1; (getline(&glob.buffer, &max, fd)) > 0; i++)
	{
		token = strtok(glob.buffer, " \t$\n");
		if (token)
		{
			glob.f = checkop(token, i);
			token = strtok(NULL, " \t$\n");
			if (token)
				glob.num = token;
			glob.f(&glob.top, i);
		}
	}
	return (0);
}
