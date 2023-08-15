#include "monty.h"


void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n; // Add the top two elements
	temp = *stack;
	*stack = (*stack)->next; // Move the pointer to the next element
	free(temp); // Free the old top element
}
