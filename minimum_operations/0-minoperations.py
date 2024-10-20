#!/usr/bin/python3
"""
this an algorithm in python
called Minimum operations
by Ced
"""

def minOperations(n):
    if n <= 1:
        return 0
    
    operations = 0
    clipboard = 1
    current = 1
    
    while current < n:
        if n - current >= current:
            clipboard = current
            current += clipboard
            operations += 2
        else:
            current += clipboard
            operations += 1
    
    return operations
