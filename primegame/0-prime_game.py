#!/usr/bin/python3
"""
Prime Game
"""

def isWinner(n, list):
    """[summary]

    Returns:
        [type]: [description]
    """
    # print("n", n)
    # print("list", list)
    # print("Winner: Ben", is_prime(4))
    maria = 0
    ben = 0
    for i in range(0, n):
        if num_prime(list[i]) % 2 == 1:
           maria += 1
        else:
            ben += 1
    if maria > ben:
        return "Maria"
    elif maria < ben:
        return "Ben"
    else:
        return None
           



def is_prime(n):
    """
    check if a number is prime
    """

    for i in range(2, n):
        if n % i == 0:
            return False
    return True


def num_prime(n):
    """
    check if a number is prime
    """
    nbr = 0
    for i in range(2, n):
       if is_prime(i):
           nbr += 1
    return nbr 