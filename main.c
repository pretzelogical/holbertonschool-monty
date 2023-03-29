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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = open_file(argv[1]);
	if (file == NULL)
		exit(EXIT_FAILURE);

	close_file(file);
	return (0);
}
