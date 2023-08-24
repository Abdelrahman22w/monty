#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file = fopen(argv[1], "r");
	char line[MAX_LINE_LENGTH];
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		counter++;

		/* Remove newline character from the line */
		line[strcspn(line, "\n")] = '\0';

		exec(line, &stack, counter, file);
	}

	fclose(file);

	free_stack(stack); /* Free remaining elements in the stack */
	return (0);
}
