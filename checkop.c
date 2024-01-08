#include "monty.h"
/**
 * checkop - checks given function aviability
 * @str: function name
 * @line_number: function accured in file
 * Return: function adress in success, exits in failure
 */
void (*checkop(char *str, unsigned int line_number))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	for (i = 0; strcmp(ops[i].opcode, str) != 0; i++)
	{
		if (ops[i + 1].opcode == NULL && ops[i].opcode != str)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, str);
			freeStack();
			exit(EXIT_FAILURE);
		}
	}
	return (ops[i].f);
}
