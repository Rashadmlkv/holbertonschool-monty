#include "monty.h"
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *temp = *stack;

        for (; temp != NULL; temp = temp->next)
		printf("%d\n", temp->n);
}
