#include "monty.h"


void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num;


	if (global_value == NULL || !is_digit(global_value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	num = atoi(global_value);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}

	stack_t *temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev = temp;
}


int is_digit(char *string)
{
	if (!string)
		return (0);
	if (*string == '-')
		string++;
	while (*string)
	{
		if (!isdigit(*string))
			return (0);
		string++;
	}
	return (1);
}
