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
        # print(bin_rep)
        # # Si c'est un octet de suite
        # if n_bytes != 0:
        #     # Vérifie si le masque binaire commence par 10
        #     if not (bin_rep[0:2] == '10'):
        #         return False
        #     n_bytes -= 1
        #     continue
        
        # Sinon, détermine le nombre d'octets sur la base du masque
        if bin_rep[0] == '0':
            continue
        elif bin_rep[0:3] == '110':
            # print("2 bytes")
            num = next(data)
            num2 = format(num, '#010b')[2:4]
            # print(num2)
            if not (num2 == '10'):
                return False
            
        elif bin_rep[0:4] == '1110':
            # print("3 bytes")
            for i in range(2):
                num = next(data)
                num2 = format(num, '#010b')[2:4]
                if not (format == '10'):
                    return False
            
        elif bin_rep[0:5] == '11110':
            #print("3 bytes")
            for i in range(3):
                num = next(data)
                num2 = format(num, '#010b')[2:4]
                if not (format == '10'):
                    return False 
    
    # S'il reste des octets en attente, c'est invalid
    return True




"""


    data = iter(data)
    
    for i in data:
        if int(i)>>7 == 0:
            continue

        elif int(i)>>5 == 6:
            i == data.next()
            if int(i)>>6 != 2:
                continue

        elif int(i)>>4 == 14:
 
            j = next(data)
            if int(j)>>6 == 2:
                continue
            j = next(data)
            if int(j)>>6 == 2:
                continue
    
            
        elif int(i)>>3 == 30: 
            j = next(data)
            if int(j)>>6 == 2:
                continue
            j = next(data)
            if int(j)>>6 == 2:
                continue
            j = next(data)
            if int(j)>>6 == 2:
                continue

        else:
            return False
    return True


"""



        # if len(bin(i)) - 2 > 16 and len(bin(i)) - 2 < 24:
        #     print(i, " is 3 bytes")
        # if len(bin(i)) - 2 > 24 and len(bin(i)) - 2 < 32:
        #     print(i, " is 4 bytes")