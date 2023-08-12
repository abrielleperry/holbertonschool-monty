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

	read_file(fileReader);

	fclose(fileReader);
}

void read_file(FILE *fileReader)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;
	stack_t *stack = NULL;

	while ((read = getline(&line, &len, fileReader)) != -1)
	{
		process_line(line, line_number, &stack);
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


	void (*exe_opcode)(stack_t **, unsigned int);
	exe_opcode = opfunc_mapper(opcode);

	if (exe_opcode == NULL)
	{
		fprintf(stderr, "Unknown instruction %s at line %d\n", opcode, line_number);
		exit(EXIT_FAILURE);
	}

	exe_opcode(stack, line_number);
	
}
