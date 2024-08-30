#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

listint_t *insert_node(listint_t **head, int number)
{
    // Allouer de la mémoire pour le nouveau nœud
    listint_t *new_node = malloc(sizeof(listint_t));
    
    if (new_node == NULL) {
        return NULL; // Gérer l'erreur d'allocation
    }
    new_node->n = number;
    new_node->next = NULL;

    // Si la liste est vide ou si le nombre est inférieur au premier élément
    if (*head == NULL || number < (*head)->n) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    // Trouver la position d'insertion
    listint_t *current = *head;
    while (current->next != NULL && current->next->n < number) {
        current = current->next;
    }

    // Insérer le nouveau nœud à la position donnée ci dessus
    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}
