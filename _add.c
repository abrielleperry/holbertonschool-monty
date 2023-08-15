#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number where the add opcode appears.
 * Description:
 * If the stack contains less than two elements, prints an error message
 * with the line number where the error occurred and exits the program
 * with the status EXIT_FAILURE.
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
