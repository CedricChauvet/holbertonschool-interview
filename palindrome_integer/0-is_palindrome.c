#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"


int is_palindrome(unsigned long number)
{
    // Gestion de ULONG_MAX
    if (number == ULONG_MAX)
        return 0;  // ULONG_MAX n'est pas un palindrome
        

    int c = 0; /* digit position */
    long long n; /* number */
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