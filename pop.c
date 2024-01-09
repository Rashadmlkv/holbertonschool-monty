#include "monty.h"

/**
 * pop - remove head element from stack
 * @stack: head of stack
 * @line_number: line number where command occured
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(glob.fd);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next, (*stack)->prev = NULL;
	free(tmp);
}
