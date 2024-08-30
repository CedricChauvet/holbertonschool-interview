#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


listint_t *insert_node(listint_t **head, int number)
{
/**
 * insert_node - insert a number into a sorted singly linked list
 * @head: pointer to head of list
 * @number: number to be included in new node
 * Return: address of the new element or NULL if it fails
 */
	/* Allouer de la mémoire pour le nouveau neud */
	listint_t *new_node = malloc(sizeof(listint_t));

	new_node->n = number;
	new_node->next = NULL;

    /*Si la liste est vide ou si le nombre est inf au 1er élément */
	if (*head == NULL || number < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	/* Trouver la position d'insertion */
	listint_t *current = *head;

	while (current->next != NULL && current->next->n < number)
	{
		current = current->next;
	}

	/* Insérer le nouveau nœud à la position donnée ci dessus */
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
