#include "monty.h"

#define DELIMITERS " \t\n"

char **tokenize_line(char *line)
{
	int buffer_size = 64;
	int position = 0;
	char **tokens = malloc(buffer_size * sizeof(char*));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(line, DELIMITERS);
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		position++;

	if (position >= buffer_size)
	{
		buffer_size += 64;
		tokens = realloc(tokens, buffer_size * sizeof(char*));
		
		if (!tokens)
		{
			fprintf(stderr, "Memory allocation error\n");
			exit(EXIT_FAILURE);
		}
	}

	token = strtok(NULL, DELIMITERS);
}
tokens[position] = NULL;
return tokens;
}
