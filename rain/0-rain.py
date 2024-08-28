#!/usr/bin/python3
"""
0_main
"""

def rain(walls):
    mur = []
    ecart = []
    mini = []
    rain = 0 

    if walls == []:
        return 0 

    for i,w in enumerate(walls):
        if w != 0:
            mur.append(i)

    for j in range(len(mur)-1):
        ecart.append(mur[j+1] - mur[j] - 1)

    for k in range(len(mur)-1):
        mini.append(min(walls[mur[k]], walls[mur[k+1]]))

    for i,j in zip(mini, ecart):
        rain += i*j
    return walls

