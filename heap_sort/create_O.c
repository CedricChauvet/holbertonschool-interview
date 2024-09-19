#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void write_big_o_notations()
{
    FILE *file = fopen("0-O", "w");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }

    fprintf(file, "O(n log n)\n");   // Best case time complexity
    fprintf(file, "O(n log n)\n"); // Average case time complexity
    fprintf(file, "O(n log n)\n");   // Worst case time complexity
	fprintf("\n");
    fclose(file);
}