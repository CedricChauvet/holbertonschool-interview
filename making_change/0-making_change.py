#!/usr/bin/python3
"""
project making changes
By Ced
"""
from typing import List, Optional


def makeChange(coins: List[int], total: int) -> int:
    """
    Calcule le nombre minimal de pièces nécessaires pour
    atteindre une somme donnée.

    Args:
        coins (List[int]): Liste des valeurs des pièces disponibles
        total (int): Montant total à atteindre

    Returns:
        int: Nombre minimal de pièces nécessaires, ou -1 si impossible

    Raises:
        ValueError: Si la liste de pièces est vide ou contient
        des valeurs négatives/nulles
        TypeError: Si les arguments ne sont pas du bon type
    """
    # Cas de base
    if total <= 0:
        return 0

    if not isinstance(coins, list) or not isinstance(total, int):
        return -1
    if not coins:
        return -1

    if any(coin < 0 for coin in coins):
        return -1

    # Optimisation : éliminer les doublons et trier en ordre décroissant
    coins = sorted(set(coins), reverse=True)

    # Programmation dynamique pour trouver la solution optimale
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    if dp[total] == float('inf'):
        return -1
    else:
        return dp[total]
