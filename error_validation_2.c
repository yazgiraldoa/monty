#include "monty.h"

/**
 * error_sub - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_sub(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * error_div - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_div(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * error_mul - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_mul(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * error_mod - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_mod(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
