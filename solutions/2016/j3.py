"""
2016 CCC Junior P3
Simple user input processing and looping.
String manipulation avoided since Python was used.
In C, string manipulation (substrings) would play a large part in the solution.

Mason X (ohnx) was here (2016)

Post-contest note: I failed to come up with a good solution
for this in C. As a result, this is written in python.
"""
import sys

def isPalindrome(str):
    length = len(str)
    if (length == 1):
        return True
    if (length == 2):
        if (str[0] == str[1]):
            return True
        else:
            return False
    if (length == 3):
        if (str[0] == str[2]):
            return True
        else:
            return False
    largest = int(length / 2)
    for i in range(0, largest):
        firstChar = str[i]
        lastChar = str[length - 1 - i]
        if firstChar != lastChar:
            return False
    return True

def normPalindrome(str):
    length = len(str)
    for i in range(length, 1, -1):
        for j in range(0, length-i+1):
            if isPalindrome(str[j:i+j]):
                return i
    return 1

str = input("")
print(normPalindrome(str))