#include "monty.h"
/**
 * exec - execute the opcode based on content
 * @content: line content
 * @stack: pointer to the stack
 * @counter: line counter
 * @file: pointer to monty file
 * Return: 0 on success, 1 on failure
 */
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", check_push}, {"pall", pall}, {"pint", pint},
		{"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", f_div}, {"mul", mul}, {"mod", mod},
		{"pchar", peek_ch}, {"pstr", peek_str}, {"rotl", rotl},
		{"rotr", rotr}, {"queue", queue}, {"stack", f_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *opcode;
	(void)file;
	opcode = strtok(content, " \n\t"); /* Moved this line here */
	bus.arg = strtok(NULL, " \n\t");

	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, counter);
			return (0); /* Success */
		}
		i++;
	}

	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		goto cleanup;
	}

cleanup:
	fclose(bus.file);
	free(bus.content);
	free_stack(*stack);
	exit(EXIT_FAILURE);

	return (1); /* On Failure */
}
