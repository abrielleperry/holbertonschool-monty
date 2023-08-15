#include "monty.h"

/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number where the instruction appears.
 */

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
