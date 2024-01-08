#include "monty.h"
/**
 * freeStack - frees a stack
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
	free(glob.top);
	free(glob.buffer);
	fclose(glob.fd);
}
