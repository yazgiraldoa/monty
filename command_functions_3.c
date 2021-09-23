#include "monty.h"

/**
 * mod - function that computes the rest of the division
 * of second top element of stack by top element of stack.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = *stack;
	(void) line_number;

	*stack = (*stack)->prev;
	(*stack)->n = ((*stack)->n) % (aux1->n);
	(*stack)->next = NULL;
	free(aux1);
}

/**
 * pchar- function that prints the last element of a list as a char.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	printf("%c\n", (*stack)->n);
}

/**
 * pstr- function that prints all the elements of a list as str.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *aux = *stack;
	(void) line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

		while (aux != NULL && aux->n > 0 && aux->n < 128)
		{
			printf("%c", aux->n);
			aux = aux->prev;
		}
		printf("\n");
		return;

}
