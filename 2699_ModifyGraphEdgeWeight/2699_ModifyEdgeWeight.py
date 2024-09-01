#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Aug 30 11:00:01 2024

@author: chenleyu
"""
from typing import List


class Solution:
    edgeTable: List[List[int]] = []
    n = 0
    target = 0

    def merge_edges(n: int, original_edges: List[List[int]], helper_edges: List[List[int]]) -> List[List[int]]:
        #len(helper_edges) should be smaller or equal to len(original_edges)
        
        # print("original: ", original_edges, "helper: ", helper_edges)
        for i in range(len(helper_edges)):
            e_h = helper_edges[i]
            for j in range(len(original_edges)):
                e_o = original_edges[j]
                if (e_o[0] == e_h[0] and e_o[1] == e_h[1]) or (e_o[0] == e_h[1] and e_o[1] == e_h[0]):
                    e_o[2] = e_h[2]
        # print(original_edges)
        return original_edges
        
    # helper takes a list of edges and returns a pair (List[edges], neededWeight) with edges = (s, e, weight)
    def helper(self, source: int, destination: int, prev_nodes: List[int]):
        edges = []
        connected_nodes = []
        for i in range(self.n):
            if self.edgeTable[destination][i] != 0:            
                connected_nodes.append(i)
        # print(connected_nodes)
        # print(prev_nodes)


        for i in connected_nodes:
            if prev_nodes != None and (i not in prev_nodes):
                if self.edgeTable[source][i] > self.target:
                    continue
                else:
                    if i == source:
                        if self.edgeTable[i][destination] < self.target:
                            edges.append([i,destination, self.edgeTable[i][destination]])
                            # print("return:source ", source, " destination: ", destination, " result: ",  edges, self.edgeTable[i][destination])
                            return edges, self.edgeTable[i][destination]
                    else:
                        prev_nodes.append(destination)
                        prev_edges, neededWeight = self.helper(source, i, prev_nodes)
                        if self.edgeTable[i][destination] + neededWeight < self.target:    
                            prev_edges.append([i, destination, self.edgeTable[i][destination]])
                            edges = prev_edges
                            # print("return:source ", source, " destination: ", destination, " result: ",  edges, self.edgeTable[i][destination] + neededWeight)
                            return edges, self.edgeTable[i][destination] + neededWeight
        
        return [],0
    
    
    # helper_no_neg takes a list of edges and returns a pair (List[edges], neededWeight) with edges = (s, e, weight)
    # the different between helper_no_neg and helper is that helper does not eliminate negative weight but
    # helper_no_neg ignores negative weights.
    def helper_no_neg(self, source: int, destination: int, prev_nodes: List[int]):
        edges = []
        connected_nodes = []
        print(source)
        for i in range(self.n):
            if self.edgeTable[destination][i] != 0:            
                connected_nodes.append(i)
        # print(connected_nodes)
        # print(prev_nodes)


        for i in connected_nodes:
            if prev_nodes != None and (i not in prev_nodes):
                if self.edgeTable[source][i] > self.target:
                    continue
                if self.edgeTable[i][destination] < 0:
                    continue
                if i == source:
                    if self.edgeTable[i][destination] < self.target and self.edgeTable[i][destination] > 0:
                        edges.append([i,destination, self.edgeTable[i][destination]])
                        # print("return:source ", source, " destination: ", destination, " result: ",  edges, self.edgeTable[i][destination])
                        return edges, self.edgeTable[i][destination]
                else:
                    prev_nodes.append(destination)
                    prev_edges, neededWeight = self.helper_no_neg(source, i, prev_nodes)
                    if self.edgeTable[i][destination] + neededWeight < self.target:    
                        prev_edges.append([i, destination, self.edgeTable[i][destination]])
                        edges = prev_edges
                        # print("return:source ", source, " destination: ", destination, " result: ",  edges, self.edgeTable[i][destination] + neededWeight)
                        return edges, self.edgeTable[i][destination] + neededWeight
        
        return [],0
                
    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        
        self.edgeTable = [[0 for _ in range(n)] for _ in range(n)]
        self.n = n
        self.target = target
        
        # fill the edgeTable in the class
        for i in range(len(edges)):
            self.edgeTable[edges[i][0]][edges[i][1]] = edges[i][2]
            self.edgeTable[edges[i][1]][edges[i][0]] = edges[i][2]
        
        # print(self.edgeTable)
        
        
        #without using negative edges, if we are able to get from source to destination with a weight < target, then no solution
        helper_edges2, neededWeight2 = self.helper_no_neg(source, destination, [])
        print(helper_edges2, neededWeight2)

        if neededWeight2 > 0 and neededWeight2 < target:
            return []
        
        
        helper_edges, neededWeight = self.helper(source, destination, [])


        # print(helper_edges)
        # print(neededWeight)

        tmp_helper = []

        accumulated_weight = 0
        for i in range(len(helper_edges)):
            if helper_edges[i][2] > 0:
                accumulated_weight += helper_edges[i][2]
            else:
                edge = helper_edges[i]
                edge[2] = 1
                # self.edgeTable[edge[0]][edge[1]] = 1
                # self.edgeTable[edge[1]][edge[0]] = 1
                accumulated_weight += 1
                tmp_helper.append(edge)

        helper_edges = tmp_helper
        # print(helper_edges)

        if accumulated_weight > target:
            return []
        elif accumulated_weight == target:
            return self.merge_edges(edges, helper_edges)
        else:
            if (len(helper_edges) == 0):
                return []
            else:
                # we only need to access to the first element because the list 
                # contains only negative edges
                helper_edges[0][2] += (target - accumulated_weight)
                # self.edgeTable[edge[0]][edge[1]] = helper_edges[0][2]
                # self.edgeTable[edge[1]][edge[0]] = helper_edges[0][2]
        
        for i in range(len(edges)):
            if edges[i][2] == -1:
                edges[i][2] = 1
                # print(edges[i])
        # print(edges)

        # print(helper_edges, accumulated_weight)
        return self.merge_edges(edges, helper_edges)

s=Solution()
# print(s.modifiedGraphEdges(5,[[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], 0, 1,5))
# print(s.modifiedGraphEdges(3,[[0,1,-1],[0,2,5]], 0, 2,6))
# print(s.modifiedGraphEdges(4,[[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], 0, 2,6))
# print(s.modifiedGraphEdges(4, [[0,1,-1],[1,2,-1],[3,1,-1],[3,0,2],[0,2,5]], 2, 3, 8))
print(s.modifiedGraphEdges(5, [[0,1,-1],[2,1,-1],[2,4,8],[3,4,10]], 0, 2, 9))
