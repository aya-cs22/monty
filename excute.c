#include "monty.h"
/**
* execute - executes the program
* @content: the program
* @counter: the line number
* @ptr_first_node: pointer to the first node of the stack
* Return: 1 if success, 0 if error
*/
int execute(char *content, unsigned int counter, stack_t **ptr_first_node)
{
	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
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
