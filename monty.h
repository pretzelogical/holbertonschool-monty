#ifndef MONTY_h
#define MONTY_h

#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 128

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack	 (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct file_s- file and associated data
 * @script: pointer to currently open file
 * @linenum: current line number (starting at 1)
 * 
*/
typedef struct file_s
{
	FILE *script;
	unsigned int linenum;
        char *buf;

}file_t;

extern int element;

file_t *open_file(char *filename);
void close_file(file_t *file);
stack_t **create_stack();
void free_stack(stack_t *head);
stack_t *push_stack(stack_t **stack, int n);
instruction_t parse_line(file_t *file);


#endif
