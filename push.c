#include "monty.h"
/**
 * push - pushes data into stack
 * @stack: top of stack
 * @line_number: command accured in file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	glob.token = strtok(NULL, " \t\n");
	if (isDigit(glob.token) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		freeStack();
		exit(EXIT_FAILURE); }

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack();
		exit(EXIT_FAILURE); }

	new_node->n = atoi(glob.token);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;

	printf("Integer: %d\n", new_node->n);
}
