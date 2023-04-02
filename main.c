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
	instruction_t instruction;
	stack_t **stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	file = open_file(argv[1]);
	if (file == NULL)
		exit(EXIT_FAILURE);
	
	instruction = parse_line(fgets(file->buf, BUFFER_SIZE, file->script));
	while (instruction.opcode != NULL)
	{
		if (instruction.f == NULL)
		{
			fprintf(stderr, "L<%d>: unknown instruction <%s>\n",
			file->linenum + 1, instruction.opcode);

		}
		instruction.f(**stack)
	}

	free_stack(*stack);
	close_file(file);
	return (0);
}
