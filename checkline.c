#include "monty.h"


/**
 * checkline - parses line & pushes into checkop & execute if success
 * @fd: file description
 * @str: filename
 * Return: doesn't
 */
int checkline(FILE *fd, char *str)
{
	int i = 0;
	size_t max = 0;
	char *token = NULL;
	glob.top = malloc(sizeof(stack_t));
	glob.top = NULL;

	for (i = 1; (getline(&str, &max, fd)) != -1; i++)
	{
		token = strtok(str, " \t$\n");
		if (token)
		{
			glob.f = checkop(token, i);
			token = strtok(NULL, " \t$\n");
			if (token)
				glob.num = token;
			glob.f(&glob.top, i);
		}
	}
	freeStack();
	return (0);
}
