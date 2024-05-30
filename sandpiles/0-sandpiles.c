#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int grid_unstable[3][3];
	int is_unstable;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid_unstable[i][j] = 0;
		}
	}
	is_unstable = 0;


	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (grid1[i][j] > 3)
			{
				grid_unstable[i][j] = 1;
				is_unstable = 1;
			}
		}
	}

	if (is_unstable == 1)
	{
		printf("=\n");
		print_grid(grid1);
		sandpiles_stabling(grid_unstable, grid1);
	}
}


void sandpiles_stabling(int grid_unstable[3][3], int grid1[3][3])
{
	
	int i, j;
	int is_unstable;
	
	is_unstable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{

		if ((i == 1) && (j == 1) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i + 1][j] += 1;
			grid1[i - 1][j] += 1;
			grid1[i][j + 1] += 1;
			grid1[i][j - 1] += 1;
		}

		if ((i == 0) && (j == 0) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i + 1][j] += 1;
			grid1[i][j + 1] += 1;
		}

		if ((i == 0) && (j == 2) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i + 1][j] += 1;
			grid1[i][j - 1] += 1;
		}

		if ((i == 2) && (j == 0) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i - 1][j] += 1;
			grid1[i][j + 1] += 1;
		}

		if ((i == 2) && (j == 2) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i - 1][j] += 1;
			grid1[i][j - 1] += 1;
		}

		if ((i == 1) && (j == 0) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i + 1][j] += 1;
			grid1[i - 1][j] += 1;
			grid1[i][j + 1] += 1;
		}

		if ((i == 1) && (j == 2) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i + 1][j] += 1;
			grid1[i - 1][j] += 1;
			grid1[i][j - 1] += 1;
		}

		if ((i == 0) && (j == 1) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i + 1][j] += 1;
			grid1[i][j + 1] += 1;
			grid1[i][j - 1] += 1;
		}

		if ((i == 2) && (j == 1) && (grid_unstable[i][j] == 1))
		{
			grid1[i][j] += -4;
			grid1[i - 1][j] += 1;
			grid1[i][j + 1] += 1;
			grid1[i][j - 1] += 1;
		}
	}
}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid_unstable[i][j] = 1;
				is_unstable = 1;
			}
			else
			{
				grid_unstable[i][j] = 0;
			}
		}
	}

	if (is_unstable == 1)
	{
		printf("=\n");
		print_grid(grid1);
		sandpiles_stabling(grid_unstable,  grid1);
	}
}
