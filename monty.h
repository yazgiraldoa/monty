#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Prototypes*/
char **tokenizer(char *s, char *delim);
int count_words(char *str);
void (*get_instruction(char *s))(stack_t **stack, unsigned int line_number);
void ev(char **tokens, stack_t **stack, unsigned int num_line, FILE *file);

/*Free function*/
void free_stack(stack_t **stack);

/*Error messages*/
void error_arguments(void);
void error_open(char **av);
void error_malloc(void);
void error_command(int num_line, char **tokens, stack_t **stack, FILE *file);

/*Error validations*/
void error_push(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_pint(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_pop(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_swap(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_add(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_sub(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_div(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_mul(int num_line, char **tokens, stack_t **stack, FILE *file);
void error_mod(int num_line, char **tokens, stack_t **stack, FILE *file);

/*Command functions*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

static const instruction_t op_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{NULL, NULL}
};

#endif /* MONTY_H */