#include "monty.h"

int main(int argc, char *argv[])
{
	if (argc != 2) /* check if there is one argument */
	{
		fprintf(stderr, "Usage: monty <file>\n");
		exit(EXIT_FAILURE);
	}
	FILE *fileReader = fopen(argv[1], "r"); /* open file */

	if (fileReader == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

read_file(fileReader); /* call read file to read contents of file */
fclose(fileReader); /* close file */
/* Declare variables */
char *line;
int line_number = 1;
/* Loop over each line in the file */
while (getline(&line, NULL, fileReader) != -1)
{
	char **tokens = tokenize_line(line); /* tokenize line */
	char *instruction = tokens[0]; /* get instructions */

	int (*instruction_function)(stack_t **stack, unsigned int line_number) =
		get_instruction_function(instruction);
	if (instruction_function == NULL)
	{
		fprintf(stderr, "Unknown instruc %s at line %d\n", instruction, line_number);
		exit(EXIT_FAILURE);
	}
	instruction_function(stack, line_number);
	for (int i = 0; tokens[i] != NULL; i++) /* free tokens */
	{
		free(tokens[i]);
	}
	free(tokens);
	line_number++;
}
return (0);
}

void open_file(char *filename)
{
	/* Check if filename is NULL */
	if (filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	/* Check if file exists and is readable */
	int fileCheck = access(filename, R_OK);

	if (fileCheck == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Open file in read mode */
	FILE *fileReader = fopen(filename, "r");

	if (fileReader == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Call read_file to read the contents of the file */
	read_file(fileReader);

	/* Close the file */
	fclose(fileReader);
}


void read_file(FILE *fileReader)
{
	/* Declare variables */
	int i;
	char *line = NULL;
	size_t line_size = 0;

	/* Read file line by line */
	for (i = 1; getline(&line, &line_size, fileReader) != -1; i++)
	{
		/* Tokenize line */
		tokenize_line(line);
	}
	/* Free line memory */
	free(line);
}
