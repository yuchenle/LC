#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Aug 28 20:07:20 2024

@author: chenleyu
"""

from typing import List

class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        u1,v1 = edges[0]
        u2,v2 = edges[1]
        if(v1==v2 or v1 == u2):
            return v1
        if (u1==u2 or u1==v2):
            return u1
        return 0
s=Solution()
print(s.findCenter([[1,2],[5,1],[1,3],[1,4]]))