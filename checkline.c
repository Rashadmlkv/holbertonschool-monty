#include "monty.h"
/**
 * checkline - parses line & pushes into checkop & execute if success
 * @fd: file description
 * Return: doesn't
 */
int checkline(FILE *fd)
{
	unsigned int linenumber = 0;
	size_t max = 0;
	char *token = NULL;

	for (linenumber = 1; (getline(&glob.buffer, &max, fd)) > 0; linenumber++)
	{
		token = strtok(glob.buffer, " \t\n");
		if (token)
		{
			glob.f = checkop(token, linenumber);
			token = strtok(NULL, " \t\n");
			glob.num = token;
			glob.f(&glob.top, linenumber);
		}
	}
	return (0);
}
