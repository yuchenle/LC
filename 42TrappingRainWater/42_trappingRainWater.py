#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug 24 17:38:38 2024

@author: chenleyu
"""

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        variations = [1] * n 
        monts_idx = []
        rain=0
        max_idx = 0
        max_val = height[0]
        for i in range(1,n):
            #determine the max value of the array and locate them
            if height[i] >= max_val:
                max_idx = i
                max_val = height[i]

            if height[i] > height[i-1]:
                variations[i] = 1
                if(i==n-1):
                    monts_idx.append(i)
                    # clear the peaks to keep the true ones
            else:
                variations[i] = -1
                if (variations[i-1] == 1):
                    monts_idx.append(i-1)
        # print("max_idx = ", max_idx)
        # print("mont_idx = ", monts_idx)
        for i in range(0,len(monts_idx)):
            if (monts_idx[i] != max_idx):
                low = min(height[max_idx], height[monts_idx[i]])
                stride = 0
                # print("i = ", i, "max_idx = ", max_idx, "monts_idx [i] = ", monts_idx[i])
                if monts_idx[i] < max_idx:
                    stride = 1
                else:
                    stride = -1
                # print("stride = " , stride, "begin_idx:", monts_idx[i], "end_idx=", max_idx)
                for j in range(monts_idx[i], max_idx, stride):
                    store = low - height[j]
                    # print("store = ", store)
                    if (store>0):
                        rain += store
                        height[j] = low
                    # print("iteration j = ", j, "rain = ", rain)
        
        print(rain)
        return rain
s=Solution()
# s.trap([0,1,0,2,1,0,1,3,2,1,2,1])
# s.trap([4,2,0,3,2,9])
# s.trap([0,7,1,4,6])
s.trap([4,2,3,2])