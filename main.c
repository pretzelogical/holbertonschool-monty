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
	{
		fclose(file);
		exit(EXIT_FAILURE);
	}
	get_line(file);
	instruction = parse_line(file->buf);
	while (instruction.status != 's')
	{
		if (instruction.status == 'u')
		{
			fprintf(stderr, "L<%d>: unknown instruction <%s>\n",
				file->linenum);
			error_out(file, stack);
			exit(EXIT_FAILURE);
		}
		value = instruction.n; /* we have to use an external int instead
								of putting it in the struct because betty
								said */
		/* execute function here */
		get_line(file);
		instruction = parse_line(file->buf);
	}

	free_stack(*stack);
	close_file(file);
	return (0);
}
