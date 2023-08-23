#include "monty.h"

/**
 * f_stack - sets the format of the data to a stack (LIFO)
 * @head: double pointer to the head of the stack
 * @counter: counts the line at which the error occurred
 * Return: Nothing
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}

/**
 * queue - sets the data format to queue (FIFO)
 * @head: double pointer to the head of the stack
 * @counter: counts the line at which the error occurred
 * Return: Nothing
*/
void queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail of the queue
 * @n: new_value
 * @head: double pointer to the head of the stack
 * Return: Nothing
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (!current)
	{
		/* If the queue is empty, set the new_node as the head */
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		/* Traverse to the end of the queue */
		while (current->next)
			current = current->next;

		/* Link the new_node to the end of the queue */
		current->next = new_node;
		new_node->prev = current;
	}
}
