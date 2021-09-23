#include "monty.h"

/**
 * add - function that adds the top two elements of the stack.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = *stack;
	(void) line_number;

	*stack = (*stack)->prev;
	(*stack)->n = ((*stack)->n) + (aux1->n);
	(*stack)->next = NULL;
	free(aux1);
}

/**
 * nop - function that doesn’t do anything.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}

/**
 * sub - function that subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = *stack;
	(void) line_number;

	*stack = (*stack)->prev;
	(*stack)->n = ((*stack)->n) - (aux1->n);
	(*stack)->next = NULL;
	free(aux1);
}

/**
 * _div - function that  divides the second top element of the stack
 * by the top element of the stack.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = *stack;
	(void) line_number;

	*stack = (*stack)->prev;
	(*stack)->n = ((*stack)->n) / (aux1->n);
	(*stack)->next = NULL;
	free(aux1);
}

/**
 * mul - function that multiplies the top two elements of the stack.
 * @stack: top pointer of a doubly linked list.
 * @line_number: number of line in file where we found the command.
 * Return: nothing.
 */

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *aux1 = *stack;
	(void) line_number;

	*stack = (*stack)->prev;
	(*stack)->n = ((*stack)->n) * (aux1->n);
	(*stack)->next = NULL;
	free(aux1);
}
