#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 23 14:52:54 2024

@author: chenleyu
"""

from typing import List

class Solution:
    def candy(self, ratings: List[int]) -> int:
        n=len(ratings)
        candies = [1] * n
        
        for i in range(1,n,1):
            if (ratings[i]>ratings[i-1]):
                candies[i] = candies[i-1]+1
        for i in range(n-2, -1, -1):
            if (ratings[i]>ratings[i+1] and candies[i]<=candies[i+1]):
                candies[i] = candies[i+1]+1
        return sum(candies)
    

s = Solution()
# print(s.candy([1,2,3,3,1,0,4]))
# print(s.candy([3,3,3,3,3,2]))
print(s.candy([1,3,4,5,2]))



class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)

        candies = [1] * n

        # First Pass, l to r
        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                candies[i] = candies[i-1] + 1
        
        # Second Pass, r to l
        for i in range(n-2, -1, -1):
            if ratings[i] > ratings[i+1] and candies[i] <= candies[i+1]:
                candies[i] = candies[i+1] + 1

        return sum(candies)