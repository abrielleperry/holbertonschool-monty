#ifndef MONTY_H
#define MONTY_H
#define DELIMITERS " \t\n"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Descript: doubly linked list node structure for stack, queues, LIFO FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Prototypes */
void open_file(char *filename);
void read_file(FILE *fileReader, stack_t **main_stack);
char **tokenize_line(char *line);
void (*opfunc_mapper(char *opcode))(stack_t **, unsigned int);
void _pall(stack_t **stack, unsigned int line_number);
void _push(stack_t **stack, unsigned int line_number);
extern char *global_value;
int is_digit(char *string);
void process_line(char *line, unsigned int line_number, stack_t **stack);
void free_stack(stack_t **stack);
void _pop(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);



#endif
