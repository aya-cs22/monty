#include "monty.h"
/**
* execute - Executes an opcode on a stack.
* @line: The line containing the opcode to execute.
* @line_number: The line number of the opcode in the input file.
* @stack: A pointer to the top of the stack.
* Return: 0 if the opcode is a comment or if the line is empty, 1 otherwise.
*/
int execute(char *content, unsigned int counter, stack_t **ptr_first_node)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	int i = 0;
	int found = 0;
	char *opcode;


	opcode = strtok(content, " \t\n");
	if (!opcode || *opcode == '#' || opcode[0] == '#')
	{
		return (0);
	}
	while (opcodes[i].opcode != NULL && opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(ptr_first_node, counter);
			found = 1;
			break;
		}
		i++;
	}
	if (found == 0)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", counter, opcode);
		exit(EXIT_FAILURE);
	}
	return (1);
}
