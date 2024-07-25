#!/usr/bin/python3
"""
this an algorithm in python
called LockBoxes
by Ced
"""


def canUnlockAll(boxes):
    """
    using a functionnal method
    """

    n = len(boxes)
    global list_box_closed
    list_box_closed = [False] * n

    boite_a_ouvrir = {0}
    nouvelles_boites = {0}

    for j in range(n):
        for i in boite_a_ouvrir:
            list_box_closed[i] = True
            a = boxes[i]
            for k in a:
                nouvelles_boites.add(k)

        boite_a_ouvrir = set(nouvelles_boites)

    # print(list_box_closed)
    # print(boite_a_ouvrir)

    if all(list_box_closed):
        return True
    else:
        return False
