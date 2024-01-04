#include "monty.h"

/**
 * pall - prints datas in stack
 * @stack: top of stack
 * @line_number: command occured in file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;

	for (; temp->next != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}
