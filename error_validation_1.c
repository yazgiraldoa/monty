#include "monty.h"

/**
 * error_push - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_push(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	int i = 0;

	if (tokens[1] == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num_line);
		free(tokens[0]);
		free(tokens);
		free_stack(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	while (tokens[1][i] != '\0')
	{
		if (tokens[1][i] == 45 && tokens[1][i + 1] == '\0')
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_line);
			free(tokens[0]);
			free(tokens);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		else if (tokens[1][i] == 45)
		{
			i++;
			continue;
		}
		else if (tokens[1][i] < 48 || tokens[1][i] > 57)
		{
			fprintf(stderr, "L%d: usage: push integer\n", num_line);
			free(tokens[0]);
			free(tokens);
			free_stack(stack);
			fclose(file);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	node_data = atoi(tokens[1]);
}

/**
 * error_pint - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_pint(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num_line);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * error_pop - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_pop(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num_line);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * error_swap - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_swap(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 * error_add - function that prints an error message and
 * exit the program.
 * @num_line: number of line in file where we found the command.
 * @tokens: tokenized string passed by parameter.
 * @stack: top pointer of a doubly linked list.
 * @file: pointer to the open file.
 * Return: nothing.
 */

void error_add(int num_line, char **tokens, stack_t **stack, FILE *file)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num_line);
		free_stack(stack);
		free(tokens[0]);
		free(tokens);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
