#include "monty.h"
/**
 * _pint - prints the stack
 * @head: head of the stack
 * @line: line number
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;
	(void)line;
	temp = *head;
	if (temp == NULL)
	{
		return;
	}
	printf("%d\n", temp->n);
}
