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
    list_box_closed  = [False] * n
    
    
    open_box(boxes, 0)
    
    print("list", list_box_closed)

def open_box(boxes,iliste):
    return open_box(boxes[iliste])

    
#        list_box_closed[i] = True

 