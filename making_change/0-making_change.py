#!/usr/bin/python3
"""
project making changes
By Ced
"""

def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.
    """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    result = 0
    for coin in coins:
        if total <= 0:
            break
        # nombre de pieces utilisé
        result += total // coin
        # reste du toal apres utilisation des pieces
        total %= coin
    
    if total != 0:
        return -1
    return result

