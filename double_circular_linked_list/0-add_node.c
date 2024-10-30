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
    }

    return (0);
} 


// Fonction d'ajout de nœud en fin de liste

List *add_node_end(List **list, char *str)
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
        last = *list;
		head = last->prev;
        

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
    }

    return (0);
} 