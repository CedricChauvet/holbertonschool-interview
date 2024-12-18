#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * find_substring - Finds all the possible substrings containing a list of
 *                  words within a given string.
 *
 * @s: The string to scan.
 * @words: The array of words all substrings must be a concatenation of.
 * @nb_words: The number of elements in the array words.
 * @n: The address at which to store the number of elements in the returned
 *     array.
 *
 * Return: An array of integers storing the indices of substrings containing
 *         all the words in words, or NULL if no such substring is found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	/* Validation des paramètres */
	if (!s || !words || nb_words <= 0 || !n)
	{
		*n = 0;
		return (NULL);
	}

	int s_len = strlen(s);
	int w_len = strlen(words[0]);
	int total_len = w_len * nb_words;

	int *positions = NULL;
	int max_positions = 10;
	int current_positions = 0;

	positions = malloc(max_positions * sizeof(int));
	if (!positions)
	{
		*n = 0;
		return (NULL);
	}

	/* Parcours de la chaîne */
	for (int i = 0; i <= s_len - total_len; i++)
	{
		/*Alloue un bloc de mémoire ET initialise TOUS les octets à 0*/
		int *used_words = calloc(nb_words, sizeof(int));

		if (!used_words)
		{
			free(positions);
			*n = 0;
			return (NULL);
		}
		int all_words_found = 1;

		/* Vérifier chaque mot */
		for (int j = 0; j < nb_words; j++)
		{
			int word_found = 0;

			for (int k = 0; k < nb_words; k++)
			{
				/* strncmp fonction de comparaison de chaînes de caractères en */
				/* C qui permet de comparer un nombre limité de caractères.*/
				if (!used_words[k] &&
					strncmp(s + i + j * w_len, words[k], w_len) == 0) {
					used_words[k] = 1;
					word_found = 1;
					break;
				}
			}

			if (!word_found)
			{
				all_words_found = 0;
				break;
			}
		}

		/* Gérer les positions trouvées */
		if (all_words_found)
		{
			if (current_positions >= max_positions)
			{
				max_positions *= 2;
				/* Permet de changer la taille d'un bloc mémoire existant*/
				int *temp = realloc(positions, max_positions * sizeof(int));

				if (!temp)
				{
					free(positions);
					free(used_words);
					*n = 0;
					return (NULL);
				}
				positions = temp;
			}
			positions[current_positions++] = i;
		}

		free(used_words);
	}
	/* Ajuster la taille finale*/
	*n = current_positions;
	if (current_positions > 0)
	{
		int *final_positions = realloc(positions, current_positions * sizeof(int));

		if (final_positions)
		{
			positions = final_positions;
		}
	}
	else
	{
		free(positions);
		positions = NULL;
	}
	return (positions);
}
