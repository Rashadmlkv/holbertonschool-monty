#include "monty.h"

/**
 * sub - subtrackts top element of the stack from the second top element
 *
 * @stack: pointer to top of the stack
 * @line_number: line number of instruction
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *top;

	if (!stack || !*stack || !(*stack)->next)
	{
		freeStack();
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack);
	temp = (*stack)->next->n - (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack)->next->n = temp;
	*stack = (*stack)->next;
	free(top);
}
