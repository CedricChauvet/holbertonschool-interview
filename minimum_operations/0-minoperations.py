#!/usr/bin/python3
"""
this an algorithm in python
called Minimum operations
by Ced
"""


def minOperations(n):
    sol = 0
    while n > 1:
        if n%2 == 0:
            sol += 2
            n = n/2
        else:
            sol += 1
            n = n - 1
    return sol 
