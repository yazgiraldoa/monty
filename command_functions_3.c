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
