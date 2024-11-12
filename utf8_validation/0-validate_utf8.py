#!/usr/bin/python3
"""
Valid UTF-8
"""


def validUTF8(data):
    """
    test si une liste de caracter est un utf8
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










        # if len(bin(i)) - 2 > 16 and len(bin(i)) - 2 < 24:
        #     print(i, " is 3 bytes")
        # if len(bin(i)) - 2 > 24 and len(bin(i)) - 2 < 32:
        #     print(i, " is 4 bytes")