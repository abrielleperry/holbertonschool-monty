#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty <file>\n");
		exit(EXIT_FAILURE);
	}
	
	open_file(argv[1]);
	
	return 0;
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
		char **tokens = tokenize_line(line);
		char *instruction = tokens[0];

		int (*instruction_function)(stack_t **stack, unsigned int line_number) = get_instruction_function(instruction);
		if (instruction_function == NULL)
		{
			fprintf(stderr, "Unknown instruction %s at line %d\n", instruction, line_number);
			free(line);
			for (int i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			fclose(fileReader);
			exit(EXIT_FAILURE);
		}

		instruction_function(&stack, line_number);
		
		for (int i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);

		line_number++;
	}
	free(line);
}
