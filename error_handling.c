#include "monty.h"

/**
 * error_out- handles freeing and closing of files, buffer, stack...
 * after some part fails 
 * @file: file to close
 * @stack: stack to free
 *
 * Return: void return
*/
void error_out(FILE *file, stack_t **stack)
{
	free_stack(stack);
	close_file(file);
	return;
}
