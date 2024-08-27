#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 27 12:10:01 2024

@author: chenleyu
"""
from typing import List

class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        length = len(points)
        dic = {}
        max_element = 0
        if(len(points)==1):
            return 1
        for i in range(0,length):
            for j in range(i+1,length):
                if (points[i][0] == points[j][0]):
                    slope = points[i][0]
                    offset = 99999
                else:
                    slope = (points[i][1]-points[j][1])/(points[i][0]-points[j][0])
                    offset=points[i][1] - slope * points[i][0]
                    print(slope,offset)
                if (slope, offset) in dic:
                    if i not in dic[(slope,offset)]:
                        dic[(slope,offset)].append(i)
                    if j not in dic[(slope,offset)]:
                        dic[(slope,offset)].append(j)
                    # print("adding a point to (", slope, ", ", offset, ")")
                    if len(dic[(slope, offset)]) > max_element:
                        max_element = len(dic[(slope,offset)])
                else:
                    dic[(slope,offset)] = []
                    dic[(slope,offset)].append(i)
                    dic[(slope,offset)].append(j)
                    if len(dic[(slope, offset)]) > max_element:
                        max_element = len(dic[(slope,offset)])
        # print(dic)
        return max_element
s=Solution()
# print(s.maxPoints([[1,1],[2,2],[3,3]]))
# print(s.maxPoints([[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]))
print(s.maxPoints([[1,0],[0,0]]))