#include "monty.h"
/**
 * check_push - check for errors before we can add a new element
 * @head: a double pointer to the head of the stack
 * @counter: counts the lines
 * Return: Nothing
*/
void check_push(stack_t **head, unsigned int counter)
{
	int n;
	char *arg = bus.arg; /* Storing the argument in a local variable */

	if (!arg || *arg == '\0')
	{ /* check if the arg equals NUll*/
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		goto cleanup; /*to close, free the file and the stack then exit the file */
	}
	int j = 0;

	if (arg[j] == '-')
	{
		j++; /* Skip the negative sign */
	}
	while (arg[j] != '\0')
	{
		if (arg[j] < '0' || arg[j] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			goto cleanup;
		}
		j++;
	}
	n = atoi(arg);

	if (bus.lifi == 0)
	{
		addnode(head, n);
	}
	else
	{
		addqueue(head, n);
	}
	return;
cleanup: /* close and free file and free the stack to avoid memory leaking */
	fclose(bus.file);
	free(bus.content);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
/**
 * pall - print the elements in the stack
 * @head: double pointer to the head of the stack
 * Return: Nothing
*/

void pall(stack_t **head)
{
	stack_t *current_node = *head;

	if (current_node == NULL)
	{
		return; /* the stack is empty nothing to be printed */
	}

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
