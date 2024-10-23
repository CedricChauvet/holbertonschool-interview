#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"


int is_palindrome(int number)
{
    int c = 0; /* digit position */
    int n; /* number */
    n = number;
    // nombre de digits
    while (n != 0)
    {
        n /= 10;
        c++;
    }
    // cree une variable de bonne longueur
    int numberArray[c];
    int ca = c / 2;   
    
    c = 0;
    n = number;
    
    /* extract each digit */
    while (n != 0)
    {
        numberArray[c] = n % 10;
        n /= 10;
        c++;
    }
    
    for(int k = 0; k < ca; k++)
    {
        if (numberArray[k] != numberArray[c -1 - k])
        {
            return (0);
        }
    }
    return (1);
}