#include "monty.h"

/**
 * mul - multiplication of two top elements of the stack
 *
 * @stack: pointer to top of the stack
 * @line_number: line number of instruction
 */

void mul(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *top;

	if (!stack || !*stack || !(*stack)->next)
	{
		freeStack();
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = (*stack);
	temp = (*stack)->next->n * (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack)->next->n = temp;
	*stack = (*stack)->next;
	free(top);
}
