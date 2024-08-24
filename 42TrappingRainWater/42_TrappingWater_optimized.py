#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug 24 23:14:17 2024

@author: chenleyu
"""

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) < 3:
            return 0
        
        left, right = 0, len(height) - 1
        l_max, r_max = height[left], height[right]
        w_trap = 0

        while left <= right:
            if height[left] <= height[right]:
                if height[left] >= l_max:
                    l_max = height[left]
                else:
                    w_trap += l_max - height[left]
                left += 1
            else:
                if height[right] >= r_max:
                    r_max = height[right]
                else:
                    w_trap += r_max - height[right]
                right -= 1
        print(w_trap)
        return w_trap

s=Solution()
# s.trap([0,1,0,2,1,0,1,3,2,1,2,1])
# s.trap([4,2,0,3,2,9])
# s.trap([0,7,1,4,6])
s.trap([4,2,3,2])