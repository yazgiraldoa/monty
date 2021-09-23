#define  _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * main - main function of Monty interpreter.
 * @ac: number of argumments passed by parameter.
 * @av: array with argumments passed by parameter.
 * Return: success is 0.
 */

int main(int ac, char **av)
{
	char *line = NULL, **tokens = NULL;
	FILE *file = NULL;
	unsigned int num_line = 0;
	size_t line_size = 0;
	stack_t *stack = NULL;
	(void) ac;

	if (ac != 2)
		error_arguments();

	file = fopen(av[1], "r");
	if (!file)
		error_open(av);

	while (getline(&line, &line_size, file) != -1)
	{
		num_line++;
		tokens = tokenizer(line, "\n\t ");
		if (tokens == NULL)
			continue;
		if (tokens[0][0] != '#')
			ev(tokens, &stack, num_line, file);
		free(tokens);
	}
	free(line);
	free_stack(&stack);
	fclose(file);
	return (0);
}

/**
 * ev - function that validates all errors in functions.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void ev(char **tokens, stack_t **stack, unsigned int num_line, FILE *file)
{
	void (*f)(stack_t **, unsigned int);

	if (strcmp(tokens[0], "push") == 0)
		error_push(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "pint") == 0)
		error_pint(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "pop") == 0)
		error_pop(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "swap") == 0)
		error_swap(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "add") == 0)
		error_add(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "sub") == 0)
		error_sub(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "div") == 0)
		error_div(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "mul") == 0)
		error_mul(num_line, tokens, stack, file);
	else if (strcmp(tokens[0], "mod") == 0)
		error_mod(num_line, tokens, stack, file);

	f = get_instruction(tokens[0]);
	if (!f)
		error_command(num_line, tokens, stack, file);
	f(stack, num_line);
}
