#!/usr/bin/python3
"""
Test  - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """
    this one rotates a 2D matrix 90 degrees clockwise
    """

    A = []
    for i in range(len(matrix)):
        A .append(list(reversed([matrix[j][i] for j in range(len(matrix))])))

    matrix[:] = A
