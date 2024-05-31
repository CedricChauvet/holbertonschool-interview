#include <stdlib.h>
#include <stdio.h>
#include "slide_line.h"


/**
* slide_line - Entry point
*
* @line: Arguments counter
* @size: Arguments vector
* @direction: Arguments vector
* Return: int
*/
int slide_line(int *line, int size, int direction)
{
	int newLine[size];
	int i, j;
	int h = 0;

	for (i = 0; i <= (int)size; i++)
	{
		newLine[i] = 0;
	}


	for (i = 0; i <= (int)size ; i += 1)
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
					newLine[h] = line[i];
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
			printf("[%d]", newLine[i]);
		}
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
