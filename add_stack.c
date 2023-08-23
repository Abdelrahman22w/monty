#include "monty.h"

/**
 * addnode - add a node to the head of the stack
 * @head: double pointer to the head of the stack
 * @n: new_value
 * Return: Nothing
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *current_top;

	/* Store the current top node of the stack */
	current_top = *head;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	/* Set the value and connections for the new node */
	new_node->n = n;
	new_node->next = current_top;
	new_node->prev = NULL;

	/* Update the previous pointer of the previous top node */
	if (current_top)
		current_top->prev = new_node;

	/* Set the new node as the new top of the stack */
	*head = new_node;
}
