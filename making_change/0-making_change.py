#!/usr/bin/python3
"""
project making changes
By Ced
"""


from typing import List, Optional

def makeChange(coins: List[int], total: int) -> int:
    """
    Calcule le nombre minimal de pièces nécessaires pour atteindre une somme donnée.
    
    Args:
        coins (List[int]): Liste des valeurs des pièces disponibles
        total (int): Montant total à atteindre
        
    Returns:
        int: Nombre minimal de pièces nécessaires, ou -1 si impossible
        
    Raises:
        ValueError: Si la liste de pièces est vide ou contient des valeurs négatives/nulles
        TypeError: Si les arguments ne sont pas du bon type
    """
    # Validation des entrées
    
    # Cas de base
    if total == 0:
        return 0
    if total < 0:
        return -1
    
    
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
    
    return -1 if dp[total] == float('inf') else dp[total]

# def print_solution(coins: List[int], total: int) -> None:
#     """
#     Affiche la solution détaillée du problème de monnaie.
    
#     Args:
#         coins (List[int]): Liste des valeurs des pièces disponibles
#         total (int): Montant total à atteindre
#     """
#     try:
#         result = makeChange(coins, total)
#         if result == -1:
#             print(f"Impossible de faire la monnaie pour {total}")
#             return
            
#         # Retrouver la solution
#         remaining = total
#         used_coins = []
#         coins = sorted(set(coins), reverse=True)
        
#         for coin in coins:
#             while remaining >= coin:
#                 used_coins.append(coin)
#                 remaining -= coin
                
#         print(f"Montant total: {total}")
#         print(f"Nombre minimal de pièces: {result}")
#         print("Pièces utilisées:", used_coins)
        
#     except (ValueError, TypeError) as e:
#         print(f"Erreur: {str(e)}")


# def makeChange(coins, total):
#     """
#     Given a pile of coins of different values, determine the fewest
#     number of coins needed to meet a given amount total.
#     """
#     if total <= 0:
#         return 0
#     coins.sort(reverse=True)
#     result = 0
#     for coin in coins:
#         if total <= 0:
#             break
#         # nombre de pieces utilisé
#         result += total // coin
#         # reste du toal apres utilisation des pieces
#         total %= coin
    
#     if total != 0:
#         return -1
#    return result

