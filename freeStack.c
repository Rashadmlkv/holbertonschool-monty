#include "monty.h"

/**
 * freeStack - frees a stack
 * @stack: top of stack
 */
void freeStack(void)
{
	stack_t *temp = NULL;

	while (glob.top)
	{
		temp = glob.top;
		glob.top = glob.top->next;
		free(temp);
	}
	temp = NULL;
	free(temp);
}
