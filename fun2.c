#include "monty.h"
/**
 * _pint - prints the stack
 * @head: head of the stack
 * @line: line number
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * _pop - removes a node from the stack
 * @head: new node to be added
 * @line: line number
 * Return: nothing
 */
void _pop(stack_t **head, unsigned int line)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	temp = (*head);
	(*head) = (*head)->next;
	if (*head != NULL)
	{
		(*head)->prev = NULL;
	}
	free(temp);
}
