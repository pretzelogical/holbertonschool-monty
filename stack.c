#include "monty.h"

/**
 * This file contains the functions used to manage stacks
*/

/**
 * create_stack- creates the head of a new stack and returns it
 *
 * Return: newly created stack or NULL if fail
*/
stack_t **create_stack()
{
	stack_t **new;

	*new = malloc(sizeof(stack_t));
	if (!new || !*new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	(*new)->next = NULL;
	(*new)->prev = NULL;
	(*new)->n = 0;
	return (new);
}

/**
 * free_stack- frees a stack
 * @stack: head node of the stack you want to free
*/
void free_stack(stack_t *head)
{
	if (head->next)
		free_stack(head->next);

	free(head);
}

/**
 * push_stack- creates a stack if none exists and pushes a node onto it
 * @stack: stack to manage
 * @n: value to associate with node
 *
 * Return: void return
*/
push_stack(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		stack = create_stack();
		if (!stack)
			return;
	}
}
