#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    """
    test si une liste de caracter est un utf8
    """
    for i in data:
        #print(len(bin(i)))
        # print(len(bin(i)))
        if len(bin(i)) - 2 < 8:
            print(i, " is ascci")   
        if len(bin(i)) - 2 > 8 and len(bin(i)) - 2 < 16:
            print(i, " is 2 bytes")
            print(bin(i),  "mask",bin(i)[2:5], "second byte", bin(i)[10:12])
            if bin(i)[2:5] == "110" and bin(i+1)[10:11] == "10":
                return True
            else:
                return False















        # if len(bin(i)) - 2 > 16 and len(bin(i)) - 2 < 24:
        #     print(i, " is 3 bytes")
        # if len(bin(i)) - 2 > 24 and len(bin(i)) - 2 < 32:
        #     print(i, " is 4 bytes")