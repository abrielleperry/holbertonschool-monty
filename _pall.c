#include "monty.h"

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;  /*line_num unused for pall -silences compiler warning*/

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
