#include "monty.h"

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
	if (file != NULL)
		free(file);
}
