#include "monty.h"

/**
 * _push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number where the instruction appears.
 * Description:
 * Verifies if the given string is a valid integer using is_digit function.
 * If the string is not an integer or if there is no argument given to push,
 * prints an error message with the line number where the error occurred and
 * exits the program with the status EXIT_FAILURE.
 */

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

/**
 * is_digit - Function to check if a character represents a dig
 * @string: The string to be checked.
 * Return: 1 if c is a digit, 0 otherwise
 * Description:
 * Iterates through each character of the given string, checking if each
 * character is a digit (0-9). If any character is not a digit, the function
 * returns 0, indicating that the string does not represent a valid integer.
 * If all characters are digits, the function returns 1, indicating that the
 * string does represent a valid integer.
 */

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
