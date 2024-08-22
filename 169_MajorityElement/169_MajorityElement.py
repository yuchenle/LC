#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 22 19:50:27 2024

@author: chenleyu
"""

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if (len(nums) == 1):
            return nums[0]

        majority = len(nums)/2 # majority = floor(n/2)
        nums.sort()

        prev_val = nums[0]
        occurrence = 1
        for i in range(1, len(nums), 1):
            if (nums[i] == prev_val):
                occurrence += 1
                if occurrence > majority:
                    return prev_val
            else:
                occurrence = 1
                prev_val = nums[i]
                
s = Solution()
print(s.majorityElement([2,2,1,1,1,2,2]))