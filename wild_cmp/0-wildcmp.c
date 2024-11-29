/* Wild Compare*/

#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - Compares two strings with support for wildcard characters.
 * @str: The string to be compared.
 * @pattern: The pattern containing characters to compare, including
 *           wildcards '*' and '?'.
 *
 * Description:
 * - '?' matches any single character.
 * - '*' matches zero or more characters.
 *
 * Return: 1 if the strings can be considered identical,
 *         otherwise 0.
 */
int wildcmp(const char *str, const char *pattern)
{
	if (*pattern == '\0')
	{
		/* If the pattern is empty, the strings match only if str is also empty */
		if (*str == '\0')
			return (1);
		else
			return (0);
	}

	if (*pattern == '*')
	{
		/*
		 * If the current pattern character is '*', try matching:
		 * - Zero characters (move to the next character in pattern).
		 * - One or more characters (move to the next character in str).
		 */
		return (wildcmp(str, pattern + 1) ||
			(*str != '\0' && wildcmp(str + 1, pattern)));
	}

	if (*str != '\0' && (*pattern == '?' || *pattern == *str))
	{
		/*
		 * If the current characters match directly or if the pattern
		 * contains '?', proceed to compare the next characters recursively.
		 */
		return (wildcmp(str + 1, pattern + 1));
	}

	/* If no match is found, return 0 */
	return (0);
}
