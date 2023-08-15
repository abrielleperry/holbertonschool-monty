#include "monty.h"

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
