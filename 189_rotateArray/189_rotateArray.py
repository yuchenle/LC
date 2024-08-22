#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 22 20:31:05 2024

@author: chenleyu
"""

class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if k > len(nums):
            k = k % len(nums)
        length = len(nums)
        tmp = nums[length-k:]
        for i in range(0,length-k,1):
            tmp.append(nums[i])
        nums.clear()
        nums.extend(tmp)
        # print(nums)
        


s=Solution()
# s.rotate([1,2,3,4,5,6,7], 3)
# s.rotate([-1,-100,3,99], 2)
s.rotate([1,2], 1)