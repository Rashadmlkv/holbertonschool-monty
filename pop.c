#include "monty.h"

/**
 * pop - remove head element from stack
 * @stack: head of stack
 * @line_number: line number where command occured
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;

	if (!stack || !(*stack))
	{
		fprintf(stderr,	"L%u: can't pop an empty stack\n", line_number);
		freeStack();
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
	if (*stack)
		(*stack)->prev = NULL;
}
