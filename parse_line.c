#include "monty.h"

/**
 * get_line- copies line to file->buf and increments line number
 * @file: file struct to operate on
 *
 * Return: void return
*/
void get_line(file_t *file)
{
	fgets(file->buf, BUFFER_SIZE, file->script);
	file->linenum++;
}

/**
 * parse_line- Takes a buffer of a line and parses opcode and element
 * @file: the current file that is open
 *
 * Description: this will walk a line until it reaches the first
 * letter in which case it will check the current and next 3 characters to
 * check if they are a valid opcode
 * Return: Return matching instruction or NULL at end of file
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
		return(out);
	}

	
	}

}