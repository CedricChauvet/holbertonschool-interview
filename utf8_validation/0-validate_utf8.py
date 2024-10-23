#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    """
    test si une liste de caracter est un utf8
    """
    for i in data:
        if (i >0x7f and i < 0XC280) or i > 0XC3BF:
            return False
    return True

# 	C280 c3 bf