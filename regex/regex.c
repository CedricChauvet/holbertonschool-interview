#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

int regex_match(const char *str, const char *pattern) {
    // Cas de base : si le pattern est vide, le texte doit aussi être vide
    if (*pattern == '\0') {
        return *str == '\0';
    }

    // Gestion du quantificateur *
    if (*(pattern + 1) == '*') {
        // Première boucle : zéro occurrence du caractère
        if (regex_match(str, pattern + 2)) {
            return 1;
        }

        // Deuxième boucle : une ou plusieurs occurrences
        while (*str && (*str == *pattern || *pattern == '.')) {
            str++;
            if (regex_match(str, pattern + 2)) {
                return 1;
            }
        }
        return 0;
    }

    // Cas sans quantificateur
    if (*str && (*pattern == '.' || *pattern == *str)) {
        return regex_match(str + 1, pattern + 1);
    }

    return 0;
}