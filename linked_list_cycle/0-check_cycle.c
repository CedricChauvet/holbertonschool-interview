#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"



int check_cycle(listint_t *list)
{
    // int s;
    // s = sizeof(listint_t);
    // printf('Size of listint_t : %d\n', s);
    for(int i = 0; i < 100; i++)
    {
        if(list == NULL)
        {
            return (0);
        }
        list = list->next;
        // listint_t *addr = list;
        // printf("Adresse : %p\n", (void *)addr);

    }
    return (1);
}



