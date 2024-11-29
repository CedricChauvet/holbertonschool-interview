/* Wild Compare*/
#include "holberton.h"
#include <stdio.h>

int wildcmp(const char *str, const char *pattern) {
    // Pointeurs pour garder la trace des positions
    const char *star = NULL;      // Pointeur pour la position du dernier *
    const char *match = NULL;     // Pointeur pour correspondre dans str

    // Parcourt les deux chaînes
    while (*str) {
        if (*pattern == '?' || *pattern == *str) {
            // Correspondance normale ou avec '?'
            str++;
            pattern++;
        } else if (*pattern == '*') {
            // Rencontré un '*'
            star = pattern++;     // Enregistrez la position de *
            match = str;          // Marquez la position correspondante dans str
        } else if (star) {
            // Si un * a été rencontré auparavant
            pattern = star + 1;   // Revenez à la position après *
            str = ++match;        // Essayez avec un caractère supplémentaire
        } else {
            // Pas de correspondance
            return (0);
        }
    }

    // Vérifiez les caractères restants dans le modèle
    while (*pattern == '*') {
        pattern++;
    }

    // Si le modèle est vide, c'est une correspondance
    if( *pattern == '\0') {
		return (1);
	} else {
		return (0);
	}
	}
