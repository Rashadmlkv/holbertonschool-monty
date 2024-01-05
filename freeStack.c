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
		printf("Clean: %d\n", temp->n);
		glob.top = glob.top->next;
		free(temp);
	}
	free(glob.top);
        free(glob.buffer);
}
