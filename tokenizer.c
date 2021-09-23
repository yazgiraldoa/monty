#include "monty.h"
#define OUT 0
#define IN 1

/**
 * tokenizer - Function that split a string.
 * @s: string to split.
 * @delim: words delimiter.
 * Return: a char double pointer that contains splited words.
 */

char **tokenizer(char *s, char *delim)
{
	int i = 0, cword = 0;
	char **splited_words = NULL;

	cword = count_words(s);

	splited_words = malloc(sizeof(char *) * (cword + 1));
	if (splited_words == NULL)
	{
		free(s);
		error_malloc();
	}

	splited_words[0] = strtok(s, delim);

	if (splited_words[0] == NULL)
	{
		free(splited_words[0]);
		free(splited_words);
		return (NULL);
	}

	for (i = 1; i < cword; i++)
	{
		splited_words[i] = strtok(NULL, delim);
	}
	splited_words[i] = NULL;
	return (splited_words);
}

/**
 * count_words - function that counts words depending on delimiters
 * @str: string to be evaluated.
 * Return: number of words in the string.
 */

int count_words(char *str)
{
	int state = OUT;
	unsigned int wc = 0;

	while (*str)
	{
		if (*str == ' ' || *str == '\n' || *str == '\t')
			state = OUT;
		else if (state == OUT)
		{
			state = IN;
			++wc;
		}
		++str;
	}
	return (wc);
}
