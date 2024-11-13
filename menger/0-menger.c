#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * isHole -Fonction pour vérifier si une cellule doit être vide
 * @row: Position de la ligne
 * @col: Position de la colonne
 *
 * Return: 1 si la position doit être un trou, 0 sinon
 */

int isHole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			return (1);
		}
		row /= 3;
		col /= 3;
	}
	return (0);
}


/**
 * menger - Fonction pour dessiner l'éponge de Menger
 * @level: Niveau de récursion de l'éponge
 *
 * Description: Cette fonction génère une représentation ASCII
 * d'une éponge de Menger au niveau spécifié. Le niveau 0 est un
 * simple carré, et chaque niveau suivant subdivise chaque carré
 * en 9 carrés plus petits, en retirant le carré central.
 */
void menger(int level)
{
	/*Taille totale de l'éponge*/
	int size = pow(3, level);

	/*Parcours l'ensemble de l'eponge*/
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (isHole(i, j))
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}
}
