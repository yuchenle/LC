# -*- coding: utf-8 -*-
"""
Created on Sun Sep  8 15:19:19 2024

@author: ycle
"""
import time
from typing import List

class Solution:
    edgeTable: List[List[int]] = []
    n = 0
    target = 0

    # Path_no_neg takes a set of edges (defined within the class) determines whether there is a path starting from source
    # ending on destination that has the weight < target. All edges in this path must be positive
    # It returns such a path if it exists, or [] if it does not exist
    def path_no_neg(self, source: int, destination: int, prev_nodes: List[int], accumulatedWeight: int) -> List[List[int]]:
        connected_nodes = []
        ret = []
        target = self.target

        # print("path_no_neg: source ", source, ", destination = ", destination, " prev_node = ", prev_nodes)

        for i in range(self.n):
            if self.edgeTable[destination][i] > 0 and self.edgeTable[destination][i] < target:
                connected_nodes.append(i)

        # print(connected_nodes)

        for node in connected_nodes:
            if node not in prev_nodes:
                if node == source:
                    # print("path_no_neg: source 111", source, ", destination = ", destination, " prev_node = ", prev_nodes, "accumulatedWeight =", accumulatedWeight)

                    if self.edgeTable[node][destination] + accumulatedWeight < target:
                        ret = [[node, destination, self.edgeTable[node][destination]]]
                        break
                else:
                    tmp_prev_node = prev_nodes.copy()
                    tmp_prev_node.append(destination)
                    tmp_acc_w = accumulatedWeight
                    tmp_acc_w += self.edgeTable[node][destination]
                    prev_edges = self.path_no_neg(source, node, tmp_prev_node, tmp_acc_w)
                    # print("path_no_neg: source 222", source, ", destination = ", destination, " prev_node = ", prev_nodes)

                    if len(prev_edges) > 0:
                        prev_edges.append([node, destination, self.edgeTable[node][destination]])
                        ret = prev_edges

        return ret

    def path_neg(self, source: int, destination: int, prev_nodes: List[int], accumulatedWeight: int) -> List[List[int]]:
        connected_nodes = []
        ret = []
        target = self.target

        # print("Neg: source ", source, ", destination = ", destination, " prev_node = ", prev_nodes, "accumulated weight = ", accumulatedWeight)

        for i in range(self.n):
            if self.edgeTable[destination][i] != 0 and self.edgeTable[destination][i] < target:
                connected_nodes.append(i)

        # print("Neg: connected_nodes: ", connected_nodes)

        for node in connected_nodes:
            if node not in prev_nodes:
                if node == source:
                    if self.edgeTable[node][destination] + accumulatedWeight < target:
                        ret = [[node, destination, self.edgeTable[node][destination]]]
                        break
                else:
                    tmp_prev_nodes = prev_nodes.copy()
                    tmp_prev_nodes.append(destination)
                    tmp_acc_w = accumulatedWeight
                    tmp_acc_w += self.edgeTable[node][destination]
                    prev_edges = self.path_neg(source, node, tmp_prev_nodes, tmp_acc_w)
                    if len(prev_edges) > 0:
                        prev_edges.append([node, destination, self.edgeTable[node][destination]])
                        ret = prev_edges
                        break

        print("Neg:" , ret)
        return ret

    def isInSet(self, edge:List[int], edgeSet:List[List[int]]) -> (bool, int):
        present = False
        idx = 0
        ret_idx = -1
        for edge_ in edgeSet:
            if (edge_[0] == edge[0] and edge_[1] == edge[1]) or (edge_[1] == edge[0] and edge_[0] == edge[1]):
                present = True
                ret_idx = idx 
                break
            idx += 1
        return present, ret_idx

    def modifiedGraphEdges(self, n: int, edges: List[List[int]], source: int, destination: int, target: int) -> List[List[int]]:
        
        
        self.edgeTable = [[0 for _ in range(n)] for _ in range(n)]
        self.edgeState = [[0 for _ in range(n)] for _ in range(n)]

        self.n = n
        self.target = target
        # print(edges)

        # fill the edgeTable in the class
        for i in range(len(edges)):
            self.edgeTable[edges[i][0]][edges[i][1]] = edges[i][2]
            self.edgeTable[edges[i][1]][edges[i][0]] = edges[i][2]
            if edges[i][2] == -1:
                self.edgeState[edges[i][0]][edges[i][1]] = -1
                self.edgeState[edges[i][1]][edges[i][0]] = -1
                print("changing the sate for ", edges[i][0], edges[i][1], "to : ",  self.edgeTable[edges[i][1]][edges[i][0]])

        
        # determine whether there is a path from source to destination that contains only positive edges
        positive_edges = self.path_no_neg(source, destination, [], 0)

        print("positive_edges = ", positive_edges)
        if len(positive_edges):
            return []

        solution_edges = self.path_neg(source, destination, [], 0)
        
        print("solution_edges:" ,solution_edges)
        # make all negative edge unusable
        for edge in edges:
            presence, idx = self.isInSet(edge, solution_edges)
            if  (presence == False) and edge[2] == -1:
                edge[2] = 9999
                self.edgeTable[edge[0]][edge[1]] = edge[2]
                self.edgeTable[edge[1]][edge[0]] = edge[2]
        
        acc_w = 0
        non_neg = 0
        for edge in solution_edges:
            if edge[2] > 0:
                acc_w += edge[2]
                non_neg += 1
        
        fill_w = target - acc_w
        num_neg_edge = len(solution_edges) - non_neg
        iter_var = 0
        for edge in solution_edges:
            if edge[2] < 0:
                if iter_var != len(solution_edges) - 1: 
                    edge[2] = int(fill_w / num_neg_edge)
                    acc_w += edge[2]
                else:
                    edge[2] = target - acc_w

            iter_var += 1
        
        
        for edge in solution_edges:
            presence, idx = self.isInSet(edge, edges)
            if (presence):
                edges[idx][2] = edge[2]
                self.edgeTable[edge[1]][edge[0]] = edge[2]
                self.edgeTable[edge[0]][edge[1]] = edge[2]

        # print("solution_edges:", solution_edges)
        # print("all edges: ", edges)

        # verification, we run path_no_neg
        positive_edges = self.path_no_neg(source, destination, [], 0)
        acc_w = 0
        for i in range(len(positive_edges)):
            acc_w += positive_edges[i][2]

        print("verif, second path_no_neg run has edges:", positive_edges)

        while len(positive_edges) > 0:
            for edge in positive_edges:
                if self.edgeState[edge[0]][edge[1]] == -1:
                    print("modifying!!!")
                    presence,idx = self.isInSet(edge, edges)
                    if presence:
                        edges[idx][2] += target - acc_w
                        self.edgeTable[ edges[idx][0]][edges[idx][1]] =  edges[idx][2]
                        self.edgeTable[ edges[idx][1]][edges[idx][0]] =  edges[idx][2]
                        break
            print("azehazeeh", edges)
            # time.sleep(2)
            positive_edges = self.path_no_neg(source, destination, [], 0)

        return edges
            

s=Solution()
# print(s.modifiedGraphEdges(5,[[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], 0, 1,5))
# print(s.modifiedGraphEdges(3,[[0,1,-1],[0,2,5]], 0, 2,6))
# print(s.modifiedGraphEdges(4,[[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], 0, 2,6))
# print(s.modifiedGraphEdges(4, [[0,1,-1],[1,2,-1],[3,1,-1],[3,0,2],[0,2,5]], 2, 3, 8))
# print(s.modifiedGraphEdges(5, [[0,1,-1],[2,1,-1],[2,4,8],[3,4,10]], 0, 2, 9))
# print(s.modifiedGraphEdges(5,[[3,0,-1],[2,1,-1],[4,1,9],[3,4,-1],[4,0,6],[2,3,5],[4,2,8],[3,1,7],[1,0,6],[0,2,9]], 4, 1, 10))
# print(s.modifiedGraphEdges(5,[[1,4,-1],[0,2,-1],[0,3,9],[4,0,-1],[1,0,10],[4,2,10]], 1, 2, 9))
# print(s.modifiedGraphEdges(4, [[3,0,-1],[1,3,-1],[3,2,10],[0,2,2]], 0, 1, 13))
# print(s.modifiedGraphEdges(5,[[1,4,1],[2,4,-1],[3,0,2],[0,4,-1],[1,3,10],[1,0,10]], 0, 2 , 15))
# print(s.modifiedGraphEdges(4,[[3,0,-1],[1,2,-1],[2,3,-1],[1,3,9],[2,0,5]],0,1,7))
# print(s.modifiedGraphEdges(5, [[3,0,-1],[2,1,-1],[4,1,9],[3,4,-1],[4,0,6],[2,3,5],[4,2,8],[3,1,7],[1,0,6],[0,2,9]],4,1,10))
# print(s.modifiedGraphEdges(5, [[0,1,-1],[2,1,-1],[2,4,8],[3,4,10]], 0, 2, 9))
# print(s.modifiedGraphEdges(5, [[0,2,5],[2,1,-1],[2,4,3],[3,4,5],[4,0,1],[0,3,-1],[2,3,-1]], 0, 1, 9))
print(s.modifiedGraphEdges(5,[[1,2,7],[0,1,10],[4,0,1],[3,4,10],[1,4,7],[1,3,4],[2,3,9999],[4,2,7],[0,2,0]], 0, 3, 11))