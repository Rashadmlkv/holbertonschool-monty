#include "monty.h"

/**
 * freeStack - frees a stack
 * @stack: top of stack
 */
void freeStack(void)
{
	stack_t *temp;

	while (glob.top)
	{
		temp = glob.top;
		glob.top = glob.top->next;
		free(temp);
	}
}
