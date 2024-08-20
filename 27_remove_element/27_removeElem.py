#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 13:47:51 2024

@author: chenleyu
"""

class Solution(object):
    def removeElement(self, nums, val):
    
        ret = 0
        for idx in range(0, len(nums), 1):
            if (nums[idx] == val):
                nums[idx] = 51
            else:
                ret+=1
        nums.sort()
        return ret
    
    
s = Solution()
NE = s.removeElement([3,2,2,3], 3)
print(NE)