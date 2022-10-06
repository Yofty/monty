#define _POSIX_C_SOURCE 200809L
#include "monty.h"
/**
 * textfile_to_array - reads a text file and prints it
 * @filename : pointer to file
 * Return: the number of letters
 */
line_t *textfile_to_array(const char *filename)
{
	FILE *file;
	char *lineBuffer;
	size_t size = 0;
	int lineNumber = 0;
	line_t *lines;
	line_t *tmp;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	lineBuffer = NULL;

	lines = NULL;

	while (getline(&lineBuffer, &size, file) != -1)
	{
		tmp = realloc(lines, sizeof(line_t) * (lineNumber + 2));
		if (tmp == NULL)
		{
			fclose(file);
			return (0);
		}
		lines = tmp;

		(lines + lineNumber)->content = strdup(lineBuffer);
		(lines + lineNumber)->number = lineNumber;
		lineNumber++;
		tmp = lines;
	}
	free(lineBuffer);
	(lines + lineNumber)->content = NULL;
	fclose(file);
	return (lines);
}
