#include "holberton.h"

/**
 * _puts - affiche une chaîne
 * @str: chaîne à afficher
 */
void _puts(char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        _putchar(str[i]);
    _putchar('\n');
}

/**
 * print_error - affiche Error
 * Return: 98
 */
int print_error(void)
{
    _puts("Error");
    return (98);
}

/**
 * _strlen - retourne la longueur d'une chaîne
 * @s: chaîne
 * Return: longueur
 */
size_t _strlen(char *s)
{
    size_t i = 0;

    while (s[i])
        i++;
    return (i);
}

/**
 * is_zero - vérifie si le nombre est zéro
 * @str: chaîne à vérifier
 * Return: 1 si zéro, 0 sinon
 */
int is_zero(char *str)
{
    while (*str)
    {
        if (*str != '0')
            return (0);
        str++;
    }
    return (1);
}

/**
 * multiply - multiplie deux nombres immenses
 * @num1: premier nombre
 * @num2: deuxième nombre
 * Return: résultat ou NULL si erreur
 */
char *multiply(char *num1, char *num2)
{
    size_t len1, len2, len_res, i, j;
    int carry, n1, n2, sum;
    int *result;
    char *final_result;

    /* Vérification des cas spéciaux */
    if (is_zero(num1) || is_zero(num2))
        return (strdup("0"));

    len1 = _strlen(num1);
    len2 = _strlen(num2);
    len_res = len1 + len2;

    /* Vérification de dépassement de taille */
    if (len_res < len1 || len_res < len2)
        return (NULL);

    /* Allocation de mémoire avec vérification */
    result = calloc(len_res + 1, sizeof(int));
    if (!result)
        return (NULL);

    /* Multiplication optimisée */
    for (i = len1; i > 0; i--)
    {
        carry = 0;
        n1 = num1[i - 1] - '0';
        
        for (j = len2; j > 0; j--)
        {
            n2 = num2[j - 1] - '0';
            sum = (n1 * n2) + result[i + j - 1] + carry;
            
            if (sum > 99)  /* Optimisation pour grands nombres */
            {
                carry = sum / 10;
                result[i + j - 1] = sum % 10;
            }
            else
            {
                carry = sum / 10;
                result[i + j - 1] = sum % 10;
            }
        }
        
        if (carry > 0)
            result[i - 1] += carry;
    }

    /* Allocation du résultat final avec vérification */
    final_result = malloc(len_res + 1);
    if (!final_result)
    {
        free(result);
        return (NULL);
    }

    /* Conversion en chaîne avec suppression des zéros non significatifs */
    i = 0;
    while (i < len_res && result[i] == 0)
        i++;

    if (i == len_res)  /* Si le résultat est zéro */
    {
        final_result[0] = '0';
        final_result[1] = '\0';
    }
    else
    {
        j = 0;
        while (i < len_res)
            final_result[j++] = result[i++] + '0';
        final_result[j] = '\0';
    }

    free(result);
    return (final_result);
}

/**
 * is_valid_number - vérifie si la chaîne est un nombre valide
 * @str: chaîne à vérifier
 * Return: 1 si valide, 0 sinon
 */
int is_valid_number(char *str)
{
    if (!str || !*str)
        return (0);

    /* Ignore les zéros non significatifs au début */
    while (*str == '0')
        str++;

    /* Si la chaîne est vide après avoir ignoré les zéros */
    if (!*str)
        return (1);

    /* Vérification de la longueur maximale (environ 1Go de résultat) */
    if (_strlen(str) > 500000000)
        return (0);

    while (*str)
    {
        if (*str < '0' || *str > '9')
            return (0);
        str++;
    }
    return (1);
}

/**
 * main - point d'entrée
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0 si succès, 98 si erreur
 */
int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3)
        return (print_error());

    if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
        return (print_error());

    result = multiply(argv[1], argv[2]);
    if (!result)
        return (print_error());

    _puts(result);
    free(result);
    return (0);
}