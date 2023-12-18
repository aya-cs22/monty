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
/**
 * _swap - swap the top two elements of the stack
 * @head: head of the stack
 * @line: line number
 * Return: nothing
 */
void _swap(stack_t **head, unsigned int line)
{
	stack_t *temp;
	int data = 0;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head);
	data = temp->n;
	temp->n = temp->next->n;
	temp->next->n = data;
}
/**
 * _nop - does nothing
 * @head: head of the stack
 * @line: line number
 * Return: nothing
*/
void _nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}
/**
 * _add - adds two numbers
 * @head: head of the stack
 * @line: line number
 * Return: nothing
 */
void _add(stack_t **head, unsigned int line)
{
	int sum = 0;
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	sum = (*head)->n + (*head)->next->n;
	temp = (*head)->next;
	(*head)->next = temp->next;
	temp->next->prev = (*head);
	(*head)->n = sum;
	free (temp);
}
