#include "monty.h"

/**
 * swap - swap elemts in stack
 * @stack: head of stack
 * @line_number: command occured in file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!(*stack)->next || !(*swap))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		freeStack();
		fclose(glob.fd);
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(stack_t));
	if(!tmp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack();
		fclose(glob.fd);
		exit(EXIT_FAILURE);
	}
	tmp->n = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp->n;
	free(tmp);
}
