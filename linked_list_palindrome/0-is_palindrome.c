#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int is_palindrome(listint_t **head){
    listint_t *current = *head;
    int i = 0, j = 0, k = 0;
    int arr[10000];
    while (current != NULL){
        arr[i] = current->n;
        current = current->next;
        i++;
    }
    j = i - 1;
    while (k < j){
        if (arr[k] != arr[j]){
            return 0;
        }
        k++;
        j--;
    }
    return 1;

}