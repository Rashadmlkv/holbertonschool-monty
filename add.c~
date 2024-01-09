#include "monty.h"

/**
 * add - adds top two elements of stack and make it top
 *
 * @stack: pointer to top of the stack
 * @line_number: line number of instruction
 */

void add(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *top;

	if (!stack || !*stack || !(*stack)->next)
	{
		free_glob();
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack);
	temp = (*stack)->n + (*stack)->next->n;
	(*stack)->next->prev = NULL;
	(*stack)->next->n = temp;
	*stack = (*stack)->next;
	free(top);
}
