#include "monty.h"

/**
 * error_arguments - function that prints an error message and
 * exit the program.
 * Return: nothing.
 */

void error_arguments(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error_open - function that prints an error message and
 * exit the program.
 * @av: array with argumments passed by parameter.
 * Return: nothing.
 */

void error_open(char **av)
{
	fprintf(stderr, "Error: Can't open file %s\n", av[1]);
	exit(EXIT_FAILURE);
}

/**
 * error_malloc - function that prints an error message and
 * exit the program.
 * Return: nothing.
 */

void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * error_command - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_command(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", num_line, tokens[0]);
	free(tokens[0]);
	free(tokens);
	free_stack(stack);
	fclose(file);
	exit(EXIT_FAILURE);
}
