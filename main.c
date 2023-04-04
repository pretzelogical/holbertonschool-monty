#include "monty.h"

/**
 * main- monty scripting language
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: Return 0 unless code fails and exits;
*/
int main(int argc, char **argv)
{
	file_t *file;
	parsed_line_t instruction;
	stack_t **stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	file = open_file(argv[1]);
	if (file == NULL)
		exit(EXIT_FAILURE);
	
	get_line(file);
	instruction = parse_line(file->buf);
	while ()
	{
		if (instruction.f == NULL)
		{
			fprintf(stderr, "L<%d>: unknown instruction <%s>\n",
			file->linenum + 1, instruction.opcode);

		}
		instruction.f(stack, file->linenum);
		instruction = parse_line(fgets(file->buf, BUFFER_SIZE, file->script));
	}

	free_stack(*stack);
	close_file(file);
	return (0);
}
