#include "monty.h"
/**
 * pop - delete the top element of the stack
 * @head: double pointer to the head of the stack
 * @counter: counts the line at which the error occurred
 * Return: Nothing
*/
void pop(stack_t **head, unsigned int counter)
{
	stack_t *top_node;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	top_node = *head;
	*head = top_node->next;
	if (*head)
	{
		(*head)->prev = NULL;
	}
	free(top_node);
}
