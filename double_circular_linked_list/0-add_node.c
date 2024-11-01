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
    List *newNode = malloc(sizeof(List));
    if (newNode == NULL) {
        // Gestion de l'erreur d'allocation
        return NULL;
    }

    newNode->str = str;

    List *head;
    List *last;

    if (*list == NULL) {
        // Si la liste est vide
        newNode->next = newNode;
        newNode->prev = newNode;
        *list = newNode;
    } else {
        // Si la liste n'est pas vide
        head = *list;
        last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
		*list = newNode;
    }

    return (newNode);
} 
List *add_node_end(List **list, char *str)
{
    /* Allocation du nouveau nœud */
    List *newNode = malloc(sizeof(List));
    if (newNode == NULL)
        return NULL;
    
    /* Initialisation des données du nouveau nœud */
    newNode->str = str;
    
    /* Cas 1: Liste vide */
    if (*list == NULL)
    {
        newNode->next = newNode;  /* Pointe sur lui-même */
        newNode->prev = newNode;  /* Pointe sur lui-même */
        *list = newNode;         /* Devient la tête de liste */
        return newNode;
    }
    
    /* Cas 2: Liste non vide */
    List *head = *list;
    List *last = head->prev;
    
    /* Mise à jour des pointeurs */
    newNode->next = head;        /* Nouveau nœud pointe vers la tête */
    newNode->prev = last;        /* Nouveau nœud pointe vers l'ancien dernier */
    head->prev = newNode;        /* La tête pointe vers le nouveau dernier */
    last->next = newNode;        /* L'ancien dernier pointe vers le nouveau */
    
    return newNode;
}