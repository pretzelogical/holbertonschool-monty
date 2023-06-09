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
	new->buf = malloc(sizeof(char) * BUFFER_SIZE);
	if (!new->buf)
	{
		fprintf(stderr, "Error: Malloc failed\n");
		close_file(new);
		return (NULL);
	}
	new->status = malloc(sizeof(char));
	if (!new->status)
	{
		fprintf(stderr, "Error: Malloc failed\n");
		close_file(new);
		return (NULL);
	}
	new->linenum = 0;
	return (new);
}

/**
 * close_file- closes a file_t file
 * @file: file to close
 *
 * Return: void return
*/
void close_file(file_t *file)
{
	if (file->script != NULL)
		fclose(file->script);
	if (file->buf != NULL)
		free(file->buf);
	if (file->status != NULL)
		free(file->status);
	if (file != NULL)
		free(file);
}
