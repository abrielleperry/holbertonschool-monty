#include "monty.h"


void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num;


	if (global_value == NULL || !is_digit(global_value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(global_value);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->next = *stack;
	*stack = new_node;
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
