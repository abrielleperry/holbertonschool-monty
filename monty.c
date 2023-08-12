#include "monty.h"

char *global_value = NULL;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
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
		char **tokens = tokenize_line(line);
		char *instr_token = tokens[0];
		void (*exe_opcode)(stack_t **stack, unsigned int line_number);

		exe_opcode = opfunc_mapper(instr_token);

		if (exe_opcode == NULL)
		{
			fprintf(stderr, "Unknown instruction %s at line %d\n", instr_token, line_number);
			free(line);
			for (int i = 0; tokens[i] != NULL; i++)
			{
				free(tokens[i]);
			}
			free(tokens);
			fclose(fileReader);
			exit(EXIT_FAILURE);
		}

		exe_opcode(&stack, line_number);

		for (int i = 0; tokens[i] != NULL; i++)
		{
			free(tokens[i]);
		}
		free(tokens);

		line_number++;
	}
	free(line);
}
