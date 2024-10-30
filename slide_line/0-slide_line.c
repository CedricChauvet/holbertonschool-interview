#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"

#define MAX_SIZE 100
/**
 * print_array - Prints out an array of integer, followed by a new line
 * 
 * @array: Pointer to the array of integer to be printed
 * @size: Number of elements in @array
 */
static void print_array(int const *array, size_t size)
{
    size_t i;

    printf("Line: ");
    for (i = 0; i < size; i++)
        printf("%s%d", i > 0 ? ", " : "", array[i]);
    printf("\n");
}

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
	int i, j;
	int h = 0;  // h is the index of newLine

	// crée un tableau de taille size avec des 0
	for (i = 0; i <= (int)size; i++)
	{
		newLine[i] = 0;
	}


	for (i = 0; i <= (int)size ; i ++)
	{
		if (line[i] != 0)
		{
			for (j = i + 1; j <= (int)size ; j += 1)
			{
				if (line[j] == 0)
				{
					continue;
				}

				else if (line[i] == line[j])
				{
					newLine[h] = 2 * line[i];
					h = h + 1;
					i = j - 1;
					break;
				}
				else if (line[i] != line[j] && line[j] != 0)
				{
					// newLine[h] = line[i];
					h = h + 1;
					i = j - 1;
					break;
				}
			}
		}
	}

	if (direction == SLIDE_LEFT)
	{

		for (i = 0; i < (int)size; i++)
		{
			line[i] = newLine[i];
		}
		printf("line left   ");
		print_array(line, size);
	}
	if (direction == SLIDE_RIGHT)
	{
		while (newLine[size - 1] == 0)
		{
			for (i = size; i > 0; i--)
			{
				newLine[i] = newLine[i - 1];
			}
			newLine[0] = 0;

		}

		for (i = 0; i < (int)size; i++)
		{
			line[i] = newLine[i];
		}
	}
	return (1);
}
