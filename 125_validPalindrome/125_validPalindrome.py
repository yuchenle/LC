#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 23 20:43:42 2024

@author: chenleyu
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        n = len(s)
        analyse=""
        for i in range(0,n):
            if (ord(s[i]) >= 48 and ord(s[i]) <= 57) or (ord(s[i]) >= 97 and ord(s[i]) <= 122):
                analyse += s[i]

        n = len(analyse)
        for i in range(0, int(n/2)):
            opposite_idx = n-1-i
            if (analyse[i] != analyse[opposite_idx]):
                return False
        return True
            
s=Solution()
print(s.isPalindrome("Marge, let's \"[went].\" I await {news} telegram."))