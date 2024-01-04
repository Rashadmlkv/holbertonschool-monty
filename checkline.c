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
	stack_t *top = malloc(sizeof(stack_t));
	void (*f)(stack_t **stack, unsigned int line_number);

	for (i = 1; (getline(&str, &max, fd)) != -1; i++)
	{
		token = strtok(str, " \t$\n");
		if (token)
		{
			f = checkop(token, i);
			token = strtok(NULL, " \t$\n");
			if (token)
			{
				glob.num = token;
			}
			f(&top, i);
		}
	}
	return (0);
}
