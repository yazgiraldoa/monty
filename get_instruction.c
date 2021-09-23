#include "monty.h"

/**
* get_instruction - Function that look for a command.
* @s: string to be evaluated.
* Return: A function associated with the command name (success).
*/

void (*get_instruction(char *s))(stack_t **stack, unsigned int line_number)
{
	unsigned int j = 0;

	while (op_list[j].opcode != NULL)
	{
		if (strcmp(s, op_list[j].opcode) == 0)
		{
			return (op_list[j].f);
		}
		j++;
	}
	return (NULL);
}
