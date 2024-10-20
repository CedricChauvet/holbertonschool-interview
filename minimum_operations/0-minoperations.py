#!/usr/bin/python3
"""
this an algorithm in python
called Minimum operations
by Ced
"""


def minOperations(n):
    if n <= 1:
        return 0
    
    # Factorisation du nombre
    factors = []
    d = 2
    while d * d <= n:
        while n % d == 0:
            factors.append(d)
            n //= d
        d += 1
    if n > 1:
        factors.append(n)
    