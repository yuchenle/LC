#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Aug 26 09:41:42 2024

@author: chenleyu
"""

from typing import List

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if (sum(nums)%2) ==1:
            return False
        
        #nlog(n), assuming merge sort or similar
        nums.sort()
        targetValue = sum(nums)/2
        length = len(nums)
        array_max = nums[length-1]
        print(targetValue, array_max)

        if array_max > targetValue:
            return False
        if array_max == targetValue:
            return True

        
        acc_sum = 0
    
        for i in range(0, length-1, 1):
            for j in range(i+1, length-1, 1):
                acc_sum = nums[i]+nums[j]
                if acc_sum == targetValue:
                    return True
                elif acc_sum > targetValue:
                    break
                acc_sum = 0


        
s=Solution()
# print(s.canPartition([1,2,3,5]))
# print(s.canPartition([1,6,6,11]))
# print(s.canPartition([1,5,11,5]))
# print(s.canPartition([14,9,8,4,3,2]))
print(s.canPartition([28,63,95,30,39,16,36,44,37,100,61,73,32,71,100,2,37,60,23,71,53,70,69,82,97,43,16,33,29,5,97,32,29,78,93,59,37,88,89,79,75,9,74,32,81,12,34,13,16,15,16,40,90,70,17,78,54,81,18,92,75,74,59,18,66,62,55,19,2,67,30,25,64,84,25,76,98,59,74,87,5,93,97,68,20,58,55,73,74,97,49,71,42,26,8,87,99,1,16,79]))