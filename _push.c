#include "monty.h"

/**
 * _push - pushes integer on to the stack
 * @stack: The stack to push the integer onto
 * @line_number: line num in the file where the push instruction was found
 * Return: 0 if instruction successful or 1 if instruction failed
 */

int _push(stack_t **stack, unsigned int line_number)
{
	/* Check if there is an argument */
	if (argc < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Get the integer from the argument */
	int value = atoi(argv[1]);

	/* Push the integer onto the stack */
	stack_push(stack, value);

/* Return 0 if the push instruction was successful */
return (0);
}
