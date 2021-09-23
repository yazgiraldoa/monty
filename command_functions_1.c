#include "monty.h"


/**
 * push - function that adds a new node at the end of a list
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	(void) line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free_stack(stack);
		error_malloc();
	}
	new->n = node_data;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL)
	{
		*stack = new;
	}
	else
	{
		(*stack)->next = new;
		new->prev = *stack;
		*stack = new;
	}
}

/**
 * pall- function that prints all the elements of a list.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void) line_number;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->prev;
	}
}

/**
 * pop- function that deletes a node at the end of a list
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void) line_number;

	*stack = (*stack)->prev;
	if (*stack != NULL)
		(*stack)->next = NULL;
	free(aux);
}

/**
 * pint- function that prints the last element of a list.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	printf("%d\n", (*stack)->n);
}

/**
 * swap - function that swaps the top two elements of the stack.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;
	stack_t *aux1 = *stack, *aux2 = *stack;
	(void) line_number;

	aux1 = aux1->prev;
	temp = aux2->n;
	aux2->n = aux1->n;
	aux1->n = temp;
}
