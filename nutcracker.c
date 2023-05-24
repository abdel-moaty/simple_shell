#include "main.h"

/**
 * nutcracker - splits a string and returns an array of each word of the string
 * @input: input
 * @wordCount: word count
 * Return: Array of Words
 */
char **nutcracker(const char *input, int *wordCount)
{
	char *token, *copy, **words = NULL;
	const char *delimiters;
	int count = 0;

	copy = strdup(input);
	delimiters = " \t\n";
	token = strtok(copy, delimiters);
	while (token != NULL)
	{
		words = realloc(words, (count + 1) * sizeof(char *));
		words[count] = strdup(token);
		count++;
		token = strtok(NULL, delimiters);
	}
	free(copy);
	*wordCount = count;
	return (words);
}
