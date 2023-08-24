#include "monty.h"
/**
 * check_push - check for errors before we can add a new element
 * @head: a double pointer to the head of the stack
 * @counter: counts the lines
 * Return: Nothing
*/
void check_push(stack_t **head, unsigned int counter)
{
	int value, index = 0, invalid_input = 0;
	char *input = bus.arg;

	if (input)
	{
		if (input[index] == '-')
			index++;
		while (input[index] != '\0')
		{
			if (input[index] < '0' || input[index] > '9')
			{
				invalid_input = 1;
				break;
			}
			index++;
		}
		if (invalid_input)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	value = atoi(input);
	if (bus.lifi == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}

/**
 * pall - print the elements in the stack
 * @head: double pointer to the head of the stack
 * @counter: counts the lines
 * Return: Nothing
*/

void pall(stack_t **head, unsigned int counter)
{
	stack_t *current_node = *head;
	(void)counter;

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
