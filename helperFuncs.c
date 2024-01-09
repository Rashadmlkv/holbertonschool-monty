#include "monty.h"

/**
 * checkFile - checks aviability of file & given argument
 * @ac: arguments' count
 * @av: arguments' array
 */
void checkFile(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }

	glob.fd = fopen(av[1], "r");
	if (!glob.fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE); }
}


/**
 * checkLine - reads and parses the line
 * Return: getline's read status
 */
void checkLine(void)
{
	size_t max = 0;
	unsigned int line_number = 1;

	for (; getline(&glob.buffer, &max, glob.fd) != -1; line_number++)
	{
		glob.token = strtok(glob.buffer, " \t\n");
		if (glob.token)
		{
			glob.f = checkOp(glob.token, line_number);
			glob.token = strtok(NULL, " \t\n");
			glob.f(&glob.top, line_number); }
	}
}


/**
 * checkOp - checks given function's aviability
 * @str: function name
 * @line_number: function accured in file
 * Return: function adress in success, exits in failure
 */
void (*checkOp(char *str, unsigned int line_number))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
	};

		for (i = 0; strcmp(ops[i].opcode, str) != 0; i++)
		{
			if (ops[i + 1].opcode == NULL && ops[i].opcode != str)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
				freeStack();
				fclose(glob.fd);
				exit(EXIT_FAILURE);
			}
		}
	return (ops[i].f);
}


/**
 * freeStack - frees stack & closes file descriptor
 */
void freeStack(void)
{
	stack_t *temp = NULL;

	while (glob.top)
	{
		temp = glob.top;
		glob.top = glob.top->next;
		free(temp);
	}
	free(glob.top);
	free(glob.buffer);
}


/**
 * isDigit - check string is full of digits or not
 * @number: string
 * Return: if string is not digit return -1
 */
int isDigit(char *number)
{
	int i = 0;

	if (number)
	{
		if (number[i] == '-')
			++i;
		for (; number[i] != '\0'; i++)
		{
			if ((isdigit(number[i])) == 0)
				return (-1); }
		return (0);
	}
	return (-1);
}
