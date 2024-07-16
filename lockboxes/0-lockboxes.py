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
    
    
    open_box(boxes, 0,n)
    list_box_closed[0] = True
    return all(list_box_closed)


def open_box(boxes,iliste,dur):
    dur -= 1
    if dur > 0:
        box = boxes[iliste]
        for i in box:
            list_box_closed[i] = True
            open_box(boxes,i,dur)
  

    
#        list_box_closed[i] = True

 