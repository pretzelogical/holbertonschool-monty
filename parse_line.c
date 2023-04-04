#include "monty.h"

/**
 * get_line- copies line to file->buf and increments line number
 * @file: file struct to operate on
 *
 * Return: void return
*/
void get_line(file_t *file)
{
	file->linenum++;
	file->status = fgets(file->buf, BUFFER_SIZE, file->script);
}

/**
 * parse_line- Takes a buffer of a line and parses opcode and element
 * @file: the current file that is open
 *
 * Description: this will walk a line until it reaches the first
 * letter in which case it will check the current and next 3 characters to
 * check if they are a valid opcode
 * Return: Return parsed line struct with status indicated in status
 * char (see parsed_line_t)
*/
parsed_line_t parse_line(char *buf)
{
	char *opcode;
	int i;
	parsed_line_t out;
	instruction_t instructions[] = {
		{"push", push_stack},
		/*{"pall", print_stack_all}*/
		{NULL, NULL} 
	};

	opcode = strtok(buf, " \n\t\r");
	if (!opcode)
	{
		free(opcode);
		out.status = 's';
		return (out);
	}

	for (i = 0; strcmp(instructions[i].opcode, opcode) != 0; i++)
	{

		if (instructions[i].opcode == NULL)
		{
			free(opcode);
			out.status = "u";
			return (out);
		}

	}

	value = atoi(strtok(NULL, " \n\t\r"));
	out.op.opcode = instructions[i].opcode;
	out.op.f = instructions[i].f;
	out.status = "c";
	return (out);
}
