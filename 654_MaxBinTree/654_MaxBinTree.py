#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug 29 12:08:56 2024

@author: chenleyu
"""

from typing import List
from typing import Optional

# Definition for a binary tree node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        
        length = len(nums)
        
        if (length == 0):
            return None
        if (length == 1):
            return TreeNode(nums[0])

        # Root node value is max(nums)
        maxi = 0
        idx_max = -1
        for i in range(len(nums)):
            if nums[i] > maxi:
                maxi=nums[i]
                idx_max = i

        node_val = max(nums)
        Ret = TreeNode(node_val)
        
        # Left branch is built from numbers on the left of index(max(nums)).
        # Needs to be built recursively
        
        # The same for the right branch.
        left_array = nums[0:idx_max]
        left_graph = self.constructMaximumBinaryTree(left_array)
        right_array = nums[idx_max+1:]
        right_graph = self.constructMaximumBinaryTree(right_array)

        Ret.left = left_graph
        Ret.right = right_graph

        return Ret

def print_TreeNode(node: Optional[TreeNode]) -> str:
    if node == None:
        return "null"
    else:
        ret = str(node.val) + "," + print_TreeNode(node.left) +"," + print_TreeNode(node.right)
        return ret

s=Solution()
node = s.constructMaximumBinaryTree([3,2,1])
print(node, node.val)
print(node.right, node.right.val)
print(node.right.right, node.right.right.val)
print(print_TreeNode(node))


        
        