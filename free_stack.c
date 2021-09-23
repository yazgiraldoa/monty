#include "monty.h"

/**
 * free_stack - function that frees a stack_t stack.
 * @stack: top pointer of a doubly linked list.
 * Return: nothing.
 */

void free_stack(stack_t **stack)
{
		stack_t *aux;

		while (*stack)
		{
			aux = *stack;
			*stack = (*stack)->prev;
			free(aux);
		}
}
