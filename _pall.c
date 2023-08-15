#include "monty.h"

/**
 * _pall - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the instruction appears.
 * Description: Iterates through the stack and prints each integer value,
 * followed by a new line. If the stack is empty, nothing is printed.
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;  /*line_num unused for pall -silences compiler warning*/
	stack_t *temp = *stack;

	while (temp && temp->next)
	{
		temp = temp->next;
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
