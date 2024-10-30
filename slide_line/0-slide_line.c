#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

#define MAX_SIZE 100


/**
* slide_line - Entry point
*
* @line: Arguments counter
* @size: Arguments vector
* @direction: Arguments vector
* Return: int
*/
int slide_line(int *line, size_t size, int direction)
{
	int newLine[MAX_SIZE];
	int i;
	int pos = 0;  // h is the index of newLine

	// crée un tableau de taille size avec des 0
	for (i = 0; i <= (int)size; i++)
	{
		newLine[i] = 0;
	}

    if (direction == SLIDE_LEFT) 
    {
        // Première passe : déplacer tous les nombres non-nuls vers la gauche
        for (i = 0; i < (int)size; i++) 
        {
            if (line[i] != 0) 
            {
                newLine[pos] = line[i];
                pos++;
            }
        }
        
        // Deuxième passe : fusionner les nombres identiques adjacents
        for (i = 0; i < pos - 1; i++) 
        {
            if (newLine[i] == newLine[i + 1]) 
            {
                newLine[i] *= 2;
                // Décaler tous les éléments restants vers la gauche
                for (int j = i + 1; j < pos - 1; j++)
                    newLine[j] = newLine[j + 1];
                newLine[pos - 1] = 0;
                pos--;
            }
        }
    }


   else if (direction == SLIDE_RIGHT) 
    {
        // Première passe : déplacer tous les nombres non-nuls vers la droite
        pos = size - 1;
        for (i = size - 1; i >= 0; i--) 
        {
            if (line[i] != 0) 
            {
                newLine[pos] = line[i];
                pos--;
            }
        }
        
        // Deuxième passe : fusionner les nombres identiques adjacents
        for (i = size - 1; i > 0; i--) 
        {
            if (newLine[i] == newLine[i - 1] && newLine[i] != 0) 
            {
                newLine[i] *= 2;
                // Décaler tous les éléments restants vers la droite
                for (int j = i - 1; j > 0; j--)
                    newLine[j] = newLine[j - 1];
                newLine[0] = 0;
            }
        }
    }



	    // Copier le résultat dans le tableau d'origine
    for (i = 0; i < (int)size; i++)
    {
	line[i] = newLine[i];
	}


	return (1);
}
