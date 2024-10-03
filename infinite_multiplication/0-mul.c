#include "holberton.h"

/**
 * _puts - affiche une chaîne suivie d'un retour à la ligne
 * @str: chaîne à afficher
 */
void _puts(char *str)
{
    int i = 0;
    
    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
    _putchar('\n');
}

/**
 * print_error - affiche "Error" et sort
 * Return: 98
 */
int print_error(void)
{
    char *error = "Error";
    int i = 0;

    while (error[i])
    {
        _putchar(error[i]);
        i++;
    }
    _putchar('\n');
    return (98);
}

/**
 * multiply - multiplie deux grands nombres
 * @num1: premier nombre
 * @num2: deuxième nombre
 * Return: résultat de la multiplication
 */
char *multiply(char *num1, char *num2)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int *result;
    char *final_result;
    int i, j, carry, n1, n2, sum;
    int len_result = len1 + len2;

    result = calloc(len_result, sizeof(int));
    if (!result)
        return (NULL);

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = num1[i] - '0';
        
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = (n1 * n2) + result[i + j + 1] + carry;
            result[i + j + 1] = sum % 10;
            carry = sum / 10;
        }
        result[i] += carry;
    }

    final_result = malloc(len_result + 1);
    if (!final_result)
    {
        free(result);
        return (NULL);
    }

    i = 0;
    while (i < len_result - 1 && result[i] == 0)
        i++;

    int k = 0;
    while (i < len_result)
        final_result[k++] = result[i++] + '0';
    final_result[k] = '\0';

    free(result);
    return (final_result);
}

/**
 * is_digit - vérifie si une chaîne ne contient que des chiffres
 * @s: chaîne à vérifier
 * Return: 1 si que des chiffres, 0 sinon
 */
int is_digit(char *s)
{
    while (*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

/**
 * main - point d'entrée
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0 en cas de succès, 98 en cas d'erreur
 */
int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3)
        return (print_error());

    if (!is_digit(argv[1]) || !is_digit(argv[2]))
        return (print_error());

    result = multiply(argv[1], argv[2]);
    if (!result)
        return (print_error());

    _puts(result);
    free(result);
    return (0);
}