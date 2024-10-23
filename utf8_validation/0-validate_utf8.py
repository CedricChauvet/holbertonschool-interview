#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    """
    test si une liste de caracter est un utf8
    """
    for i in data:
        premier_octet = i >> 8
        second_octet = i & 0xFF
        # print("i", i, "premier_octet", premier_octet, "second_octet", second_octet)
        #i = hex(i)
        #if (i > 0x7f and i < 0xC280) or i > 0xC3BF:
        if i <=  0x7f:
            return True
        if i > 0x7f and i < 0x7FF:
            # Obtenir le premier octet (0xC3)
               #
            if not (premier_octet > 0xC0 and premier_octet < 0xDF):
                # Obtenir le second octet (0xBF)
                if not (second_octet > 0x80 and second_octet < 0xBF):
                    return False
    return True



# Premier octet : 0xC0 à 0xDF
# Deuxième octet : 0x80 à 0xBF

# 	C280 c3 bf