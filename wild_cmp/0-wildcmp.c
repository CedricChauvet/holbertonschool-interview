/* Wild Compare*/
#include "holberton.h"
#include <stdio.h>

int wildcmp(const char *str, const char *pattern) {
     // Base cases
    if (*pattern == '\0') {
        // If the pattern is empty, the strings match only if str is also empty
        if(*str == '\0') {
			return (1);
		}
		else {
			return (0);
		}
	}
    if (*pattern == '*') {
        // If the current pattern character is '*', try matching zero or more characters
        return wildcmp(str, pattern + 1) || (*str != '\0' && wildcmp(str + 1, pattern));
    }
    if (*str != '\0' && (*pattern == '?' || *pattern == *str)) {
        // If the characters match or the pattern is '?', continue recursively
        return wildcmp(str + 1, pattern + 1);
    }

    // No match found
    return (0);
}
