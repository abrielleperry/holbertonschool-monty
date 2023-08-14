#include "monty.h"

void free_stack(stack_t **stack)
{
	stack_t *current_node = *stack;
	stack_t *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
