#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Aug 25 20:03:58 2024

@author: chenleyu
"""

class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        if a|b == c :
            return 0
        bin_a = format(a, "032b")
        bin_b = format(b, "032b")
        bin_c = format(c, "032b")
        # print(bin_a)
        # print(bin_b)
        # print(bin_c)
        ret = 0
        for i in range(len(bin_a)):
            a_bit = int(bin_a[i])
            b_bit = int(bin_b[i])
            c_bit = int(bin_c[i])
            # print(a_bit,b_bit,c_bit)
            if a_bit == 1 and b_bit == 1 and c_bit == 0:
                ret+=2
            else:
                ret += abs(c_bit - (a_bit|b_bit))

        return ret
    
s = Solution()
# print(s.minFlips(1, 2, 3))
# print(s.minFlips(4, 2, 7))
print(s.minFlips(7, 3, 9))
