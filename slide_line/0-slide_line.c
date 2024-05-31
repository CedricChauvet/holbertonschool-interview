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
int slide_line(int *line, size_t size, int direction)
{
	int newLine[size];
	int i, j;
	int h = 0;
	size_t start, end;

	for (i = 0; i < (int)size; i++){
		newLine[i] = 0;
	}


	if (direction == SLIDE_LEFT)
	{	start = 0;
		end = size;
	}
	if (direction == SLIDE_RIGHT)
	{
		start = size;
		end = 0;
	}

	for (i = start; i < direction * (int)end ; i += direction)
	{	

		
		if (line[i] != 0)
		{
			for (j = i + 1; j < (int)end ; j += 1)
			{
				if (line[j] == 0)
				{
					continue;
				}

				else if (line[i] == line[j])
				{
					newLine[h] = 2 * line[i];
					h= h + 1;
					i = j;
					break;
				}
				else if (line[i] != line[j] && line[j] != 0 )
				{
					newLine[h] = line[i];
					h = h + 1;
					i = j;
					break;
				}
			}
		}
		if (i == (int)end - 1 && line[i] != 0)
		{
			newLine[h] = line[i];
			printf("some"); 
		}
	}

	printf("newLine");
	for (i = 0; i < (int)size; i++){
		line[i] = newLine[i];
		printf("[%d]", newLine[i]);
		
	}

	 
	printf("\n");
	printf("direction [%d]\n", direction);
	// *newLine = find_zeros(line, size);
	printf("size [%lu]\n", size);
	return (1);
}
