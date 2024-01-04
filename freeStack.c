#include "monty.h"

/**
 * freeStack - frees nodes
 * @stack: stack
 */
void freeStack(stack_t *stack)
{
	stack_t *temp = stack;

	for (; temp != NULL; temp = temp->next)
	{
		if (temp->prev != NULL)
			free(temp->prev);
		else if (temp->next == NULL)
			free(temp);
	}
}
