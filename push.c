#include "monty.h"
/**
 * push - pushes data into stack
 * @stack: top of stack
 * @line_number: command accured in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	if (isNumber(glob.num) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freeStack();
		fclose(glob.fd);
		exit(EXIT_FAILURE); }

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack();
		fclose(glob.fd);
		exit(EXIT_FAILURE); }

	new_node->n = atoi(glob.num);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
