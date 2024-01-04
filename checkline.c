#include "monty.h"


/**
 * checkline - parses line & pushes into checkop & execute if success
 * @fd: file description
 * @str: filename
 * Return: doesn't
 */
int checkline(FILE *fd, char *str)
{
	int i;
	size_t max = 0;
	char *token = NULL;
	void (*f)(stack_t **stack, unsigned int line_number);
	stack_t *top = malloc(sizeof(stack_t));

	for (i = 1; (getline(&str, &max, fd)) != -1; i++)
	{
		token = strtok(str, " \t$\n");
		if (token)
		{
			f = checkop(token, i);
			token = strtok(NULL, " \t$\n");
			if (token)
				num = token;
			f(&top, i);
		}
	}
	return (0);
}
