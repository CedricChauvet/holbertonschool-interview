#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "binary_trees.h"


/**
 * binary_tree_is_avl - Valide si un arbre est un AVL
 * @tree: Pointeur vers le nœud racine
 * Return: Facteur d'équilibre
 */
int binary_tree_is_avl(const binary_tree_t *tree)
	{
	if (tree == NULL)
		return (1);

	/* 1. Vérifier si c'est un BST valide */
	if (!is_bst(tree, 0, 1024))
		return (0);

	/* 2. Vérifier le facteur d'équilibre */
	int balance = binary_tree_balance(tree);

	if (balance > 1 || balance < -1)
		return (0);

	/* 3. Vérifier récursivement les sous-arbres */
	return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right));
	}

/**
 * binary_tree_height - Calcule la hauteur d'un arbre
 * @tree: Pointeur vers le nœud racine
 * Return: Hauteur de l'arbre
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_balance - Calcule le facteur d'équilibre
 * @tree: Pointeur vers le nœud racine
 * Return: Facteur d'équilibre
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left, height_right;

	if (tree == NULL)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (height_left - height_right);
}

/**
 * is_bst - check si la valeur du nœud est valide
 * @tree: Pointeur vers le nœud racine
 * @min: Valeur minimale
 * @max: Valeur maximale
 * Return: 0 ne respecte pas la condition
 * 1 respecte la condition
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	/* Verfie si la valeur N do*/
	if (tree == NULL)
		return (1);

	/* Vérifie si le nœud actuel respecte les limites min/max */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Vérifie récursivement les sous-arbres */
	return (is_bst(tree->left, min, tree->n) &&  /* ss-arbre gauche  < nœud */
			is_bst(tree->right, tree->n, max));  /* ss-arbre droit  > nœud */
}
