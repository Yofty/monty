#include "monty.h"
/**
 * split_line - parse file into list
 * @line : pointer to line
 * Return: pointer to the first token
 */
#define _TOK_DELIM " \t\r\n\a"
char **split_line(char *line)
{
	int position = 0;
	char **tokens = NULL, **tmp = NULL; *token;

	token = strtok(line, _TOK_DELIM);

	while (token != NULL)
	{
		tmp = realloc(tokens, sizeof(char *) * (position + 2));
		if (tmp == NULL)
		{
			printf(stderr, "sh: allocation error\n");
			exit(EXIT_FAILURE);
		}
		tokens = tmp;
		tokens[position] = token;
		token = strtok(NULL, _TOK_DELIM);
		position++;
	}
	tokens[position] = NULL;
	return (tokens);
}
