#include "monty.h"

char *global_value = NULL;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_file(argv[1]);

	return (0);
}

void open_file(char *filename)
{
	stack_t *stack = NULL;

	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	int fileCheck = access(filename, R_OK);

	if (fileCheck == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	FILE *fileReader = fopen(filename, "r");

	if (fileReader == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	read_file(fileReader, &stack);
	fclose(fileReader);
	free_stack(&stack);
}

void read_file(FILE *fileReader, stack_t **main_stack)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;

	while ((read = getline(&line, &len, fileReader)) != -1)
	{
		process_line(line, line_number, main_stack);
		line_number++;
	}
	free(line);
}

void process_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode;
	char *value;

	opcode = strtok(line, " \t\n");
	if (opcode == NULL)
	{
		return;
	}

	value = strtok(NULL, " \t\n");
	global_value = value;

	void (*exe_opcode)(stack_t **, unsigned int) = opfunc_mapper(opcode);

	if (exe_opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	if (strcmp(opcode, "push") == 0)
	{
		if (value == NULL || !is_digit(value))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
	}
	exe_opcode(stack, line_number);

}

void free_stack(stack_t **stack)
{
	stack_t *temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

