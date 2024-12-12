#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

int regex_match(const char *str, const char *pattern)
{
	/*if pattern is empty, return 1 if str is empty, 0 otherwise*/
		if (*pattern == '\0')
	{
		return (*str == '\0');
	}

    /* Gestion du quantificateur */
	if (*(pattern + 1) == '*')
	{
		/* first loop : zéro occurrence du caractère */
		if (regex_match(str, pattern + 2))
		{
			return (1);
		}

		/* second loop : one or many occurrences */
		while (*str && (*str == *pattern || *pattern == '.'))
		{
			str++;
			if (regex_match(str, pattern + 2))
			{
				return (1);
			}
		}
		return (0);
	}

	/* general case*/
	if (*str && (*pattern == '.' || *pattern == *str))
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}
