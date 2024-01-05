#include "monty.h"

/**
 * freeStack - frees a stack
 * @stack: top of stack
 */
void freeStack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
