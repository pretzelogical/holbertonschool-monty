#include "monty.h"

/**
 * parse_line- Takes a buffer of a line and parses opcode and element
 * @file: the current file that is open
 *
 * Description: this will walk a line until it reaches the first
 * letter in which case it will check the current and next 3 characters to
 * check if they are a valid opcode
 * Return: Return matching instruction or NULL at end of file
*/
instruction_t parse_line(char *buf)
{
	while (buf != '\0')
	{
		printf("%c", buf);

		
	}

}