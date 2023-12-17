#include "monty.h"

/**
 * main - monty code interpreter
 * @argc: argument counter
 * @argv: argument vector
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *file;
	size_t size = 0;
	ssize_t read_line;
	stack_t *ptr_first_node = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read_line = getline(&content, &size, file)) != -1)
	{
		counter++;
		if (read_line > 0)
		{
			if (execute(content, counter, &ptr_first_node) == 0)
			{
				continue;
			}
		}
	}
	free_stack(&ptr_first_node);
	free(content);
	fclose(file);
	return (0);
}
