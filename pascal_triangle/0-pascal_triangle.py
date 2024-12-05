#!/usr/bin/python3
"""
triangle de pascal
"""

def pascal_triangle(n):
    """
    This is how to print the triangle of Pascal
    """
    print("numpy?")
    if n <= 0:
        return []
    else :
        triangle = [[1],[1,1]]
        return triangle
        
    # for i in range(0, n ):
    #     triangle=[]
    #     triangle[0] = 1
    #     # triangle[i] = [1]
    #     for j in range(1, i):
    #         triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]