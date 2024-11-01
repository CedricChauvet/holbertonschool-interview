#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    """
    test si une liste de caracter est un utf8
    """
    for i in data:
        mask1 = 0b011
        print(i, ", is",bin(i,8))
        if bin(i)[2:5] == mask1:
            print(i, " is ascci", bin(i))
        mask2 = 0b110
        mask3 = 0b1110
        mask4 = 0b11110

    return True












        # if len(bin(i)) - 2 > 16 and len(bin(i)) - 2 < 24:
        #     print(i, " is 3 bytes")
        # if len(bin(i)) - 2 > 24 and len(bin(i)) - 2 < 32:
        #     print(i, " is 4 bytes")