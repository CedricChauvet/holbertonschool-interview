#!/usr/bin/python3
"""
Valid UTF-8
"""


def validUTF8(data):
    """
    test si une liste de caracter est un utf8
    """

    n_bytes = 0
    data = iter(data)

    # Pour chaque entier dans la donnée
    for num in data:
        # Récupère le masque binaire de l'octet le plus à gauche
        bin_rep = format(num, '#010b')[-8:]
        if bin_rep[0] == '0':
            continue
        elif bin_rep[0:3] == '110':
            # print("2 bytes")
            try:
                num = next(data)
                num2 = format(num, '#010b')[2:4]
                if not (num2 == '10'):
                    return False
            except StopIteration:
                return False
        elif bin_rep[0:4] == '1110':
            # print("3 bytes")
            for i in range(2):
                try:
                    num = next(data)
                    num2 = format(num, '#010b')[2:4]
                    if not (num2 == '10'):
                        return False
                except StopIteration:
                    return False
        elif bin_rep[0:5] == '11110':
            # print("3 bytes")
            for i in range(3):
                try:
                    num = next(data)
                    num2 = format(num, '#010b')[2:4]
                    if not (num2 == '10'):
                        return False
                except StopIteration:
                    return False
        else:
            return False
    # S'il reste des octets en attente, c'est invalid
    return True
