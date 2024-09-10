# -*- coding: utf-8 -*-
"""
Created on Tue Sep 10 22:17:14 2024

@author: ycle
"""

class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_x = str(x)
        size_x = len(str_x)
        if size_x == 1:
            return True
        ret = True
        floor_size = int(size_x/2)
        # print(floor_size)
        for i in range(floor_size):
            if str_x[i] != str_x[size_x-1-i]:
                ret = False
        return ret

s=Solution()
print(s.isPalindrome(-121))