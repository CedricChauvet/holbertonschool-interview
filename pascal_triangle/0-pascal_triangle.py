#!/usr/bin/python3
"""
triangle de pascal
"""

def pascal_triangle(n):
    """
    This is how to print the triangle of Pascal
    """
    
    if n <= 0:
        return []
    triangle = []
    former_line = [1]
    for i in range(1, n+1):
        
        line = [0] * i
        line[0] = 1
        line[-1] = 1
        
        for j in range(1, len(line)-1):
            line[j] =  former_line[j] + former_line[j-1]
        former_line = line
        triangle.append(line)
    return triangle
        
    