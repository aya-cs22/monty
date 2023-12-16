#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: head of the stack
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *tmp = NULL;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*stack = NULL;
}
/**
 * add_to_stack - adds a new node to the stack
 * @new_node: new node to be added
 * Return: nothing
 */
void _push(stack_t **head, unsigned int line)
{

	stack_t *temp;
	char *arg = NULL;
	int i = 0;

	arg = strtok(NULL, " \t\n");
	if (arg == NULL)
	{
		fprintf(stderr,"L%d: usage: push integer\n",line);
		exit(EXIT_FAILURE);
	}
	while (arg[i] != '\0')
	{
		if (arg[i] != '-' && !isdigit(arg[i]))
		{
			fprintf(stderr,"L%d: usage: push integer\n",line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr,"L%d: usage: push integer\n",line);
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(arg);
	temp->next = *head;
	if(*head)
	{
		(*head)->prev = temp;
	}
	temp->prev = NULL;
	(*head) = temp;
}
/**
 * _pall - prints the stack
 * @head: head of the stack
 * Return: nothing
*/
void _pall(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;
	(void)line;

	temp = *head;
	if (temp == NULL)
	{
		return;
	}
	while (temp)
	{
		printf("%d\n",temp->n);
		temp = temp->next;
	}
}
