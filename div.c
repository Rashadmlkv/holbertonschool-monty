#include "monty.h"

/**
 * division - divides second top element of the stack by top element
 *
 * @stack: pointer to top of the stack
 * @line_number: line number of instruction
 */

void division(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *top;

	if (!stack || !*stack || !(*stack)->next)
	{
		freeStack();
		dprintf(2, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = (*stack);
	temp = (*stack)->next->n / (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack)->next->n = temp;
	*stack = (*stack)->next;
	free(top);
}
