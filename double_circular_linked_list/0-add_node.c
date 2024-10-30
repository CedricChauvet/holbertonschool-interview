#include <stdio.h>
#include <stdlib.h>
#include "list.h"


/**
 * print_list - Print informations about each element of a list
 *
 * @list: A pointer to the head of the linkd list
 *
 * Return: void
 */


List *add_node_begin(List **list, char *str)
    {	
        printf("add_node_begin%s\n",str);
		print_list(*list);
		List *new_node;
		List *temp;

		/* Création du nouveau nœud */
		new_node = malloc(sizeof(List));
		if (new_node == NULL)
			return (NULL);

		/* Initialisation du nouveau nœud */
		new_node->str = str;
		new_node->next = NULL;

		/* Si la liste est vide, le nouveau nœud devient la tête */
		if (*list == NULL)
		{
			*list = new_node;
			return (new_node);
		}

		/* Parcours jusqu'au dernier nœud */
		temp = *list;
		while (temp->next != NULL)
			temp = temp->next;

		/* Ajout du nouveau nœud à la fin */
		temp->next = new_node;
		return (0);
    }

// Fonction d'ajout de nœud en fin de liste

List *add_node_end(List **list, char *str)
{
    List *new_node;
    List *temp;

    /* Création du nouveau nœud */
    new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return (NULL);

    /* Initialisation du nouveau nœud */
    new_node->str = str;
    new_node->next = NULL;

    /* Si la liste est vide, le nouveau nœud devient la tête */
    if (*list == NULL)
    {
        *list = new_node;
        return (new_node);
    }

    /* Parcours jusqu'au dernier nœud */
    temp = *list;
    while (temp->next != NULL)
        temp = temp->next;

    /* Ajout du nouveau nœud à la fin */
    temp->next = new_node;

    return (new_node);
}