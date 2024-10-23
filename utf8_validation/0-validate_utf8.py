#!/usr/bin/python3
"""
Main file for testing
"""


def validUTF8(data):
    for i in data:
        if i >255:
            return False
    return True