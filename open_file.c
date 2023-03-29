#include "monty.h"

/**
 * open_file- opens a file and returns the pointer
 * @filename: name of the file to open
 *
 * Return: pointer to file or NULL if fail
*/
file_t *open_file(char *filename)
{
	file_t *new;

	new = malloc(sizeof(file_t));

	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		close_file(new);
		return (NULL);
	}
	new->script = fopen(filename, "r");
	if (!new->script)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		close_file(new);
		return (NULL);
	}
	new->linenum = 1;
	return (new);
}
