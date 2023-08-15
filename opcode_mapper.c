#include "monty.h"


void (*opfunc_mapper(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		/* ... add other opcodes and their functions here ... */
		{NULL, NULL}
	};

	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL); /* Return NULL if opcode not found */
}
