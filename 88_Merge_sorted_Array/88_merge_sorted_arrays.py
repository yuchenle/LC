#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 20 10:40:37 2024

@author: chenleyu
"""

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        if n == 0:
          print(nums1)
          return
        if m == 0:
          for i in range(0,n,1):
              nums1[i] = nums2[i]
          print(nums1)

        nums_tmp = []
        for i in range(0,m,1):
              nums_tmp.append(nums1[i])
        
        idx1 = 0
        idx2 = 0
        for idx in range(0, m+n, 1):
            if (idx1 >= m):
                nums1[idx] = nums2[idx2]
                idx2+=1
                continue
            if (idx2 >= n):
                nums1[idx] = nums_tmp[idx1]
                idx1+=1
                continue
            if (nums2[idx2] < nums_tmp[idx1]):
                nums1[idx] = nums2[idx2]
                idx2 += 1
            else:
                nums1[idx] = nums_tmp[idx1]
                idx1 += 1

s=Solution()
array1=[4,0]
array2=[1]
s.merge(array1, 1, array2,1)
print(array1)
