#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * add_node_begin - Adds a new node at the beginning of a doubly circular list
 * @list: A double pointer to the head of the linked list
 * @str: String to be stored in the new node
 *
 * Return: Address of the new node, or NULL if allocation fails
 */
List *add_node_begin(List **list, char *str)
{
	List *newNode, *head, *last;

	/* Allocate memory for the new node */
	newNode = malloc(sizeof(List));
	if (newNode == NULL)
		return (NULL);

	/* Initialize the string in the new node */
	newNode->str = str;

	/* Case 1: Empty list */
	if (*list == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
		return (newNode);
	}

	/* Case 2: List is not empty */
	head = *list;
	last = head->prev;

	/* Connect new node to the list */
	newNode->next = head;
	newNode->prev = last;
	head->prev = newNode;
	last->next = newNode;
	*list = newNode;

	return (newNode);
}

/**
 * add_node_end - Adds a new node at the end of a doubly circular list
 * @list: A double pointer to the head of the linked list
 * @str: String to be stored in the new node
 *
 * Return: Address of the new node, or NULL if allocation fails
 */
List *add_node_end(List **list, char *str)
{
	List *newNode, *head, *last;

	/* Allocate memory for the new node */
	newNode = malloc(sizeof(List));
	if (newNode == NULL)
		return (NULL);

	/* Initialize the string in the new node */
	newNode->str = str;

	/* Case 1: Empty list */
	if (*list == NULL)
	{
		newNode->next = newNode;
		newNode->prev = newNode;
		*list = newNode;
		return (newNode);
	}

	/* Case 2: List is not empty */
	head = *list;
	last = head->prev;

	/* Update pointers to insert at end */
	newNode->next = head;
	newNode->prev = last;
	head->prev = newNode;
	last->next = newNode;

	return (newNode);
}
