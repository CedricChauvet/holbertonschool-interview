#!/usr/bin/python3
"""
Main file for testing
"""

validUTF8 = __import__('0-validate_utf8').validUTF8

data = [467]
print("data1")
print(validUTF8(data))

data = [80, 121, 116, 104, 111, 110, 32, 105, 115, 32, 99, 111, 111, 108, 33]
print("data2       ascii")
print(validUTF8(data))

data = [229, 65, 127, 256]
print("data3")
print(validUTF8(data))


