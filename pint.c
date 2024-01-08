#include "monty.h"

/**
 * pint - print head of stack
 * @stack: stack
 * @line_number: line number where command occured
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(glob.fd);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
