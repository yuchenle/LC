#include <unordered_map>
#include <vector>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:

    bool isConnected(int n, int source, int dest, unordered_map<int, vector<int>>& nb, unordered_map<int,int>& parsed) {
        assert(source>=0 && source < n);
        assert(dest>=0 && dest < n);
        // printf("isConnected, src = %d, dst = %d\n", source, dest);
        vector<int> connected = nb[source];
        for(int node : connected) {
            if (node == dest)
                return true;
        }
        parsed[source]++;
        for (int node : connected) {
            if (parsed[node])
                continue;
            if (isConnected(n, node, dest, nb, parsed))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination)
            return true;

        unordered_map<int, vector<int>> neighbors;
        unordered_map<int, int> parsed;
        for (auto edge : edges) {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        return isConnected(n, source, destination, neighbors, parsed);
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> input = {{0,1},{1,2},{2,0}};
    vector<vector<int>> input2 = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    vector<vector<int>> input3 = {{1,2},{2,3},{3,4}};
    cout << s.validPath(4, input3, 2, 3) << endl;
    // cout << s.validPath(6, input2, 0, 5) << endl;
    return 0;
}