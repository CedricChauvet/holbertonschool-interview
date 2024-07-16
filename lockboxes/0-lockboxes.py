#!/usr/bin/python3
"""
this an algorithm in python
called LockBoxes
by Ced
"""



def canUnlockAll(boxes):

    n = len(boxes)
    global list_box_closed
    list_box_closed  = [False] * n
    
    new_list = boxes[0] 
    for _ in range(n):
            new_list=open_box(boxes,new_list)
    
    print("list", list_box_closed)
    # print(list_box_closed)


def open_box(boxes,iliste):
    for i in iliste: 
        list_box_closed[i] = True
 
    return 
